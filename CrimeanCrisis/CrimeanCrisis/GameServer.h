#pragma once

#include <cstdio>
#include <cstdlib>
#include <WinSock2.h>
#include <thread>

class GameServer
{
public:
	GameServer();
	~GameServer();
	int Start();
	void Listen();
	void Send(char* data);

private:
	SOCKET mainSocket;
};

