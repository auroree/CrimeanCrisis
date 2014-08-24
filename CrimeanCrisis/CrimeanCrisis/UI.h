#pragma once

#include <Windows.h>
#include <GL/GL.h>
#include <GL/glut.h>
#include <string.h>
#include "Types.h"

class GameUI
{
private:
	Color background;
	Color font;

	char menu[10][255];

	float pos;

public:
	int width, height;

	GameUI();
	GameUI(int w, int h);
	~GameUI();
	void init();
	void drawUI();

	void drawText(int x, int y, Color font, char text[]);
};