#pragma once

#include <list>
#include <time.h>
#include "Types.h"
#include "Particle.h"
#include "ImageUtil.h"

class ExplosionParticle
{
private:
	Vector speed;

public:
	Vector pos;
	int timeToLive;

	ExplosionParticle(float x, float y, float z, float xSpd, float ySpd, float zSpd, int timeToLive);
	~ExplosionParticle();

	void Move();
};

class Flame
{
	int explosionCounter;
	int speed;
	int timeToLive;
	int particlesEmittedPerTick;
	Vector source;
	Image * flameImg;
	Image * explosionImg;
	std::list<Particle> flameParticles;
	std::list<ExplosionParticle> explosionParticles;

public:
	Flame(float x, float y, float z);
	~Flame();
	void emitParticles();
	void affectParticles();
	void displayFlame();

private:
	void emitExplosion();
	void emitFlame();
};