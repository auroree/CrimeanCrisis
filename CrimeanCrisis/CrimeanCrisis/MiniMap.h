#pragma once

#include <Windows.h>
#include "lib/GL/GL.h"
#include "lib/GL/glut.h"
#include "Types.h"

class MiniMap
{
private:
	Color mapBg;
	int size;

public:
	MiniMap();
	MiniMap(Color mapBg, int size);
	void drawMap();
	void translateToMap(Vector point, float temp[]);
};