using System.Collections.Generic;
using System.Globalization;
using System.IO;
using OpenTK;

namespace GrafikaKomputerowa
{
	class Importer
	{
		public static void LoadMesh(/* */)
		{
			// do takiej listy można zapisywać odczytywane dane o wierzchołkach (zmienić nazwę)
			List<meshOBJ.meshData> NAZWAZMIENNEJ = new List<meshOBJ.meshData>();

			StreamReader reader = new StreamReader(Settings.dirModels + "PLIK.obj");
			string line;

			while( (line = reader.ReadLine()) != null )
			{
				// przetwarzanie pliku
			}
		}
	}
}
