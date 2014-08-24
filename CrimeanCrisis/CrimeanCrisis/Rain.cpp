#include "Rain.h"
#include <iostream>

using namespace std;

Rain::Rain()
{
	this->density = 0.05;
	this->speed = 0.9;
	this->area = 200;
	srand(time(NULL));
}

Rain::Rain(float density, float speed)
{
	if (density <= 0.1)
	{
		this->density = density;
	}
	else
	{
		this->density = 0.1;
	}
	this->speed = speed;
	this->area = 100;
	srand(time(NULL));
}

void Rain::emitParticles()
{
	for (int i = 0; i < density * area * area / 10; ++i)
	{
		float x = (float)(rand() % (area * 10) - area * 5) / 10.0;
		float z = (float)(rand() % (area * 10) - area * 5) / 10.0;
		RainParticle particle(x, 60, z);
		particles.push_front(particle);
	}
}

void Rain::affectParticles()
{
	list<RainParticle>::iterator iter = particles.begin();
	while (iter != particles.end())
	{
		iter->pos.y -= this->speed;

		if (iter->pos.y <= 0)
		{
			iter = particles.erase(iter);
		}
		else
		{
			iter++;
		}

	}
	cout << particles.size() << endl;
}

void Rain::displayRain()
{
	list<RainParticle>::iterator iter = particles.begin();
	while (iter != particles.end())
	{
		glColor4f(0.0, 0.0, 1.0, 0.5);
		glBegin(GL_LINES);
		glVertex3fv(iter->pos);
		glVertex3f(iter->pos.x, iter->pos.y - 1, iter->pos.z);
		glEnd();

		iter++;
	}
}

RainParticle::RainParticle(float x, float y, float z)
{
	pos.x = x;
	pos.y = y;
	pos.z = z;
}

RainParticle::~RainParticle()
{
}


