#include "Button.h"

Button::Button(char text[], char imagePath[], int locationX, int locationY, int width, int height, ClickResult buttonType)
{
	strcpy_s(this->text, text);
	strcpy_s(this->imagePath, imagePath);
	this->locationX = locationX;
	this->locationY = locationY;
	this->width = width;
	this->height = height;
	this->buttonType = buttonType;
	defaultColors();
}

void Button::drawButton()
{
	// bg
	glColor4fv(background);
	glBegin(GL_QUADS);
	glVertex2f(locationX, locationY);
	glVertex2f(locationX + width, locationY);
	glVertex2f(locationX + width, locationY + height);
	glVertex2f(locationX, locationY + height);
	glEnd();

	// text
	drawText();
	
}

ClickResult Button::getButtonType()
{
	return buttonType;
}

bool Button::isClicked(int x, int y)
{
	bool checkX = locationX <= x && x <= locationX + width;
	bool checkY = locationY <= y && y <= locationY + height;
	return checkX && checkY;
}

void Button::defaultColors()
{
	this->background = { 1, 1, 0, 0.8f };
	this->font = { 0, 0, 0, 1 };
}

void Button::drawText()
{
	glDisable(GL_BLEND);
	glColor4fv(font);
	glRasterPos2i(locationX + 20, locationY + 20);

	int len = strlen(text);
	for (int i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
	}
	glEnable(GL_BLEND);
}



