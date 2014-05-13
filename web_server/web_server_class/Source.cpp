#include "web_server_class.h"

int main(int argc,  char* argv[])
{
	WebServer local_server;
	PCWSTR url = L"http://localhost:80/";
	local_server.ServerAddUrl(url);
	local_server.AddSourcesPath(L"G:\\\\web_server\\html\\");
	local_server.DoReceiveRequests();
}