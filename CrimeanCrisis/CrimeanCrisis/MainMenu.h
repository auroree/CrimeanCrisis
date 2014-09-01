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