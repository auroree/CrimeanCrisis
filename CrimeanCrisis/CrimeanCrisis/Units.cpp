#include "Units.h"

// --- LIGHT

void Light::initAttenuation() {
	attenuation[0] = 1;
	attenuation[1] = attenuation[2] = 0;
}

void Light::initCutoff() {
	cutoff = 180;
}

void Light::initExponent() {
	exponent = 0;
}

Light::Light() {
	initAttenuation();
	initCutoff();
	initExponent();
}

Light::Light(int number, Vector pos) {
	setNumber(number);
	this->pos = pos;
	initAttenuation();
	initCutoff();
	initExponent();
}

Light::Light(int number, Vector pos, Vector dir) {
	setNumber(number);
	this->pos = pos;
	this->dir = dir;
	initAttenuation();
	initCutoff();
	initExponent();
}

Light::Light(int number, Vector pos, Vector dir, float* attenuation) {
	setNumber(number);
	this->pos = pos;
	this->dir = dir;
	setAttenuation(0, attenuation[0]);
	setAttenuation(1, attenuation[1]);
	setAttenuation(2, attenuation[2]);
	initCutoff();
	initExponent();
}

Light::Light(int number, Vector pos, Vector dir, float cutoff, float exponent) {
	setNumber(number);
	this->pos = pos;
	this->dir = dir;
	setCutoff(cutoff);
	setExponent(exponent);
	initAttenuation();
}

Light::Light(int number, Vector pos, Vector dir, float* attenuation, float cutoff, float exponent) {
	setNumber(number);
	this->pos = pos;
	this->dir = dir;
	setAttenuation(0, attenuation[0]);
	setAttenuation(1, attenuation[1]);
	setAttenuation(2, attenuation[2]);
	setCutoff(cutoff);
	setExponent(exponent);
}

int Light::getNumber() {
	return number;
}

Vector Light::getPos() {
	return pos;
}

Vector Light::getDir() {
	return dir;
}

float Light::getAttenuation(int i) {
	return attenuation[i];
}

float Light::getCutoff() {
	return cutoff;
}

float Light::getExponent() {
	return exponent;
}

void Light::setNumber(int number) {
	if (number >= 0) {
		this->number = number;
	}
}

void Light::setPos(Vector pos) {
	this->pos = pos;
}

void Light::setPos(float* pos) {
	this->pos.x = pos[0];
	this->pos.y = pos[1];
	this->pos.z = pos[2];
}

void Light::setDir(Vector dir) {
	this->dir = dir;
}

void Light::setDir(float* dir) {
	this->dir.x = dir[0];
	this->dir.y = dir[1];
	this->dir.z = dir[2];
}

void Light::setAttenuation(int mode, float attenuation) {
	if (mode >= 0 && mode < 3) {
		if (attenuation >= 0) {
			this->attenuation[mode] = attenuation;
		}
	}
}

void Light::setCutoff(float cutoff) {
	if ((cutoff > 0 && cutoff <= 90) || cutoff == 180) {
		this->cutoff = cutoff;
	}
}

void Light::setExponent(float exponent) {
	if (exponent >= 0) {
		this->exponent = exponent;
	}
}

void Light::modifyAttenuation(int mode, float attenuation) {
	if (mode >= 0 && mode < 3) {
		setAttenuation(mode, this->attenuation[mode] + attenuation);
	}
}

void Light::modifyCutoff(float cutoff) {
	setCutoff(this->cutoff + cutoff);
}

void Light::modifyExponent(float exponent) {
	setExponent(this->exponent + exponent);
}