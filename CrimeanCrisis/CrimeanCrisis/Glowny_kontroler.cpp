#include "Glowny_kontroler.h"

Glowny_kontroler::Glowny_kontroler()
{
}


Glowny_kontroler::~Glowny_kontroler()
{
}

void Glowny_kontroler::Start() 
{
	bool the_end = false;
	GameServer server;
	Klient klient;
	//poniższy kod odpowiada za uruchomienie serwera i klienta
	//std::thread first(&GameServer::Start, server);
	//std::thread second(&Klient::Start, klient);
	//first.join();
	//second.join();
	Renderer *renderer = new Renderer();		// Renderer test
	std::vector< glm::vec3 > vertices;
	std::vector< glm::vec2 > uvs;
	std::vector< glm::vec3 > normals;
//	renderer->createWindow();
	GraphicObject test_obj;
	//if (test_obj.loadOBJ("models/t1.obj", vertices, uvs, normals))
	//	fprintf(stdout,"zaladowano obiekt\n");
	//else
	//	fprintf(stdout,"nie zaladowano obiektu\n");

	Picture Tlo("grafiki/tekstura.png", 800, 600, 0, 0);

	while (!the_end)
	{
		//wystartowanie servera i klienta, oba potrzebne tylko do multi i będzie trzeba je uruchamiać
		//w jakimś konkretnym momencie - a na razie nic lepszego nie ma, więc niech tu będą
		//uprzejmie proszę o niezważanie na chwilową brzydotę - dopóki nie będę wiedział co mam przesyłać,
		//to trzeba będzie się obchodzić smakiem i cieszyć z tego co mamy

		Tlo.Update(100, 200);

		//tu gdzieś będzie główna pętla gry

		//najpierw trzeba by wyswietlic na pewno jakies menu startowe i potem pokierowac dalej,
		//bo do rozgrywki jako takiej bedzie osobna pętla
		glfwPollEvents();	//zamiast tego powinna być ładnie użyta klasa Events czy coś. 
							//To tutaj jest tylko dlatego, żeby okienko ładnie się wyświetlało.
		renderer->updateWindow();	//odświeżenie okna
	}
}