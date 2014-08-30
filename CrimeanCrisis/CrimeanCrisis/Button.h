#pragma once

#include <Windows.h>
#include <GL/GL.h>
#include <GL/glut.h>
#include <string.h>
#include "Types.h"
#include "ClickResult.h"
#include "ImageUtil.h"

struct ButtonStyle
{
	int width;
	int height;
	Color font;
	Color background;
};

class Button
{
private:
	int locationX, locationY;
	ButtonStyle style;
	char text[100];
	Image * image;
	ClickResult buttonType;

public:
	Button(char text[], Image * image, int locationX, int locationY, ButtonStyle style, ClickResult buttonType);
	~Button();

	void drawButton();
	ClickResult getButtonType();
	char * getText();
	void setStyle(ButtonStyle style);
	bool isClicked(int x, int y);

private:
	void drawText();
	void drawImage();
};