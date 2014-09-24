#include "Flame.h"

using namespace std;

ExplosionParticle::ExplosionParticle(float x, float y, float z, float xSpd, float ySpd, float zSpd, int timeToLive)
{
	pos.x = x;
	pos.y = y;
	pos.z = z;
	speed.x = xSpd;
	speed.y = ySpd;
	speed.z = zSpd;
	this->timeToLive = timeToLive;
}

ExplosionParticle::~ExplosionParticle()
{
}

void ExplosionParticle::Move()
{
	pos.x += speed.x;
	pos.y += speed.y;
	pos.z += speed.z;
}

Flame::Flame(float x, float y, float z)
{
	this->explosionCounter = 7;
	this->speed = 1;
	this->timeToLive = 10;
	this->particlesEmittedPerTick = 10;
	source.x = x;
	source.y = y;
	source.z = z;

	flameImg = ImageUtil::loadBmp("..\\Debug\\textures\\flame.bmp");
	explosionImg = ImageUtil::loadBmp("..\\Debug\\textures\\explosion.bmp");
}

Flame::~Flame()
{
	list<Particle>::iterator iter = flameParticles.begin();
	while (iter != flameParticles.end())
	{
		iter = flameParticles.erase(iter);
	}

	list<ExplosionParticle>::iterator exploIter = explosionParticles.begin();
	while (exploIter != explosionParticles.end())
	{
		exploIter = explosionParticles.erase(exploIter);
	}
}

void Flame::emitParticles()
{
	if (explosionCounter > 0)
	{
		explosionCounter--;
		emitExplosion();
	}
	else if (explosionCounter > -7)
	{
		explosionCounter--;
		emitExplosion();
		emitFlame();
	}
	else
	{
		emitFlame();
	}
}

void Flame::emitExplosion()
{
	for (int i = 0; i < particlesEmittedPerTick * 7; ++i)
	{
		int limit = 15;
		float x, y, z;
		x = (float)(rand() % (2 * limit) - limit) / 10.0;
		y = (float)(rand() % (2 * limit) - limit) / 10.0;
		z = (float)(rand() % (2 * limit) - limit) / 10.0;

		ExplosionParticle particle(
			source.x, source.y, source.z,
			x, y, z,
			this->timeToLive - 3);
		explosionParticles.push_front(particle);
	}
}

void Flame::emitFlame()
{
	for (int i = 0; i < particlesEmittedPerTick; ++i)
	{
		int limit = 40;
		float x, z;
		x = (float)(rand() % (2 * limit) - limit) / 10.0;
		x += source.x;
		z = (float)(rand() % (2 * limit) - limit) / 10.0;
		z += source.z;
		Particle particle(x, source.y, z, this->timeToLive);
		flameParticles.push_front(particle);
	}
}

void Flame::affectParticles()
{
	list<Particle>::iterator iter = flameParticles.begin();
	while (iter != flameParticles.end())
	{
		iter->pos.y += this->speed;
		if (iter->timeToLive-- <= 0)
		{
			iter = flameParticles.erase(iter);
		}
		else
		{
			iter++;
		}
	}

	list<ExplosionParticle>::iterator exploIter = explosionParticles.begin();
	while (exploIter != explosionParticles.end())
	{
		exploIter->Move();
		if (exploIter->timeToLive-- <= 0)
		{
			exploIter = explosionParticles.erase(exploIter);
		}
		else
		{
			exploIter++;
		}
	}
}

void Flame::displayFlame()
{
	// przygotowanie do wyswietlenia obrazka
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	list<Particle>::iterator iter = flameParticles.begin();
	while (iter != flameParticles.end())
	{
		// wyswietlanie czasteczki
		glRasterPos3fv(iter->pos);
		if (flameImg != NULL)
		{
			glDrawPixels(flameImg->sizeX, flameImg->sizeY, GL_RGB, GL_UNSIGNED_BYTE, flameImg->data);
		}
		else
		{
			// cos na wypadek gdyby obrazek sie nie wczytal
		}

		iter++;
	}

	list<ExplosionParticle>::iterator exploIter = explosionParticles.begin();
	while (exploIter != explosionParticles.end())
	{
		glRasterPos3fv(exploIter->pos);
		if (explosionImg != NULL)
		{
			glDrawPixels(explosionImg->sizeX, explosionImg->sizeY, GL_RGB, GL_UNSIGNED_BYTE, explosionImg->data);
		}
		else
		{
			// cos na wypadek gdyby obrazek sie nie wczytal
		}

		exploIter++;
	}
}