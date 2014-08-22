#ifndef _TYPES_H_
#define _TYPES_H_

#include <Windows.h>
#include <GL/GL.h>

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

// Class representing rectangle in 3D space
class Rectangle {
private:
	static int count;
	int id;
	Vector startPoint;
	// width
	float dim1;
	// height or depth
	float dim2;

	void initDims();

public:
	Rectangle();
	Rectangle(Vector startPoint);
	Rectangle(Vector startPoint, float dim1, float dim2);

	int getCount();
	int getId();
	Vector getStartPoint();
	float getWidth();
	float getHeight();
	float getDepth();

	void setId(int id);
	void setStartPoint(Vector point);
	void setWidth(float width);
	void setHeight(float height);
	void setDepth(float depth);

	void modifyWidth(float width);
	void modifyHeight(float height);
	void modifyDepth(float depth);
};

#endif