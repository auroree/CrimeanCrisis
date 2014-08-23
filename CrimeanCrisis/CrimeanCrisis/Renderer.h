#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define CUT_PARAM 10.0f
//#define GLEW_STATIC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <vector>
#include "lib/GL/glew.h"
#include "lib/GLFW/glfw3.h"
#include "lib/GL/glut.h"
#include "lib/glm/glm.hpp"
#include "lib/glm/gtc/matrix_transform.hpp"
#include "GraphicObject.h"
#include "Types.h"
#include "Units.h"


class Renderer
{
public:
	Renderer();
	Renderer(GraphicObject*);
	~Renderer();

	typedef struct
	{
		int width;
		int height;
		char* title;

		float field_of_view_angle;
		float z_near;
		float z_far;
	}	glutWindow;			// okno

	void updateWindow();

	void init();
	void display();
	void keyboard(unsigned char, int, int);
	void specialKeys(int, int, int);
	void mouse(int, int, int, int);
	void resize(int, int);
	void animate();

	void defaultMaterial();
	void drawBulb(Light light);
	void setLight(Light light);

	glutWindow win;
	float g_rotation;
	GraphicObject *obj;			// jednostka (lista jednostek)
	GraphicObject *plain;		// mapa

	Vector cam;					// po³o¿enie kamery
	Vector dir;					// ukierunkowanie kamery

	float nearParam, farParam,
		leftParam, rightParam,
		topParam, bottomParam;

	Light* light1;
	Vector teapot;
	// Teapot color
	float teapotColor[4];
	// Teapot angle
	float teapotAngle;
	boolean teapotDir;
	GLfloat ambient[4];
	GLfloat diffuse[4];
	GLfloat specular[4];
	GLfloat shininess;

private:
	int x1, x2, y1, y2;								// wspó³rzêdne kursora
	int map_x1, map_x2, map_y1, map_y2;				// wspó³rzêdne na mapie
	GLFWwindow *window;
};



