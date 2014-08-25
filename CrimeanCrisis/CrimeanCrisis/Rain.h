#pragma once

#include <list>
#include <time.h>
#include "Types.h"

class RainParticle
{
public:
	Vector pos;

	RainParticle(float x, float y, float z);
	~RainParticle();
};

class Rain
{
private:
	float density;
	float speed;
	int area;
	std::list<RainParticle> particles;

public:
	Rain();
	Rain(float density, float speed);
	~Rain() {}
	void emitParticles();
	void affectParticles();
	void displayRain();
};

