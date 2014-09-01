#include "Glowny_kontroler.h"

//#undef main
int wmain(int argc, char *argv[])
{
	glutInit(&argc, argv);

	Glowny_kontroler kontroler;
	kontroler.Start();		//tu jest g³ówna pêtla gry
	return 0;
}