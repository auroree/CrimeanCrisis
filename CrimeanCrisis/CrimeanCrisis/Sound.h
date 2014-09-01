#pragma once

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include "lib/SDL/SDL_mixer.h"
#include "lib/SDL/SDL.h"

class Sound
{
public:
	Sound();
	~Sound();

	void LoadSounds();
	void PlayMusic(const std::string& name);
	void PlaySfx(const std::string& name);

private:
	void LoadMusic(const std::string& name, const std::string& filename);
	void LoadSfx(const std::string& name, const std::string& filename);

	std::map<std::string, Mix_Chunk*> m_sfx;
	std::map<std::string, Mix_Music*> m_music;
};

