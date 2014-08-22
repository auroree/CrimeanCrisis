#pragma once

#include <cstdio>
#include <cstdlib>
#include <WinSock2.h>

class Klient
{
public:
	Klient();
	~Klient();
	int Start();

private:
	SOCKET mainSocket;
};

