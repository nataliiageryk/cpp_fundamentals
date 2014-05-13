#ifndef WEB_SERVER_CLASS_H_
#define WEB_SERVER_CLASS_H_

#include "precomp.h"
#include <iostream>
#include <sstream>
#include <fstream>

char * replaceTagWithValue(PCWSTR qr_str, char * buffer, int & buf_size);
char * getFileContent(PWSTR filename, char * buffer, int & buffer_size);
char * data_type(PCWSTR filename);

class WebServer
{
public:
	WebServer();
	~WebServer();
	DWORD DoReceiveRequests();
	DWORD SendHttpResponse(
	IN PHTTP_REQUEST pRequest,
	IN USHORT        StatusCode,
	IN PSTR          pReason,
	IN PSTR          pEntityString,
	char *			 file_type,
	int				 buffer_size
	);
	bool ServerAddUrl(PCWSTR url);
	bool AddSourcesPath(PWSTR path);
	PWSTR getPathFromUrl(PCWSTR  Url, PWSTR path, int SubqrLen = 0);

private:
	HANDLE          hReqQueue;
	HTTPAPI_VERSION HttpApiVersion;
	PWSTR sources_path;
};

#endif