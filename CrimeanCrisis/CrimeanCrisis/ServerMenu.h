#pragma once

#include <Windows.h>
#include <GL/GL.h>
#include <GL/glut.h>
#include <string.h>
#include "Types.h"
#include "Button.h"
#include "MiniMap.h"
#include "ClickResult.h"
#include "ImageUtil.h"
#include "ServerProperties.h"

#define BUTTONS_COUNT 2

struct ServerProperties
{
	char host[100];
	char port[5];
};

class ServerMenu
{
private:
	Button * buttons[BUTTONS_COUNT];

public:
	ServerMenu();
	~ServerMenu();

	void drawServerMenu();
	ClickResult whatIsClicked(int x, int y, ServerProperties * serverProperties);

private:
	void init();
};