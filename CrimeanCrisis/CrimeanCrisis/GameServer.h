#pragma once

#include <cstdio>
#include <cstdlib>
#include <WinSock2.h>

class GameServer
{
public:
	GameServer();
	~GameServer();
	int Start();
	void Listen();
	void Send();
};

