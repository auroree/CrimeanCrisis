#include "MainMenu.h"

MainMenu::MainMenu()
{
	init();
}

MainMenu::~MainMenu()
{
	for (int i = 0; i < BUTTONS_COUNT; i++)
	{
		delete buttons[i];
	}
}

void MainMenu::drawMainMenu()
{
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);

	for (int i = 0; i < BUTTONS_COUNT; i++)
	{
		buttons[i]->drawButton();
	}

	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
}

void MainMenu::init()
{
	Color font(0, 0, 0, 1);
	Color background(0.15f, 0.3f, 0.6f, 1);
	ButtonStyle style = { 200, 50, font, background };

	Color backgroundInactive(0.7f, 0.7f, 0.7f, 1);
	ButtonStyle styleInavtive = { 200, 50, font, backgroundInactive };

	buttons[0] = new Button("Singleplayer", NULL, 100, 400, styleInavtive, ClickResult::NoneResult);
	buttons[1] = new Button("Multiplayer", NULL, 100, 340, style, ClickResult::Multiplayer);
	buttons[2] = new Button("Opcje", NULL, 100, 280, styleInavtive, ClickResult::NoneResult);
	buttons[3] = new Button("Wyjœcie", NULL, 100, 220, style, ClickResult::Quit);
}

ClickResult MainMenu::whatIsClicked(int x, int y)
{
	for (int i = 0; i < BUTTONS_COUNT; i++)
	{
		if (buttons[i]->isClicked(x, y))
		{
			return buttons[i]->getButtonType();
		}
	}

	return ClickResult::NoneResult;
}