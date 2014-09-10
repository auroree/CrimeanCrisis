#pragma once

#include "Types.h"

class Particle
{
public:
	Vector pos;
	int timeToLive;

	Particle(float x, float y, float z, int timeToLive);
	~Particle();
};