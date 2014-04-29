#pragma once

#include <string>
//#include <glut.h>

#include "lib/SDL/SDL.h"
#include "lib/SDL/SDL_image.h"
#include "lib/GL/glew.h"
#include "lib/GLFW/glfw3.h"


#define GL_BGR 0x80E0 
#define GL_BGRA 0x80E1
#define GL_CLAMP_TO_EDGE 0x812F

class Picture {		//klasa dla pojedynczych obrazków
protected:
	int width,			//szerokoœæ klatki
		height,			//wysokoœæ klatki
		wx,				//wspolrzedna lewego górnego rogu klatki w poziomie
		wy,				//wspolrzedna lewego górnego rogu klatki w pionie
		tex_w,			//szerokosc tekstury	
		tex_h,			//wysokosc tekstury
		klatka;			//aktualna klatka
	int x, y;		
	double resize;		//modyfikator rozmiaru - domyœlnie 1
	std::string nazwa;	//nazwa pliku
	GLuint texture;
	//SDL_Surface *surface;

	virtual void WklejKlatke(int nr_klatki);

public:
	Picture(const std::string &nazwa_pliku, int szerokosc_klatki, int wysokosc_klatki, int x_rogu, int y_rogu);
	virtual ~Picture() { };
	virtual void Update(int lx, int ly);				//Wyswietla obrazek w odpowiednim miejscu
	virtual void UpdateMiddle(int lx, int ly);			//Wyswietla obrazek w odpowiednim miejscu, ale bierze pod uwage jego srodek
	virtual void Resize(double ile_razy) {				//Modyfikuje rozmiar obrazka (podajemy u³amek)
		resize = ile_razy;
	}
	virtual void Resize(int nowa_wysokosc_klatki) {					//Modyfikuje rozmiar obrazka (podajemy wysokoœæ)
		resize = 1.0*nowa_wysokosc_klatki / height;
	}
	virtual void ZmienKlatke(int nr_klatki) {				//pozwala ustawic rêcznie klatkê
		klatka = nr_klatki;
	}
	virtual bool InArea(int lx, int ly);				//sprawdza czy te wpolrzedne zawieraja sie w teksturze
};
