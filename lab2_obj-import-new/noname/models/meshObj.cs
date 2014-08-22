using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.Runtime.InteropServices;
using OpenTK;
using OpenTK.Graphics.OpenGL;

namespace GrafikaKomputerowa
{
	class meshOBJ
	{
		meshData[] NAZWA_TABLICY_W;		// tablica na wierzchołki (zmienić nazwę)
		uint[] NAZWA_TABLICY_I;			// tablica na indeksy (zmienić nazwę)

		public meshOBJ()
		{
			Importer.LoadMesh(/* */);	// load mesh
		}
		public void Render()
		{
			// render mesh
		}

		public struct meshData
		{
			public Vector3 normal;
			public Vector3 vertex;
		}
	}
}