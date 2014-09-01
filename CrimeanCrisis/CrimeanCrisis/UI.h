#pragma once

#include <Windows.h>
#include "lib/GL/GL.h"
#include "lib/GL/glut.h"
#include <string.h>
#include "Types.h"
#include "Button.h"
#include "MiniMap.h"
#include "ClickResult.h"
#include "ImageUtil.h"

#define PANEL_BUTTON_SIZE 64
#define PANEL_1ST_ROW 80
#define PANEL_2ND_ROW 10
#define TAB_COUNT 2
#define BUILDING_COUNT 2
#define ARMY_COUNT 2

enum ActiveTab
{
	BuildingTab,
	ArmyTab
};

class GameUI
{
private:
	Color background;
	Color font;
	ActiveTab activeTab;

	MiniMap * map;
	Button * tabButtons[TAB_COUNT];
	Button * buildingButtons[BUILDING_COUNT];
	Button * armyButtons[ARMY_COUNT];

public:
	int width, height;

	GameUI(int w, int h);
	~GameUI();

	void initButtons();
	void drawUI();
	ClickResult whatIsClicked(int x, int y);

private:
	void init();
	void drawText(int x, int y, Color font, char text[]);
	ClickResult isPanelClicked(int x, int y);
};