#pragma once

#include <Windows.h>
#include <GL/GL.h>
#include <GL/glut.h>
#include <string.h>
#include "Types.h"
#include "ClickResult.h"

class Button
{
private:
	int locationX, locationY, width, height;
	char text[100];
	char imagePath[256];
	Color background;
	Color font;
	ClickResult buttonType;

public:
	Button(char text[], char imagePath[], int locationX, int locationY, int width, int height, ClickResult buttonType);
	void drawButton();
	ClickResult getButtonType();
	bool isClicked(int x, int y);

private:
	void defaultColors();
	void drawText();
};