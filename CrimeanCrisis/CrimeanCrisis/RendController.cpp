#include "RendController.h"

Renderer* RendController::renderer = NULL;// new Renderer(); // NULL ?

RendController::RendController()
{
}

RendController::~RendController()
{
}

void RendController::setObject(GraphicObject *o)
{
	renderer = new Renderer(o);
}

void RendController::init(GraphicObject *o)
{
	setObject(o);
	renderer->init();

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);			// Display Mode
	glutInitWindowSize(renderer->win.width, renderer->win.height);		// set window size
	glutCreateWindow(renderer->win.title);
	// create Window
	glewExperimental = GL_TRUE;			// TESTING
	glewInit();

	glutDisplayFunc(display);											// register Display Function
	glutTimerFunc(5, animate, 1);										// TODO
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeys);										// register Keyboard Handler
	glutMouseFunc(mouse);

	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, renderer->win.width, renderer->win.height);
	GLfloat aspect = (GLfloat)renderer->win.width / renderer->win.height;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(renderer->win.field_of_view_angle, aspect, renderer->win.z_near, renderer->win.z_far);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0.5f, 0.5f, 0.8f, 0.5f);						// kolor okna
	glClearDepth(1.0f);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	GLfloat amb_light[] = { 0.1, 0.1, 0.1, 1.0 };
	GLfloat diffuse[] = { 0.6, 0.6, 0.6, 1 };
	GLfloat specular[] = { 0.7, 0.7, 0.3, 1 };

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb_light);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 1);
	glDepthFunc(GL_LEQUAL);

	renderer->plain->SetDisplay();
}

void RendController::display()
{
	renderer->display();
}

void RendController::animate(int value) {
	glutTimerFunc(20, animate, 1);
	renderer->animate();
}
void RendController::keyboard(unsigned char key, int x, int y)
{
	renderer->keyboard(key, x, y);
}

void RendController::specialKeys(int key, int x, int y)
{
	renderer->specialKeys(key, x, y);
}

void RendController::mouse(int button, int state, int x, int y)
{
	renderer->mouse(button, state, x, y);
	/*
	button:	GLUT_LEFT_BUTTON, GLUT_MIDDLE_BUTTON, GLUT_RIGHT_BUTTON
	state:	GLUT_DOWN, GLUT_UP
	x, y:
	*/
}

void RendController::resize(int w, int h)
{
	renderer->resize(w, h);
}
