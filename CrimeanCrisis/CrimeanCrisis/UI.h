#pragma once

#include <Windows.h>
#include <GL/GL.h>
#include <GL/glut.h>
#include <string.h>
#include "Types.h"
#include "Button.h"
#include "MiniMap.h"
#include "ClickResult.h"

enum ActiveTab
{
	BuildingTab,
	TrainingTab
};

#define TAB_COUNT 2
#define BUILDING_COUNT 2
#define TRAINING_COUNT 2

class GameUI
{
private:
	Color background;
	Color font;
	ActiveTab activeTab;

	MiniMap * map;
	Button * tabButtons[TAB_COUNT];
	Button * buildingButtons[BUILDING_COUNT];
	Button * trainingButtons[TRAINING_COUNT];

public:
	int width, height;

	GameUI();
	GameUI(int w, int h);
	~GameUI();
	void init();
	void drawUI();
	ClickResult whatIsClicked(int x, int y);

private:
	void drawText(int x, int y, Color font, char text[]);
	ClickResult isPanelClicked(int x, int y);
};