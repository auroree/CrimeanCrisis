#include "Picture.h"


Picture::Picture(const std::string &nazwa_pliku, int szerokosc_klatki, int wysokosc_klatki, int x_rogu, int y_rogu) : \
nazwa(nazwa_pliku), width(szerokosc_klatki), height(wysokosc_klatki), wx(x_rogu), wy(y_rogu), resize(1), klatka(1) {

	SDL_Surface *surface = IMG_Load(nazwa.c_str());
	if (!surface) {
	//	throw Exception_Picture(nazwa, LOAD);
		fprintf(stderr, "Nie dalo sie zaladowac pliku %s\n", nazwa_pliku.c_str(), SDL_GetError());
		exit(1);
	}
	else {
		fprintf(stderr, "Zaladowano grafike: %s\n", nazwa_pliku.c_str());
	}

	// sprawdŸ wymiary - czy s¹ potêg¹ 2
	tex_w = surface->w;
	tex_h = surface->h;
	if (((tex_w & (tex_w - 1)) != 0) || ((tex_h & (tex_h - 1)) != 0)) {
		delete surface;
	//	throw Exception_Picture(nazwa, DIMENSION);
		fprintf(stderr, "Zle wymiary obrazka %s\n", nazwa_pliku.c_str(), SDL_GetError());
		exit(1);
	}

	GLenum format;

	GLint nOfColors = surface->format->BytesPerPixel;
	if (nOfColors == 4) {     // contains an alpha channel
		if (surface->format->Rmask == 0x000000ff)
			format = GL_RGBA;
		else
			format = GL_BGRA;
	}
	else if (nOfColors == 3) {    // no alpha channel
		if (surface->format->Rmask == 0x000000ff)
			format = GL_RGB;
		else
			format = GL_BGR;
	}
	else {
		printf("warning: the image is not truecolor..  this will probably break\n");
		// this error should not go unhandled
	}

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexImage2D(GL_TEXTURE_2D, 0, surface->format->BytesPerPixel, surface->w, surface->h, 0,
		format, GL_UNSIGNED_BYTE, surface->pixels);

	SDL_FreeSurface(surface);
}


void Picture::WklejKlatke(int nr_klatki = 1) {

	glBindTexture(GL_TEXTURE_2D, texture);

	const double right = 1.0*(nr_klatki*width + wx) / tex_w;
	const double left = 1.0*(nr_klatki*width + wx - width) / tex_w;
	const double bottom = 1.0*(height + wy) / tex_h;
	const double top = 1.0*(wy) / tex_h;

	//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	//    glLoadIdentity();

	glPushMatrix();
	{
		glTranslatef(0, 0, -static_cast<double>(0));
		glBegin(GL_QUADS);
		{
			glTexCoord2f(left, bottom);   glVertex2f(x, y + height*resize);
			glTexCoord2f(right, bottom);	glVertex2f(x + width*resize, y + height*resize);
			glTexCoord2f(right, top);	glVertex2f(x + width*resize, y);
			glTexCoord2f(left, top);   glVertex2f(x, y);
		}
		glEnd();
	}
	glPopMatrix();
}

/*-------------------------------------------------------------------------------------*/

void Picture::Update(int lx, int ly) {
	x = lx;
	y = ly;
	WklejKlatke(klatka);
}

/*-------------------------------------------------------------------------------------*/

void Picture::UpdateMiddle(int lx, int ly) {
	x = lx - width / 2;
	y = ly - height / 2;
	WklejKlatke(klatka);
}

/*-------------------------------------------------------------------------------------*/

bool Picture::InArea(int lx, int ly) {
	if ((lx>x) && (lx<x + width) && (ly>y) && (ly<y + height))
		return true;
	else
		return false;
}