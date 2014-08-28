#ifndef _TYPES_H_
#define _TYPES_H_

#include <Windows.h>
#include "lib/GL/GL.h"

// Structure representing point or vector in 3D space
class Vector
{
public:
	float x, y, z;

	Vector();
	Vector(const Vector &p);
	Vector(float x, float y, float z);
	Vector(float tab[], int count);
	operator float* ();

	float dot(Vector arg);
	Vector cross(Vector arg);
};

// Structure representing RGB/RGBA color
class Color {
public:
	float r, g, b, a;

	Color();
	Color(const Color &c);
	Color(float r, float g, float b);
	Color(float r, float g, float b, float a);
	Color(float tab[], int count);
	operator float* ();

};

#endif