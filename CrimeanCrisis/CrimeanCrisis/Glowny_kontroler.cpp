#include "Glowny_kontroler.h"
#include <thread> 

Glowny_kontroler::Glowny_kontroler()
{
}


Glowny_kontroler::~Glowny_kontroler()
{
}

void Glowny_kontroler::Start() 
{
	bool the_end = false;

	while (!the_end)
	{
		//wystartowanie servera i klienta, oba potrzebne tylko do multi i będzie trzeba je uruchamiać
		//w jakimś konkretnym momencie - a na razie nic lepszego nie ma, więc niech tu będą
		//uprzejmie proszę o niezważanie na chwilową brzydotę - dopóki nie będę wiedział co mam przesyłać,
		//to trzeba będzie się obchodzić smakiem i cieszyć z tego co mamy
		GameServer server;
		Klient klient;
		std::thread first(&GameServer::Start, server);
		std::thread second(&Klient::Start, klient);
		first.join();
		second.join();

		//tu gdzieś będzie główna pętla gry

		//najpierw trzeba by wyswietlic na pewno jakies menu startowe i potem pokierowac dalej,
		//bo do rozgrywki jako takiej bedzie osobna pętla
		
	}
}