using System;
using System.Collections.Generic;
using System.Drawing;
using System.Globalization;
using System.IO;
using System.Windows.Forms;
using OpenTK;
using OpenTK.Graphics.OpenGL;

namespace GrafikaKomputerowa
{
	partial class Game
	{
		/// <summary>OpenGL initialization</summary>
		void OpenGLInit()
		{
			GL.ShadeModel(ShadingModel.Smooth);
			GL.Enable(EnableCap.DepthTest);
			GL.DepthFunc(DepthFunction.Lequal);
			GL.Enable(EnableCap.ColorMaterial);
			//GL.Enable(EnableCap.CullFace);
			//GL.CullFace(CullFaceMode.Back);
			GL.Enable(EnableCap.Lighting);
			GL.Hint(HintTarget.PerspectiveCorrectionHint, HintMode.Nicest);
			GL.ClearColor(Color.DarkGray);		// background color
		}
		/// <summary>Load engine resourses (models, interface, etc)</summary>
		void EngineInit()
		{
			// READ SETUP FILE
			StreamReader setupFile = null;
			try
			{
				setupFile = new StreamReader(Settings.dir + "\\setup");
			}
			catch
			{
				Settings.TerminateWindow(Settings.dir + "\nNie można odczytać pliku konfiguracyjnego 'setup'");
			}
			string line;
			while( (line = setupFile.ReadLine()) != null )
			{
				string[] args = line.Split(' ');
				switch( args[0] )
				{
					case "self":	// user position
						positionCamera.X = float.Parse(args[1], CultureInfo.InvariantCulture);
						positionCamera.Y = float.Parse(args[2], CultureInfo.InvariantCulture);
						positionCamera.Z = float.Parse(args[3], CultureInfo.InvariantCulture);
						break;
				}
			}

			// clean
			setupFile.Dispose();
		}
		/// <summary>
		/// Set lighting
		/// </summary>
		void Lighting()
		{
			float[] lightDiffuse = { 1.0f, 1.0f, 1.0f, 1.0f };
			float[] lightSpecular = { 0.0f, 1.0f, 0.0f, 1.0f };
			float[] lightShininess = { 100.0f };
			float[] lightAmbient = { 0.0f, 0.0f, 0.0f, 1.0f };

			GL.LightModel(LightModelParameter.LightModelAmbient, lightAmbient);
			GL.Material(MaterialFace.FrontAndBack, MaterialParameter.Diffuse, lightDiffuse);
			GL.Material(MaterialFace.FrontAndBack, MaterialParameter.Specular, lightSpecular);
			GL.Material(MaterialFace.FrontAndBack, MaterialParameter.Shininess, lightShininess);
			GL.Light(LightName.Light0, LightParameter.Diffuse, lightDiffuse);
			GL.Light(LightName.Light0, LightParameter.Specular, lightSpecular);

			GL.Enable(EnableCap.Light0);
		}
		/// <summary>Set cursor at center of the window, hide, and limit its movement area</summary>
		void SetCursor()
		{
			int windowBorder = (Size.Width - Width)/2;				// border left/righr/bottom (check winXP if there is top border)
			int windowBar = Size.Height - Height - windowBorder;	// window title bar
			Point loc = new Point(Location.X + windowBorder, Location.Y + windowBar);	// working start location

			centerX = Location.X + Size.Width / 2;
			centerY = Location.Y + Height / 2 + windowBar;
			
			Cursor.Hide();
			Cursor.Clip = new Rectangle(loc, ClientSize);
		}
	}
}
