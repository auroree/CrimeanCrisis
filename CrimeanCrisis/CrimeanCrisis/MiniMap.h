#pragma once

#include <Windows.h>
#include <GL/GL.h>
#include <GL/glut.h>
#include "Types.h"

class MiniMap
{
private:
	Color mapBg;
	int size;

public:
	MiniMap();
	MiniMap(Color mapBg, float size);
	void init();
	void drawMap();
	void translateToMap(Vector point, float temp[]);
};