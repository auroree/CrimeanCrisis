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
	for (int i = 0; i < TAB_COUNT; i++)
	{
		delete tabButtons[i];
	}
	for (int i = 0; i < TRAINING_COUNT; i++)
	{
		delete trainingButtons[i];
	}
	for (int i = 0; i < BUILDING_COUNT; i++)
	{
		delete buildingButtons[i];
	}
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
	// nie wiem czemu nie dziala z wzgledna sciezka
	Image * building = ImageUtil::loadBmp("D:\\Dropbox\\GitHub\\CrimeanCrisis\\CrimeanCrisis\\Debug\\ui\\building.bmp");
	Image * training = ImageUtil::loadBmp("D:\\Dropbox\\GitHub\\CrimeanCrisis\\CrimeanCrisis\\Debug\\ui\\training.bmp");
	Image * building1 = ImageUtil::loadBmp("D:\\Dropbox\\GitHub\\CrimeanCrisis\\CrimeanCrisis\\Debug\\ui\\building1.bmp");
	Image * training1 = ImageUtil::loadBmp("D:\\Dropbox\\GitHub\\CrimeanCrisis\\CrimeanCrisis\\Debug\\ui\\training1.bmp");
	Image * building2 = ImageUtil::loadBmp("D:\\Dropbox\\GitHub\\CrimeanCrisis\\CrimeanCrisis\\Debug\\ui\\building2.bmp");
	Image * training2 = ImageUtil::loadBmp("D:\\Dropbox\\GitHub\\CrimeanCrisis\\CrimeanCrisis\\Debug\\ui\\training2.bmp");

	// buttons
	tabButtons[0] = new Button("B", building, 200, PANEL_1ST_ROW, PANEL_BUTTON_SIZE, PANEL_BUTTON_SIZE, ClickResult::Building);
	tabButtons[1] = new Button("T", training, 200, PANEL_2ND_ROW, PANEL_BUTTON_SIZE, PANEL_BUTTON_SIZE, ClickResult::Training);

	buildingButtons[0] = new Button("B1", building1, 300, PANEL_1ST_ROW, PANEL_BUTTON_SIZE, PANEL_BUTTON_SIZE, ClickResult::Building1);
	buildingButtons[1] = new Button("B2", building2, 300, PANEL_2ND_ROW, PANEL_BUTTON_SIZE, PANEL_BUTTON_SIZE, ClickResult::Building2);

	trainingButtons[0] = new Button("T1", training1, 300, PANEL_1ST_ROW, PANEL_BUTTON_SIZE, PANEL_BUTTON_SIZE, ClickResult::Troop1);
	trainingButtons[1] = new Button("T2", training2, 300, PANEL_2ND_ROW, PANEL_BUTTON_SIZE, PANEL_BUTTON_SIZE, ClickResult::Troop2);
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

	case ActiveTab::TrainingTab:
		for (int i = 0; i < TRAINING_COUNT; i++)
		{
			trainingButtons[i]->drawButton();
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
	for (int i = 0; i < 2; i++)
	{
		if (tabButtons[i]->isClicked(x, y))
		{
			result = tabButtons[i]->getButtonType();
			switch (result)
			{
			case Building:
				activeTab = ActiveTab::BuildingTab;
				return result;
			case Training:
				activeTab = ActiveTab::TrainingTab;
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

	case ActiveTab::TrainingTab:
		for (int i = 0; i < TRAINING_COUNT; i++)
		{
			if (trainingButtons[i]->isClicked(x, y))
			{
				return trainingButtons[i]->getButtonType();
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
	if (x < width && y < height)
	{
		return Panel;
	}

	return NoneResult;
}



