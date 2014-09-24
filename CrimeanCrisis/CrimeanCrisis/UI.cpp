#include "UI.h"

GameUI::GameUI(int w, int h)
{
	width = w;
	height = h;
	init();
}

GameUI::~GameUI()
{
	for (int i = 0; i < TAB_COUNT; i++)
	{
		delete tabButtons[i];
	}
	for (int i = 0; i < ARMY_COUNT; i++)
	{
		delete armyButtons[i];
	}
	for (int i = 0; i < BUILDING_COUNT; i++)
	{
		delete buildingButtons[i];
	}

	delete map;
}

void GameUI::init()
{
	background = { 0.7f, 0.7f, 0.8f, 0.8f };
	font = { 0.1f, 0.1f, 0.1f, 1 };
	activeTab = ActiveTab::BuildingTab;

	map = new MiniMap();
	initButtons();
}

void GameUI::initButtons()
{
	// load button images
	Image * building = ImageUtil::loadBmp("..\\Debug\\ui\\building.bmp");
	Image * army = ImageUtil::loadBmp("..\\Debug\\ui\\army.bmp");
	Image * building1 = ImageUtil::loadBmp("..\\Debug\\ui\\building1.bmp");
	Image * army1 = ImageUtil::loadBmp("..\\Debug\\ui\\army1.bmp");
	Image * building2 = ImageUtil::loadBmp("..\\Debug\\ui\\building2.bmp");
	Image * army2 = ImageUtil::loadBmp("..\\Debug\\ui\\army2.bmp");

	// buttons
	Color font(0, 0, 0, 1);
	Color background(0.15f, 0.3f, 0.6f, 0.8f);
	ButtonStyle style = { PANEL_BUTTON_SIZE, PANEL_BUTTON_SIZE, font, background };

	tabButtons[0] = new Button("Buildings", building, 200, PANEL_1ST_ROW, style, ClickResult::Building);
	tabButtons[1] = new Button("Army", army, 200, PANEL_2ND_ROW, style, ClickResult::Army);

	buildingButtons[0] = new Button("Building1", building1, 300, PANEL_1ST_ROW, style, ClickResult::Building1);
	buildingButtons[1] = new Button("Building12", building2, 300, PANEL_2ND_ROW, style, ClickResult::Building2);

	armyButtons[0] = new Button("Troop1", army1, 300, PANEL_1ST_ROW, style, ClickResult::Troop1);
	armyButtons[1] = new Button("Troop2", army2, 300, PANEL_2ND_ROW, style, ClickResult::Troop2);
}

void GameUI::drawUI()
{
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);

	// backgroud
	glColor4fv(background);
	glBegin(GL_QUADS);
	glVertex3f(0, 0, 0);
	glVertex3f(width, 0, 0);
	glVertex3f(width, 150, 0);
	glVertex3f(0, 150, 0);
	glEnd();

	// map
	map->drawMap();

	// buttons
	for (int i = 0; i < TAB_COUNT; i++)
	{
		tabButtons[i]->drawButton();
	}

	switch (activeTab)
	{
	case ActiveTab::BuildingTab:
		for (int i = 0; i < BUILDING_COUNT; i++)
		{
			buildingButtons[i]->drawButton();
		}
		break;

	case ActiveTab::ArmyTab:
		for (int i = 0; i < ARMY_COUNT; i++)
		{
			armyButtons[i]->drawButton();
		}
		break;
	}

	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
}

ClickResult GameUI::whatIsClicked(int x, int y)
{
	ClickResult result = isPanelClicked(x, y);
	if (result == NoneResult)
	{
		return NoneResult;
	}

	// tab buttons
	for (int i = 0; i < TAB_COUNT; i++)
	{
		if (tabButtons[i]->isClicked(x, y))
		{
			result = tabButtons[i]->getButtonType();
			switch (result)
			{
			case Building:
				activeTab = ActiveTab::BuildingTab;
				return result;
			case Army:
				activeTab = ActiveTab::ArmyTab;
				return result;
			}
		}
	}

	// tab content buttons
	switch (activeTab)
	{
	case ActiveTab::BuildingTab:
		for (int i = 0; i < BUILDING_COUNT; i++)
		{
			if (buildingButtons[i]->isClicked(x, y))
			{
				return buildingButtons[i]->getButtonType();
			}
		}
		break;

	case ActiveTab::ArmyTab:
		for (int i = 0; i < ARMY_COUNT; i++)
		{
			if (armyButtons[i]->isClicked(x, y))
			{
				return armyButtons[i]->getButtonType();
			}
		}
		break;
	}

	return result;
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

ClickResult GameUI::isPanelClicked(int x, int y)
{
	if (x < width && y < 150)
	{
		return Panel;
	}

	return NoneResult;
}



