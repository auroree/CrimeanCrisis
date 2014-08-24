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
	float* tab = (float*)malloc(3 * sizeof(float));
	tab[0] = x;
	tab[1] = y;
	tab[2] = z;
	return tab;
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
	float* tab = (float*)malloc(4 * sizeof(float));
	tab[0] = r;
	tab[1] = g;
	tab[2] = b;
	tab[3] = a;
	return tab;
}

// --- RECTANGLE

int Rectangle::count = 0;

void Rectangle::initDims() {
	dim1 = dim2 = 1;
	count++;
}

Rectangle::Rectangle() {
	startPoint.x = startPoint.y = startPoint.z = 0;
	initDims();
	count++;
}

Rectangle::Rectangle(Vector startPoint) {
	this->startPoint = startPoint;
	initDims();
	count++;
}

Rectangle::Rectangle(Vector startPoint, float dim1, float dim2) {
	this->startPoint = startPoint;
	if (dim1 > 0) {
		this->dim1 = dim1;
	}
	else {
		dim1 = 1;
	}
	if (dim2 > 0) {
		this->dim2 = dim2;
	}
	else {
		dim2 = 1;
	}
	count++;
}

int Rectangle::getCount() {
	return count;
}

int Rectangle::getId() {
	return id;
}

Vector Rectangle::getStartPoint() {
	return startPoint;
}

float Rectangle::getWidth() {
	return dim1;
}

float Rectangle::getHeight() {
	return dim2;
}

float Rectangle::getDepth() {
	return dim2;
}

void Rectangle::setId(int id) {
	this->id = id;
}

void Rectangle::setStartPoint(Vector point) {
	this->startPoint = point;
}

void Rectangle::setWidth(float width) {
	if (width > 0) {
		this->dim1 = width;
	}
}

void Rectangle::setHeight(float height) {
	if (height > 0) {
		this->dim2 = height;
	}
}

void Rectangle::setDepth(float depth) {
	if (depth > 0) {
		this->dim2 = depth;
	}
}

void Rectangle::modifyWidth(float width) {
	if (width > 0) {
		this->dim1 += width;
	}
}

void Rectangle::modifyHeight(float height) {
	if (height > 0) {
		this->dim2 += height;
	}
}

void Rectangle::modifyDepth(float depth) {
	if (depth > 0) {
		this->dim2 += depth;
	}
}
