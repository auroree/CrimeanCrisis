#include "Button.h"

Button::Button(char text[], Image * image, int locationX, int locationY, ButtonStyle style, ClickResult buttonType)
{
	strcpy_s(this->text, text);
	this->locationX = locationX;
	this->locationY = locationY; 
	this->style = style;
	this->buttonType = buttonType;
	this->image = image;
	if (image != NULL)
	{
		style.width = image->sizeX;
		style.height = image->sizeY;
	}
}

Button::~Button()
{
	free(this->image->data);
	free(this->image);
}

void Button::drawButton()
{
	if (image == NULL)
	{
		drawText();
	}
	else
	{
		drawImage();
	}
}

ClickResult Button::getButtonType()
{
	return buttonType;
}

char * Button::getText()
{
	return this->text;
}

void Button::setStyle(ButtonStyle style)
{
	this->style = style;
}

bool Button::isClicked(int x, int y)
{
	bool checkX = locationX <= x && x <= locationX + style.width;
	bool checkY = locationY <= y && y <= locationY + style.height;
	return checkX && checkY;
}

void Button::drawText()
{
	// bg
	glColor4fv(style.background);
	glBegin(GL_QUADS);
	glVertex2f(locationX, locationY);
	glVertex2f(locationX + style.width, locationY);
	glVertex2f(locationX + style.width, locationY + style.height);
	glVertex2f(locationX, locationY + style.height);
	glEnd();

	glDisable(GL_BLEND);
	glColor4fv(style.font);
	glRasterPos2i(locationX + 2, locationY + 5);

	int len = strlen(text);
	for (int i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
	}
	glEnable(GL_BLEND);
}

void Button::drawImage()
{
	glRasterPos2i(locationX, locationY);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glDrawPixels(image->sizeX, image->sizeY, GL_RGB, GL_UNSIGNED_BYTE, image->data);
}



