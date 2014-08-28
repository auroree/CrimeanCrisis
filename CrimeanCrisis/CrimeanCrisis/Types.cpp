#include "Types.h"

// --- Vector

Vector::Vector() {
	x = y = z = 0;
}

Vector::Vector(const Vector &p) {
	this->x = p.x;
	this->y = p.y;
	this->z = p.z;
}

Vector::Vector(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector::Vector(float tab[], int count) {
	switch (count) {
	case 3: z = tab[2];
	case 2: y = tab[1];
	case 1: x = tab[0];
	}
}

Vector::operator float* () {
	return reinterpret_cast<float*>(this);
}

float Vector::dot(Vector arg) {
	return arg.x * this->x + arg.y * this->y + arg.z * this->z;
}

Vector Vector::cross(Vector arg) {
	Vector v;
	v.x = this->y * arg.z - this->z * arg.y;
	v.y = -this->x * arg.z + this->z * arg.x;
	v.z = this->x * arg.y - this->y * arg.x;
	return v;
}

// --- COLOR 

Color::Color() {
	r = g = b = a = 1.0;
}

Color::Color(const Color &c) {
	this->r = c.r;
	this->g = c.g;
	this->b = c.b;
	this->a = c.a;
}

Color::Color(float r, float g, float b) {
	this->r = r;
	this->g = g;
	this->b = b;
}

Color::Color(float r, float g, float b, float a) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

Color::Color(float tab[], int count) {
	switch (count) {
	case 4: a = tab[3];
	case 3: b = tab[2];
	case 2: g = tab[1];
	case 1: r = tab[0];
	}
}

Color::operator float* () {
	return reinterpret_cast<float*>(this);
}

