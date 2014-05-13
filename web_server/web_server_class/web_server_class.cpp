#include "web_server_class.h"
#include "precomp.h"


#define INITIALIZE_HTTP_RESPONSE( resp, status, reason )    \
	do                                                      \
	{                                                       \
	RtlZeroMemory( (resp), sizeof(*(resp)) );           \
	(resp)->StatusCode = (status);                      \
	(resp)->pReason = (reason);                         \
	(resp)->ReasonLength = (USHORT) strlen(reason);     \
	} while (FALSE)

#define ADD_KNOWN_HEADER(Response, HeaderId, RawValue)               \
	do                                                               \
	{                                                                \
	(Response).Headers.KnownHeaders[(HeaderId)].pRawValue =      \
	(RawValue);\
	(Response).Headers.KnownHeaders[(HeaderId)].RawValueLength = \
	(USHORT) strlen(RawValue);                               \
	} while(FALSE)

#define ALLOC_MEM(cb) HeapAlloc(GetProcessHeap(), 0, (cb))

#define FREE_MEM(ptr) HeapFree(GetProcessHeap(), 0, (ptr))

	DWORD WebServer::DoReceiveRequests(	)
{
	ULONG              result;
	HTTP_REQUEST_ID    requestId;
	DWORD              bytesRead;
	PHTTP_REQUEST      pRequest;
	PCHAR              pRequestBuffer;
	ULONG              RequestBufferLength;

	// Allocate a 2 KB buffer. This size should work for most 
	// requests. The buffer size can be increased if required. Space
	// is also required for an HTTP_REQUEST structure.
	RequestBufferLength = sizeof(HTTP_REQUEST) + 2048;
	pRequestBuffer      = (PCHAR) ALLOC_MEM( RequestBufferLength );

	if (pRequestBuffer == NULL)
	{
		return ERROR_NOT_ENOUGH_MEMORY;
	}

	pRequest = (PHTTP_REQUEST)pRequestBuffer;

	// Wait for a new request. This is indicated by a NULL request ID.
	HTTP_SET_NULL_ID( &requestId );

	for(;;)
	{
		RtlZeroMemory(pRequest, RequestBufferLength);

		result = HttpReceiveHttpRequest(
			hReqQueue,          // Req Queue
			requestId,          // Req ID
			0,                  // Flags
			pRequest,           // HTTP request buffer
			RequestBufferLength,// req buffer length
			&bytesRead,         // bytes received
			NULL                // LPOVERLAPPED
			);
		
		if(NO_ERROR == result)
		{
			// verify GET request. Case not - return 'Not implemented msg'
			if (pRequest->Verb != HttpVerbGET)
			{
				wprintf(L"Got a unknown request for %ws \n", 
					pRequest->CookedUrl.pFullUrl);

				result = SendHttpResponse( 
					pRequest,
					503,
					"Not Implemented",
					NULL,
					"text\\html",
					0
					);
			}
			
			else 
			{
				wprintf(L"Got a GET request for %ws \n", 
					pRequest->CookedUrl.pFullUrl);
				
				PWSTR filename = nullptr;
				char * buffer = nullptr;				
				int buffer_size = 0;
				
				if(pRequest->CookedUrl.pQueryString != 0)
				{	
					filename = getPathFromUrl(pRequest->CookedUrl.pFullUrl, filename, std::wcslen(pRequest->CookedUrl.pQueryString));
					buffer = getFileContent(filename, buffer, buffer_size);
					buffer = replaceTagWithValue(pRequest->CookedUrl.pQueryString, buffer, buffer_size);
				}
				else
				{
					filename = getPathFromUrl(pRequest->CookedUrl.pFullUrl, filename);
					buffer = getFileContent(filename, buffer, buffer_size);
				}
								
				char * file_type = data_type(filename);
				result = SendHttpResponse( 
					pRequest, 
					200,
					"OK",
					buffer,
					file_type,
					buffer_size
					);
			}

			if(result != NO_ERROR)
			{
				break;
			}

			// Reset the Request ID to handle the next request.
			HTTP_SET_NULL_ID( &requestId );
		}

		else if(result == ERROR_MORE_DATA)
		{
			// The input buffer was too small to hold the request headers. Increase the buffer size and call the API again. 
			// When calling the API again, handle the request that failed by passing a RequestID.
			// This RequestID is read from the old buffer.
			requestId = pRequest->RequestId;

			// Free the old buffer and allocate a new buffer.
			RequestBufferLength = bytesRead;
			FREE_MEM( pRequestBuffer );
			pRequestBuffer = (PCHAR) ALLOC_MEM( RequestBufferLength );

			if (pRequestBuffer == NULL)
			{
				result = ERROR_NOT_ENOUGH_MEMORY;
				break;
			}
			pRequest = (PHTTP_REQUEST)pRequestBuffer;

		}
		else if(ERROR_CONNECTION_INVALID == result && 
			!HTTP_IS_NULL_ID(&requestId))
		{
			// The TCP connection was corrupted by the peer when
			// attempting to handle a request with more buffer.  Continue to the next request.

			HTTP_SET_NULL_ID( &requestId );
		}
		else
		{
			break;
		}
	}

	if(pRequestBuffer)
	{
		FREE_MEM( pRequestBuffer );
	}
	return result;
}

	DWORD WebServer::SendHttpResponse(
	IN PHTTP_REQUEST pRequest,
	IN USHORT        StatusCode,
	IN PSTR          pReason,
	IN PSTR          pEntityString,
	char *			 file_type,
	int				 buffer_size
	)
{
	HTTP_RESPONSE   response;
	HTTP_DATA_CHUNK dataChunk;
	DWORD           result;
	DWORD           bytesSent;

	// Initialize the HTTP response structure.
	//
	INITIALIZE_HTTP_RESPONSE(&response, StatusCode, pReason);
	
	// Add a known header.
	ADD_KNOWN_HEADER(response, HttpHeaderContentType, file_type);

	if(pEntityString)
	{
		// Add an entity chunk.
		//
		dataChunk.DataChunkType           = HttpDataChunkFromMemory;
		dataChunk.FromMemory.pBuffer      = pEntityString;
		dataChunk.FromMemory.BufferLength = buffer_size;

		response.EntityChunkCount         = 1;
		response.pEntityChunks            = &dataChunk;
	}

	result = HttpSendHttpResponse(
		hReqQueue,           // ReqQueueHandle
		pRequest->RequestId, // Request ID
		0,                   // Flags
		&response,           // HTTP response
		NULL,                // pReserved1
		&bytesSent,          // bytes sent  (OPTIONAL)
		NULL,                // pReserved2  (must be NULL)
		0,                   // Reserved3   (must be 0)
		NULL,                // LPOVERLAPPED(OPTIONAL)
		NULL                 // pReserved4  (must be NULL)
		); 

	if(result != NO_ERROR)
	{
		wprintf(L"HttpSendHttpResponse failed with %lu \n", result);
	}

	return result;
}

WebServer::WebServer()
{
	ULONG           retCode;
    hReqQueue      = NULL;
	HTTPAPI_VERSION HttpApiVersion = HTTPAPI_VERSION_1;
	sources_path = 0;

	// Initialize HTTP Server APIs
	//
	retCode = HttpInitialize( 
		HttpApiVersion,
		HTTP_INITIALIZE_SERVER,    // Flags
		NULL                       // Reserved
		);

	if (retCode != NO_ERROR)
	{
		std::cout << "HttpInitialize failed with " << retCode << std::endl;
		this->~WebServer();
	}
	// Create a Request Queue Handle
	//
	retCode = HttpCreateHttpHandle(
		&hReqQueue,        // Req Queue
		0                  // Reserved
		);

	if (retCode != NO_ERROR)
	{    
		std::cout << "HttpCreateHttpHandle failed with" << retCode << "\n";
		this->~WebServer();
	}	
}

WebServer::~WebServer()
{
	if(hReqQueue)
	{
		CloseHandle(hReqQueue);
	}

	// Call HttpTerminate.
	//
	HttpTerminate(HTTP_INITIALIZE_SERVER, NULL);
}

bool WebServer::ServerAddUrl(PCWSTR url)
{
	wprintf(L"listening for requests on the following url: %s\n", url);

	int retCode = 1;
	retCode = HttpAddUrl(hReqQueue, url, NULL);

		if (retCode != NO_ERROR)
		{
			wprintf(L"HttpAddUrl failed with %lu %s \n", retCode);
			return false;
		} 
		else
		{
			wprintf(L"listening for requests on the following url: %s\n", url);
			return true;
		}
}

char * replaceTagWithValue(PCWSTR qr_string, char* buffer, int & buffer_size)
{
	const int subQrLen = std::wcslen(qr_string);
	char * tag = new char[subQrLen +  2], *value = new char[subQrLen];
	tag[0] = '%';
	int i = 1;
	while (qr_string[i] != '=' && i < subQrLen)
	{
		wctomb(&tag[i], qr_string[i]);
		i++;
		tag[i] = '%';
		tag[i + 1] = 0;
	}
					
	i++;
	int j = 0;
	while( i < subQrLen )
	{			
		wctomb(&value[j], qr_string[i]);
		i++; j++;
		value[j] = 0;
	}
					
	int tag_size = strlen(tag);
	wprintf(L"I am in replace function. Buffer size %i\n", buffer_size);

	for ( int i = 0; i < buffer_size; i++)
		if ((buffer[i]) == tag[0])
		{
			if(!strncmp(&buffer[i], tag, tag_size))
			{
				strncpy(&buffer[i], value, strlen(value));
				if(strlen(value) < tag_size)
				{
					int j = strlen(value);
					strcpy(&buffer[i + j],&buffer[i+tag_size]);
					buffer_size -= (strlen(tag) - strlen(value));
				}
			}
		}
		delete [] tag;
		delete [] value;

		return buffer;
}

bool WebServer::AddSourcesPath(PWSTR path)
{
	DWORD ftyp = GetFileAttributesW(path);
	if (ftyp == INVALID_FILE_ATTRIBUTES)
	{
		wprintf(L"Error during path adding. Wrong path.\n");
		return false;  //something is wrong with your path!
	}

	if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
	{
		int path_len = wcslen(path);
		if ( sources_path != 0 )
		{
			delete [] sources_path;
		}
			sources_path = new WCHAR[path_len + 1];
			wcsncpy(sources_path, path, path_len);
			sources_path[path_len] = 0;
			wprintf(L"Path ssuccessfully updated.\n");
			return true;   // this is a directory!
	}
		else wprintf(L"Error during path adding. Wrong path - directory needed.\n");
	return false;    // this is not a directory!
}

PWSTR WebServer::getPathFromUrl(PCWSTR  Url, PWSTR path, int SubqrLen)
{
	delete [] path;

	int backslash_count = 0;
	int src_path_len = wcslen(sources_path);
	int query_len = SubqrLen;
	PCWSTR http_head = L"http://";
	
	int Url_len = std::wcslen(Url) - query_len, http_head_len = std::wcslen(http_head);

	// return nullptr in case not http request
	if( !std::wcsncmp(http_head, Url, http_head_len+1) )
	{
		std::cout << "Invalid requested url";
		return nullptr;
	}

	else
	{
		int path_position = http_head_len;
		
		while ( Url[path_position] != '/' && path_position < Url_len)
				path_position++;
		path_position++;
		//find the number of '\' after host adress, which need to be extended by aditional '\' symbol
		for( int i = path_position; i < Url_len; i++)
			if (Url[i] == '/')
				backslash_count++;

		
		path = new WCHAR[src_path_len + Url_len - path_position + backslash_count];

		for(int i = src_path_len, j = path_position; i < Url_len - path_position, j < Url_len ; i++, j++)
		{
			if (Url[j] == '/')
			{
				path[i] = '\\'; 
				path[++i] = '\\';
			}
			else path[i] = Url[j];
		}
		std::wcsncpy(path, sources_path, src_path_len);
		path[src_path_len + Url_len -  path_position + backslash_count] = 0;
		wprintf(L"Path to file is %s\n", path);
		return path;
	}
}

char * getFileContent(PWSTR filename, char * buffer, int & buffer_size)
{
	std::ifstream requested_file;
	std::wstring file_path(filename); 
	requested_file.open(file_path, std::ifstream::binary);
	
	if(requested_file.is_open())
		wprintf(L"file is opened successfully \n");

	else 
	{
		wprintf(L"Cannot open requested file. Page not found.\n");
		file_path = L"G:\\web_server\\html\\page_not_found.html"; 
		
		requested_file.clear();
		requested_file.open(file_path, std::ifstream::binary);
	}
	std::filebuf* pbuf = requested_file.rdbuf();
	
	// get file size using buffer's members
	std::size_t size = pbuf->pubseekoff (0, requested_file.end, requested_file.in);
				pbuf->pubseekpos (0, requested_file.in);

	// allocate memory to contain file data
	delete [] buffer;
	buffer_size = size + 2;
	buffer = new char[buffer_size];
	buffer[size] = '\r';
	buffer[size + 1] = '\n';

	// get file data
	pbuf->sgetn (buffer,size);
	requested_file.close();

	return buffer;
}

char * data_type(PCWSTR filename)
{
	PCWSTR file_extension;
	int err_read_ptr = 0x00000000;
	file_extension = std::wcsstr(filename,L".");
	if(file_extension == (void *)err_read_ptr)
		file_extension = filename;
	char file_type[20];
	if( !wcscmp(file_extension,L".html") )
		strcpy(file_type,"text/html");
	else if( !wcscmp(file_extension,L".css") )
		strcpy(file_type, "text/css");
	else if ( !wcscmp(file_extension,L".jpeg") )
		strcpy(file_type, "image/jpeg");
	else strcpy(file_type, "text/html");
	return file_type;
}