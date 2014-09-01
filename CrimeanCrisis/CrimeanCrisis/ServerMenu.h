#pragma once

#include <Windows.h>
#include "lib/GL/GL.h"
#include "lib/GL/glut.h"
#include <string.h>
#include "Types.h"
#include "Button.h"
#include "MiniMap.h"
#include "ClickResult.h"
#include "ImageUtil.h"

#define SERVER_MENU_BUTTONS_COUNT 2
#define SERVER_MAX_COUNT 10

struct ServerProperties
{
	char host[100];
	char port[5];
};

class ServerMenu
{
private:
	ButtonStyle serverStyle;
	ButtonStyle markedServerStyle;
	Button * buttons[SERVER_MENU_BUTTONS_COUNT];
	Button * servers[SERVER_MAX_COUNT];
	int serverCount;
	int markedServer;
	int width, height;

public:
	ServerMenu(int w, int h);
	~ServerMenu();

	void drawServerMenu();
	void addServer(ServerProperties * serverProperties);
	ClickResult whatIsClicked(int x, int y, ServerProperties * serverProperties);

private:
	void init();
	void markServer(int id);
};