#include "Renderer.h"

using namespace glm;

Renderer::Renderer() : window(NULL)
{
	this->win.width = 1024;
	this->win.height = 480;
	this->win.title = "CrimeanCrisis BETA";
	this->win.field_of_view_angle = 45;
	this->win.z_near = 0.0f;
	this->win.z_far = 1500.0f;				// 1500f

	plain = new GraphicObject();
	plain->loadOBJ("models/plain.obj", "grafiki/tex1.bmp");
}

Renderer::Renderer(GraphicObject *o) 
{
	this->win.width = 1024;
	this->win.height = 480;
	this->win.title = "CrimeanCrisis BETA";
	this->win.field_of_view_angle = 45;
	this->win.z_near = 0.0f;
	this->win.z_far = 1500.0f;
	obj = o;		//przeciążyć operator
	plain = new GraphicObject();
	plain->loadOBJ("models/plain.obj", "grafiki/tex1.bmp");
}

Renderer::~Renderer()
{
}

void Renderer::updateWindow()
{
	glutSwapBuffers();
}
void Renderer::init()
{
	leftParam = rightParam = topParam = bottomParam = CUT_PARAM;
	nearParam = 15.0;
	farParam = 200.0;

	this->cam.x = 25.0;
	this->cam.y = 50.0;
	this->cam.z = 25.0;
	this->dir.x = this->dir.y = this->dir.z = 0;

	teapot.x = 0.0;
	teapot.y = 3.5;
	teapot.z = 10.0;
	teapotColor[0] = 0.75;
	teapotColor[1] = 1.0;
	teapotColor[2] = 0.65;
	teapotColor[4] = 1.0;
	teapotAngle = 0.0;
	teapotDir = false;

	ambient[0] = 0.850000;
	ambient[1] = 0.207250;
	ambient[2] = 0.207250;
	ambient[4] = 0.922000;

	diffuse[0] = 1.000000;
	diffuse[1] = 0.829000;
	diffuse[2] = 0.829000;
	diffuse[3] = 0.922000;

	specular[0] = 0.996648;
	specular[1] = 0.096648;
	specular[2] = 0.096648;
	specular[3] = 0.999000;

	shininess = 10;

	// light1
	Vector lightPos(-20, 18, 3), lightDir(0, -1, 0);
	float att[3] = { 1.5, 0, 0 };
	light1 = new Light(0, lightPos, lightDir, att, 180, 0);	

	x1 = x2 = y1 = y2 = 0;
}

void Renderer::display()
{	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cam.x, cam.y, cam.z, dir.x, dir.y, dir.z, 0.0, 1.0, 0.0);
	drawBulb(*light1);
	setLight(*light1);
	glColor3f(1.0, 1.0, 0.7);
	glTranslatef(-3.0, 2.0, 10.0);

	glPopMatrix();
	glPushMatrix();
	plain->Draw();		// rysuj mapę
	obj->Draw();		// rysuj jednostki
	glPopMatrix();
	glutSwapBuffers();
}

void Renderer::animate()
{
	glutPostRedisplay();
}

void Renderer::keyboard(unsigned char key, int x, int y)
{
	float* p;
	float yChange = 1;

	switch (key) {
	case '1':
		//light1->setCutoff(light1->getCutoff() + 5);
		break;
	case '2':
		//light1->setCutoff(light1->getCutoff() - 5);
		break;
	case 'q':
		//p = light1->getPos();
		//p[0] += 1;
		//light1->setPos(p);
		break;
	case 'a':
		//p = light1->getPos();
		//p[0] -= 1;
		//light1->setPos(p);
		break;
	case 'w':
		cam.y -= 0.5;
		dir.y -= 0.5;
		break;
	case 's':
		cam.y += 0.5;
		dir.y += 0.5;
		//p = light1->getPos();
		//p[1] -= 1;
		//light1->setPos(p);
		break;
	case 'e':
		//p = light1->getPos();
		//p[2] += 1;
		//light1->setPos(p);
		break;
	case 'd':
		//p = light1->getPos();
		//p[2] -= 1;
		//light1->setPos(p);
		break;
	case 'r':
		//light1->modifyExponent(0.33);
		break;
	case 'f':
		//light1->modifyExponent(-0.33);
		break;
	case 'u':
		//light1->modifyAttenuation(2, 0.03);
		obj->rot.x += 2.0;
		break;
	case 'o':
		//light1->modifyAttenuation(2, 0.03);
		obj->rot.x -= 2.0;
		break;
	case 'y':
		//light1->modifyAttenuation(2, 0.03);
		obj->rot.y += 2.0;
		break;
	case 'h':
		//light1->modifyAttenuation(2, 0.03);
		obj->rot.y -= 2.0;
		break;
	case 't':
		//light1->modifyAttenuation(2, 0.03);
		obj->rot.z += 2.0;
		break;
	case 'g':
		//light1->modifyAttenuation(2, 0.03);
		obj->rot.z -= 2.0;
		break;
	case 'j':
		//light1->modifyAttenuation(2, -0.03);
		obj->pos.x -= 1.0;
		break;
	case 'l':
		//light1->modifyAttenuation(2, -0.03);
		obj->pos.x += 1.0;
		break;
	case 'i':
		//light1->modifyAttenuation(2, -0.03);
		obj->pos.z -= 1.0;
		break;
	case 'k':
		//light1->modifyAttenuation(2, -0.03);
		obj->pos.z += 1.0;
		break;
	case KEY_ESCAPE:
		exit(0);
		break;
	case ' ':
		//cam.z += 1.0;
		break;
	case '-':
		if (cam.y < 100) {
			cam.x = (cam.y + yChange) * cam.x / cam.y;
			cam.z = (cam.y + yChange) * cam.z / cam.y;
			cam.y += yChange;
		}
		break;
	case '+':
		if (cam.y > 25) {
			cam.x = (cam.y - yChange) * cam.x / cam.y;
			cam.z = (cam.y - yChange) * cam.z / cam.y;
			cam.y -= yChange;
		}
		break;
	}
}

void Renderer::specialKeys(int key, int x, int y)
{

	float move = 2.5;

	switch (key)
	{
	case GLUT_KEY_RIGHT:
		cam.x += move;
		dir.x += move;
		//teapot.x += move;
		break;
	case GLUT_KEY_LEFT:
		cam.x -= move;
		dir.x -= move;
		//teapot.x -= move;
		break;
	case GLUT_KEY_UP:
		cam.z -= move;
		dir.z -= move;
		//teapot.z -= move / 2;
		break;
	case GLUT_KEY_DOWN:
		cam.z += move;
		dir.z += move;
		//teapot.z += move / 2;
		break;
	}
}

void Renderer::mouse(int button, int state, int x, int y)
{

	switch (button)
		//case GLUT_LEFT_BUTTON:
		//	if (state == GLUT_DOWN)			// TEST
		//		printf("Click!");
		//	else if (state == GLUT_UP)
		//		printf("Clock!");
		case GLUT_LEFT_BUTTON:
		{
			// TODO
			// znacznik bool selected

			if (state == GLUT_DOWN)		// pobranie początkowych współrzędnych
			{
				x1 = x;
				y1 = y;
			}
			if (state == GLUT_UP)		// pobranie końcowych współrzędnych i ray casting + konwersja ze współrzędnych kursora do mapy
			{
				x2 = x;
				y2 = y;
			}
			printf("X1 coordinate: %d\nY1 coordinate: %d\n\n", x1, y1);
			printf("X2 coordinate: %d\nY2 coordinate: %d\n\n", x2, y2);
		}
}

void Renderer::resize(int w, int h) 
{
	// Set viewport size to be entire OpenGL window.
	glViewport(0, 0, w, h);

	// Set matrix mode to projection.
	glMatrixMode(GL_PROJECTION);

	// Clear current projection matrix to identity.
	glLoadIdentity();

	// wysokoœæ okna wiêksza od wysokoœci okna
	if (w < h && w > 0) {
		glFrustum(-leftParam, rightParam, -bottomParam * h / w, topParam * h / w, nearParam, farParam);
	}
	else {

		// szerokoœæ okna wiêksza lub równa wysokoœci okna
		if (w >= h && h > 0) {
			glFrustum(-leftParam * w / h, rightParam * w / h, -bottomParam, topParam, nearParam, farParam);
		}
	}
}

void Renderer::defaultMaterial() {
	GLfloat defaultAmbient[] = { 0.2, 0.2, 0.2, 1 };
	GLfloat defaultDiffuse[] = { 0.8, 0.8, 0.8, 1 };
	GLfloat defaultSpecular[] = { 0, 0, 0, 1 };
	GLfloat defaultShininess = 0;
	GLfloat defaultEmission[] = { 0, 0, 0, 1 };

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, defaultAmbient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, defaultDiffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, defaultSpecular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, defaultShininess);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, defaultEmission);
}

void Renderer::drawBulb(Light light)
{
	float emission[] = { 0.9, 0.9, 0.8, 1 };
	glMaterialfv(GL_FRONT, GL_EMISSION, emission);
	glColor4f(1.0, 1.0, 0.8, 0.95);

	glPushMatrix();
	Vector pos = light.getPos();
	glTranslatef(pos.x, pos.y, pos.z);
	glutSolidSphere(0.7, 20, 20);

	glPopMatrix();
	defaultMaterial();
}

void Renderer::setLight(Light light) {
	GLenum number = GL_LIGHT0 + light.getNumber();
	glLightfv(number, GL_POSITION, light.getPosVector());
	glLightfv(number, GL_SPOT_DIRECTION, light.getDir());
	glLightf(number, GL_SPOT_CUTOFF, light.getCutoff());
	glLightf(number, GL_CONSTANT_ATTENUATION, light.getAttenuation(0));
	glLightf(number, GL_LINEAR_ATTENUATION, light.getAttenuation(1));
	glLightf(number, GL_QUADRATIC_ATTENUATION, light.getAttenuation(2));
	glLightf(number, GL_SPOT_EXPONENT, light.getExponent());
}