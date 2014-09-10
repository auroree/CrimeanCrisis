#include "Particle.h"

Particle::Particle(float x, float y, float z, int timeToLive)
{
	pos.x = x;
	pos.y = y;
	pos.z = z;
	this->timeToLive = timeToLive;
}

Particle::~Particle()
{
}