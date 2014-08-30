#include "ServerMenu.h"

ServerMenu::ServerMenu(int w, int h)
{
	width = w;
	height = h;
	init();
}

ServerMenu::~ServerMenu()
{
	for (int i = 0; i < SERVER_MENU_BUTTONS_COUNT; i++)
	{
		delete buttons[i];
	}
}

void ServerMenu::drawServerMenu()
{
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);

	for (int i = 0; i < SERVER_MENU_BUTTONS_COUNT; i++)
	{
		buttons[i]->drawButton();
	}

	for (int i = 0; i < serverCount; i++)
	{
		servers[i]->drawButton();
	}

	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
}

void ServerMenu::init()
{
	serverCount = 0;
	markedServer = -1;

	// buttons styles
	Color font(0, 0, 0, 1);

	Color backgroundServer(0.15f, 0.3f, 0.6f, 0.5f);
	serverStyle = { 200, 30, font, backgroundServer };

	Color backgroundMarked(0.9f, 0.9f, 0.9f, 0.5f);
	markedServerStyle = { 200, 30, font, backgroundMarked };

	Color background(0.15f, 0.3f, 0.6f, 1);
	ButtonStyle style = { 200, 50, font, background };

	buttons[0] = new Button("Select", NULL, 100, 100, style, ClickResult::SelectServer);
	buttons[1] = new Button("Back", NULL, 100, 40, style, ClickResult::Back);

	// TESTOWE
	ServerProperties * props1 = new ServerProperties;
	strcpy_s(props1->host, "localhost");
	strcpy_s(props1->port, "8089");

	this->addServer(props1);

	ServerProperties * props2 = new ServerProperties;
	strcpy_s(props2->host, "192.168.1.102");
	strcpy_s(props2->port, "8089");

	this->addServer(props2);
}

ClickResult ServerMenu::whatIsClicked(int x, int y, ServerProperties * serverProperties)
{
	for (int i = 0; i < SERVER_MENU_BUTTONS_COUNT; i++)
	{
		if (buttons[i]->isClicked(x, y))
		{
			ClickResult result = buttons[i]->getButtonType();

			if (result == ClickResult::SelectServer && markedServer >= 0)
			{
				char * text = servers[markedServer]->getText();
				char * port = strchr(text, ':');
				strncpy_s(serverProperties->host, text, port - text);
				strncpy_s(serverProperties->port, ++port, strlen(port));
			}
			return result;
		}
	}

	for (int i = 0; i < serverCount; i++)
	{
		if (servers[i]->isClicked(x, y))
		{
			this->markServer(i);
			return servers[i]->getButtonType();
		}
	}

	return ClickResult::NoneResult;
}

void ServerMenu::addServer(ServerProperties * serverProperties)
{
	char text[100];
	strcpy_s(text, "");
	strcat_s(text, serverProperties->host);
	strcat_s(text, ":");
	strcat_s(text, serverProperties->port);

	int locationY = height - 100 - (40 * serverCount);

	servers[serverCount] = new Button(text, NULL, 100, locationY, serverStyle, ClickResult::MarkServer);

	serverCount++;
}

void ServerMenu::markServer(int id)
{
	markedServer = id;
	for (int i = 0; i < serverCount; i++)
	{
		if (i != id)
		{
			servers[i]->setStyle(serverStyle);
		}
		else
		{
			servers[i]->setStyle(markedServerStyle);
		}
	}
}