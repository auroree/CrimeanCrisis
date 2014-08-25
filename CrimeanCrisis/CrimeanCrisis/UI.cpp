#include "UI.h"

GameUI::GameUI() 
{
	width = 800;
	height = 640;
	init();
}

GameUI::GameUI(int w, int h)
{
	width = w;
	height = h;
	init();
}

GameUI::~GameUI()
{
}

void GameUI::init()
{
	background = { 0.9f, 0.9f, 1, 0.8f };
	font = { 0.1f, 0.1f, 0.1f, 1 };

	strcpy_s(menu[0], "Menu 1");
	strcpy_s(menu[1], "Menu 2");

	pos = 0.1;
}

void GameUI::drawUI()
{
	glDisable(GL_DEPTH_TEST);
	// backgroud
	glColor4f(background.r, background.g, background.b, background.a);
	glBegin(GL_QUADS);
	glVertex3f(0, 0, 0);
	glVertex3f(width, 0, 0);
	glVertex3f(width, 150, 0);
	glVertex3f(0, 150, 0);
	glEnd();

	// menu
	glDisable(GL_BLEND);

	glColor4fv(font);
	drawText(20, 40, font, menu[0]);
	drawText(20, 100, font, menu[1]);

	glEnable(GL_BLEND);

	//glFlush();
	glEnable(GL_DEPTH_TEST);
}

void GameUI::drawText(int x, int y, Color font, char text[])
{
	// po³o¿enie napisu
	glRasterPos2i(x, y);

	// wyœwietlenie napisu
	int len = strlen(text);
	for (int i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
	}
}