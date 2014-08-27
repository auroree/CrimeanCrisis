#pragma once

#include "Klient.h"
#include "GameServer.h"
#include "Picture.h"
#include "Renderer.h"
#include "GraphicObject.h"
#include "Sound.h"
#include "RendController.h"

class Glowny_kontroler
{
public:
	Glowny_kontroler();
	~Glowny_kontroler();
	void Start();

private:
	Sound *_sound;
	Klient *_client;
	GameServer *_server;
	std::list<GraphicObject> *_objects;
};
