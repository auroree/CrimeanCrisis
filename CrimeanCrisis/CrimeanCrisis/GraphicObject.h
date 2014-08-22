#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define POINTS_PER_VERTEX 3
#define TOTAL_FLOATS_IN_TRIANGLE 9

//STARE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <vector>
#include "lib/GL/glew.h"
#include "lib/GLFW/glfw3.h"
#include "lib/glm/glm.hpp"
#include "lib/glm/gtc/matrix_transform.hpp"
#include "lib/GL/gl.h"
#include "lib/GL/glu.h"
#include "lib/GL/glut.h"
#include "Types.h"

#define KEY_ESCAPE 27

using namespace glm;
using namespace std;

class GraphicObject
{
public:

	typedef struct					
	{								
		float x, y;								
	}	point2d;				

	typedef struct					
	{								//	cfl │ cfp	(front)
		point2d fl, fp;				//	 ┌──┼──┐	cfp, cfl, cbl, cbp - const (starting rotation, but location must be updated)
		point2d bl, bp;				//	 ║┌─┴─┐║
		point2d cfl, cfp;			//	 ║│   │║
		point2d cbl, cbp;			//	 ║└───┘║
		float currentRotation;		//   └─────┘
		float cRadius;				//  cbl   cbp	(back)
	}	boundingBox;				
									

	GraphicObject();
	GraphicObject(Vector p, Vector r, int l, int w);
	virtual ~GraphicObject();
	GraphicObject operator=(const GraphicObject &);
	virtual bool loadOBJ(const char *path, const char * texturePath);
	virtual bool loadTexture(const char* texturePath);
	void setSize(int l, int w);
	void rotateBoundingBox(float angle);
	void SetDisplay();
	void Draw();					// Draws the model on the screen
	virtual void Update() {};

	Vector pos;
	Vector rot;

private:
	GLuint VertexArrayID, vertexbuffer;
	vector< unsigned int > vertexIndices, uvIndices, normalIndices;
	vector< glm::vec3 > OBJvertices;
	vector< glm::vec2 > OBJuvs;
	vector< glm::vec3 > OBJnormals;
	
	float Color[4];
	long TotalConnectedPoints;				// Stores the total number of connected verteces
	long TotalConnectedTriangles;			// Stores the total number of connected triangles
	
	int objWidth, objLength;
	boundingBox box;
};

