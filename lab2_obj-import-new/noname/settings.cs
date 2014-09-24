using System;
using System.IO;


namespace GrafikaKomputerowa
{
	static class Settings
	{
		/// <summary>"\"</summary>
		public static string dir =			Directory.GetCurrentDirectory()+"\\";
		/// <summary>"\files\"</summary>
		public static string dirFiles =		dir + "files\\";
		/// <summary>"\shaders\"</summary>
		public static string dirShaders =	dir + "shaders\\";
		/// <summary>"\models\"</summary>
		public static string dirModels =	dirFiles + "models\\";
		/// <summary>"\textures\"</summary>
		public static string dirTextures = dirFiles + "textures\\";

		public static void TerminateWindow(string info)
		{
			System.Windows.Forms.MessageBox.Show(info);
			Environment.Exit(0);
		}
		public static void Message(string info)
		{
			Console.WriteLine(info);
			//System.Windows.Forms.MessageBox.Show(info);
		}
	}
}
