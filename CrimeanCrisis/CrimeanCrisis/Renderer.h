#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define CUT_PARAM 10.0f
<<<<<<< HEAD
=======
//#define GLEW_STATIC
>>>>>>> d175017a0f84bf6dee2c2a67cc10cf605b5b4451

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
<<<<<<< HEAD
=======
#include "Rain.h"
#include "UI.h"
#include "MainMenu.h"
#include "ServerMenu.h"

enum Screen
{
	MainMenuScreen,
	ServerMenuScreen,
	GameScreen
};
>>>>>>> d175017a0f84bf6dee2c2a67cc10cf605b5b4451

class Renderer
{
public:
	Renderer();
<<<<<<< HEAD
	Renderer(GraphicObject*);
	~Renderer();

	typedef struct 
=======
	Renderer(std::list<GraphicObject>*);
	~Renderer();

	typedef struct
>>>>>>> d175017a0f84bf6dee2c2a67cc10cf605b5b4451
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

<<<<<<< HEAD
=======
	void set3D(int w, int h);
	void set2D(int w, int h);

>>>>>>> d175017a0f84bf6dee2c2a67cc10cf605b5b4451
	void defaultMaterial();
	void drawBulb(Light light);
	void setLight(Light light);

<<<<<<< HEAD
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
=======
	//accessors
	GraphicObject* GetPlain() { return plain; }
	bool IsRaining() { return isRaining; }

	glutWindow win;
	
private:
	Screen screen;
>>>>>>> d175017a0f84bf6dee2c2a67cc10cf605b5b4451
	int x1, x2, y1, y2;								// wspó³rzêdne kursora
	int map_x1, map_x2, map_y1, map_y2;				// wspó³rzêdne na mapie
	GLFWwindow *window;
	float g_rotation;
	std::list<GraphicObject> *objList;			// jednostka (lista jednostek)
	GraphicObject *plain;		// mapa

	Vector cam;					// po³o¿enie kamery
	Vector dir;					// ukierunkowanie kamery

	float nearParam, farParam,
		leftParam, rightParam,
		topParam, bottomParam;

	bool mousePressed;

	Light* sun;
	Rain* rain;
	GameUI * gameUI;
	MainMenu * mainMenu;
	ServerMenu * serverMenu;

	bool isRaining;

	void displayGameScreen();
	void displayMainMenuScreen();
	void displayServerMenuScreen();
};



