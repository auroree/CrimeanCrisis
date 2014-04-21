#include "Klient.h"
#include <thread>

Klient::Klient()
{
}


Klient::~Klient()
{
	//WSACleanup();
	//closesocket(mainSocket);
}


int Klient::Start()
{
	
	//inicjalizacja
	WSADATA wsaData;
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (result != NO_ERROR)
		printf("Initialization error.\n");
	//koniec inicjalizacji

	//utworzenie gniazda
	SOCKET mainSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (mainSocket == INVALID_SOCKET)
	{
		printf("Error creating socket: %ld ---> KLIENT --->\n", WSAGetLastError());
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

	if (connect(mainSocket, (SOCKADDR *)& service, sizeof(service)) == SOCKET_ERROR)
	{
		printf("Failed to connect. ---> KLIENT\n");
		WSACleanup();
		return 1;
	}

	int bytesSent;
	int bytesRecv = SOCKET_ERROR;
	char sendbuf[32] = "Client says hello!";
	char recvbuf[32] = "";

	bytesSent = send(mainSocket, sendbuf, strlen(sendbuf), 0);
	printf("Bytes sent: %ld ---> KLIENT\n", bytesSent);

	while (bytesRecv == SOCKET_ERROR)
	{
		bytesRecv = recv(mainSocket, recvbuf, 32, 0);

		if (bytesRecv == 0 || bytesRecv == WSAECONNRESET)
		{
			printf("Connection closed. ---> KLIENT\n");
			break;
		}

		if (bytesRecv < 0)
			return 1;

		printf("Bytes received: %ld ---> KLIENT\n", bytesRecv);
		printf("Received text: %s ---> KLIENT\n", recvbuf);
	}

	system("pause");

	return 0;
}