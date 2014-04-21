#include "GameServer.h"


GameServer::GameServer()
{
}


GameServer::~GameServer()
{
	//WSACleanup();
	//closesocket(mainSocket);
}


int GameServer::Start()	//to bêdzie jedyna uruchomiona funkcja serwera
{
	//inicjalizacja
	WSADATA wsaData;		
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (result != NO_ERROR)
		printf("Initialization error.\n");	
	//koniec inicjalizacji
	
	//utworzenie gniazda
	mainSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);		
	if (mainSocket == INVALID_SOCKET)
	{
		printf("Error creating socket: %ld ---> SERVER --->\n", WSAGetLastError());
		WSACleanup();
		return 1;
	}																	
	//koniec tworzenia gniazda

	//ustalenie IP
	sockaddr_in service;
	memset(&service, 0, sizeof(service));
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr("127.0.0.1");
	service.sin_port = htons(27015);
	//koniec ustalania IP

	if (bind(mainSocket, (SOCKADDR *)& service, sizeof(service)) == SOCKET_ERROR)
	{
		printf("bind() failed.\n");
		closesocket(mainSocket);
		return 1;
	}

	if (listen(mainSocket, 1) == SOCKET_ERROR)
		printf("Error listening on socket.\n");

	SOCKET acceptSocket = SOCKET_ERROR;
	printf("Waiting for a client to connect...\n");


	while (acceptSocket == SOCKET_ERROR)
	{
		acceptSocket = accept(mainSocket, NULL, NULL);
	}

	printf("Client connected. ---> SERVER\n");
	mainSocket = acceptSocket;

	//odbieranie	
	Listen();

	return 0;
	//zamkniêcie serwera
}


void GameServer::Listen()
{
	int bytesRecv = SOCKET_ERROR;
	char* recvbuf = "";

	while (true)
	{
		bytesRecv = recv(mainSocket, recvbuf, 32, 0);	
		// tu gdzieœ przerabianie informacji
		printf("Bytes received: %ld ---> SERVER\n", bytesRecv);
		printf("Received text: %s ---> SERVER\n", recvbuf);
		if (strcmp(recvbuf, "MAHNA MAHNA"))
		{
			Send("tututututu");	//bêdzie mo¿e odsy³ana odpowiedŸ?
		}
	}
}


void GameServer::Send(char* data)
{
	int bytesSent;		
	char* sendbuf = data;

	bytesSent = send(mainSocket, sendbuf, strlen(sendbuf), 0);
	printf("Bytes sent: %ld ---> SERVER\n", bytesSent);
}