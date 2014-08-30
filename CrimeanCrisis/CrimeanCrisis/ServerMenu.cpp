#include "ServerMenu.h"

ServerMenu::ServerMenu()
{
	init();
}

ServerMenu::~ServerMenu()
{
	for (int i = 0; i < BUTTONS_COUNT; i++)
	{
		delete buttons[i];
	}
}

void ServerMenu::drawServerMenu()
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

void ServerMenu::init()
{
	Color font(0, 0, 0, 1);
	Color background(0.15f, 0.3f, 0.6f, 1);
	ButtonStyle style = { 200, 50, font, background };

	buttons[0] = new Button("Select", NULL, 100, 100, style, ClickResult::SelectServer);
	buttons[1] = new Button("Back", NULL, 100, 40, style, ClickResult::Back);
}

ClickResult ServerMenu::whatIsClicked(int x, int y, ServerProperties * serverProperties)
{
	for (int i = 0; i < BUTTONS_COUNT; i++)
	{
		if (buttons[i]->isClicked(x, y))
		{
			return buttons[i]->getButtonType();
		}
	}

	// TODO: server info, jeszcze nie wiem

	return ClickResult::NoneResult;
}