#ifndef _UNITS_H_
#define _UNITS_H_

#include "Types.h"

// Base class for objects
class Unit {

private:
	Vector pos;
	Color color;

public:
	Unit();
	Unit(Vector pos);

	Vector getPos();
	void setPos();
	void move(float x, float y, float z);
};

// Teapot class
class Teapot : public Unit {

private:
	// Teapot size
	float size;
	// Material properties
	float ambient[4], diffuse[4], specular[4], shininess;

};

// Plane class
class Plane : public Unit {

public:
	static enum PlaneType
	{
		WALL, PARTITION_WALL, FLOOR
	};

private:
	// Dimension
	float w, h;
	// Normal vector
	Vector N;
	// Type of plane
	PlaneType type;

	// Calculates normal vector
	void CalcNormalVector();

public:
	Plane();
	Plane(PlaneType type, Vector pos, float w, float h);


};

// Class representing OpenGL light settings
class Light {
private:
	int number;
	Vector pos;
	Vector dir;
	float attenuation[3];
	float cutoff;
	float exponent;

	void initAttenuation();
	void initCutoff();
	void initExponent();

public:
	Light();
	Light(int number, Vector pos);
	Light(int number, Vector pos, Vector dir);
	Light(int number, Vector pos, Vector dir, float* attenuation);
	Light(int number, Vector pos, Vector dir, float cutoff, float exponent);
	Light(int number, Vector pos, Vector dir, float* attenuation, float cutoff, float exponent);

	int getNumber();
	Vector getPos();
	float* getPosVector();
	Vector getDir();
	float getAttenuation(int i);
	float getCutoff();
	float getExponent();

	void setNumber(int mode);
	void setPos(Vector pos);
	void setPos(float* pos);
	void setDir(Vector dir);
	void setDir(float* dir);
	void setAttenuation(int mode, float attenuation);
	void setCutoff(float cutoff);
	void setExponent(float exponent);

	void modifyAttenuation(int mode, float change);
	void modifyCutoff(float change);
	void modifyExponent(float change);
};

#endif