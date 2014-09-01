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

#define BUTTONS_COUNT 4

class MainMenu
{
private:
	Button * buttons[BUTTONS_COUNT];

public:
	MainMenu();
	~MainMenu();

	void drawMainMenu();
	ClickResult whatIsClicked(int x, int y);

private:
	void init();
};