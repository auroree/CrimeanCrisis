#include "MiniMap.h"

MiniMap::MiniMap()
{
	this->mapBg = { 0.2f, 0.6f, 0.2f, 1 };
	this->size = 120;
}

MiniMap::MiniMap(Color mapBg, int size)
{
	this->mapBg = mapBg;
	this->size = size;
}

void MiniMap::drawMap()
{
	glPushMatrix();
	glTranslatef(10, 90, 0);
	glRotatef(-45, 0, 0, 1);

	glColor4fv(mapBg);
	glBegin(GL_QUADS);
	glVertex2f(0, 0);
	glVertex2f(size, 0);
	glVertex2f(size, size);
	glVertex2f(0, size);
	glEnd();

	// TODO: wyswietlanie obiektow z gry, dodawanie, usuwanie
	// punkty 3d
	Vector x1 = { 0, 11, 0 };
	Vector x2 = { 100, 11, 0 };
	Vector z1 = { 0, 11, 0 };
	Vector z2 = { 0, 11, 100 };
	float temp[2];

	// linie pomocnicze
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	translateToMap(x1, temp);
	glVertex2fv(temp);
	translateToMap(x2, temp);
	glVertex2fv(temp);
	glEnd();

	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
	translateToMap(z1, temp);
	glVertex2fv(temp);
	translateToMap(z2, temp);
	glVertex2fv(temp);
	glEnd();

	glPopMatrix();
}

void MiniMap::translateToMap(Vector point, float temp[])
{
	float scale = size / 2;
	temp[0] = (point.x / 100) * scale + scale;
	temp[1] = (point.z / 100) * (-scale) + scale;
}