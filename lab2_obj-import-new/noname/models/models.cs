using System.Drawing;
using OpenTK;
using OpenTK.Graphics.OpenGL;

namespace GrafikaKomputerowa
{
	class Models
	{
		public static void DrawAxises()
		{
			GL.PushMatrix();
			GL.LineWidth(2);
			GL.Begin(BeginMode.Lines);

			GL.Color3(Color.Red);			//X
			GL.Vertex3(0.0f, 0.0f, 0.0f);
			GL.Vertex3(100.0f, 0.0f, 0.0f);

			GL.Color3(Color.Blue);			//Y
			GL.Vertex3(0.0f, 0.0f, 0.0f);
			GL.Vertex3(0.0f, 100.0f, 0.0f);

			GL.Color3(Color.Green);			//Z
			GL.Vertex3(0.0f, 0.0f, 0.0f);
			GL.Vertex3(0.0f, 0.0f, -100.0f);

			GL.Color3(Color.White);
			GL.End();
			GL.PopMatrix();
		}
		public static void NormalTextureCube()
		{
			GL.PushMatrix();
			//GL.BindTexture(TextureTarget.Texture2D, Game.texture);
			GL.Begin(BeginMode.Quads);
			// Front Face
			GL.Normal3(0.0f, 0.0f, 1.0f);
			GL.TexCoord2(0.0f, 0.0f); GL.Vertex3(-1.0f, -1.0f, 1.0f);
			GL.TexCoord2(1.0f, 0.0f); GL.Vertex3(1.0f, -1.0f, 1.0f);
			GL.TexCoord2(1.0f, 1.0f); GL.Vertex3(1.0f, 1.0f, 1.0f);
			GL.TexCoord2(0.0f, 1.0f); GL.Vertex3(-1.0f, 1.0f, 1.0f);
			// Back Face
			GL.Normal3(0.0f, 0.0f, -1.0f);
			GL.TexCoord2(1.0f, 0.0f); GL.Vertex3(-1.0f, -1.0f, -1.0f);
			GL.TexCoord2(1.0f, 1.0f); GL.Vertex3(-1.0f, 1.0f, -1.0f);
			GL.TexCoord2(0.0f, 1.0f); GL.Vertex3(1.0f, 1.0f, -1.0f);
			GL.TexCoord2(0.0f, 0.0f); GL.Vertex3(1.0f, -1.0f, -1.0f);
			// Top Face
			GL.Normal3(0.0f, 1.0f, 0.0f);
			GL.TexCoord2(0.0f, 1.0f); GL.Vertex3(-1.0f, 1.0f, -1.0f);
			GL.TexCoord2(0.0f, 0.0f); GL.Vertex3(-1.0f, 1.0f, 1.0f);
			GL.TexCoord2(1.0f, 0.0f); GL.Vertex3(1.0f, 1.0f, 1.0f);
			GL.TexCoord2(1.0f, 1.0f); GL.Vertex3(1.0f, 1.0f, -1.0f);
			// Bottom Face
			GL.Normal3(0.0f, -1.0f, 0.0f);
			GL.TexCoord2(1.0f, 1.0f); GL.Vertex3(-1.0f, -1.0f, -1.0f);
			GL.TexCoord2(0.0f, 1.0f); GL.Vertex3(1.0f, -1.0f, -1.0f);
			GL.TexCoord2(0.0f, 0.0f); GL.Vertex3(1.0f, -1.0f, 1.0f);
			GL.TexCoord2(1.0f, 0.0f); GL.Vertex3(-1.0f, -1.0f, 1.0f);
			// Right face
			GL.Normal3(1.0f, 0.0f, 0.0f);
			GL.TexCoord2(1.0f, 0.0f); GL.Vertex3(1.0f, -1.0f, -1.0f);
			GL.TexCoord2(1.0f, 1.0f); GL.Vertex3(1.0f, 1.0f, -1.0f);
			GL.TexCoord2(0.0f, 1.0f); GL.Vertex3(1.0f, 1.0f, 1.0f);
			GL.TexCoord2(0.0f, 0.0f); GL.Vertex3(1.0f, -1.0f, 1.0f);
			// Left Face
			GL.Normal3(-1.0f, 0.0f, 0.0f);
			GL.TexCoord2(0.0f, 0.0f); GL.Vertex3(-1.0f, -1.0f, -1.0f);
			GL.TexCoord2(1.0f, 0.0f); GL.Vertex3(-1.0f, -1.0f, 1.0f);
			GL.TexCoord2(1.0f, 1.0f); GL.Vertex3(-1.0f, 1.0f, 1.0f);
			GL.TexCoord2(0.0f, 1.0f); GL.Vertex3(-1.0f, 1.0f, -1.0f);
			GL.End();
			GL.PopMatrix();
		}
		public static void DrawPlates()
		{
			for( int x = -10; x <= 10; x++ )
			{
				for( int z = -10; z <= 10; z++ )
				{
					GL.PushMatrix();
					GL.Translate((float)x * 5f, 0f, (float)z * 5f);
					GL.Begin(BeginMode.Quads);
					GL.Normal3(0.0f, 0.0f, 1.0f);
					GL.Color3(Color.Red);
					GL.Vertex3(1f, -10f, 0f);
					GL.Color3(Color.Orange);
					GL.Vertex3(-1f, -10f, 0f);
					GL.Color3(Color.Brown);
					GL.Vertex3(-1f, -15f, 0f);
					GL.Color3(Color.Maroon);
					GL.Vertex3(1f, -15f, 0f);
					GL.End();
					GL.PopMatrix();
				}
			}
		}
		public static void DrawCube(float edge, Vector3 position)
		{
			GL.PushMatrix();
			GL.Translate(position);
			GL.Begin(BeginMode.Quads);

			GL.Normal3(0.0f, 1.0f, 0.0f);
			GL.Color4(Color.Blue);
			GL.Vertex3(-edge / 2, edge / 2, -edge / 2);        // top
			GL.Vertex3(-edge / 2, edge / 2, edge / 2);
			GL.Vertex3(edge / 2, edge / 2, edge / 2);
			GL.Vertex3(edge / 2, edge / 2, -edge / 2);

			GL.Normal3(0.0f, -1.0f, 0.0f);
			GL.Color4(Color.Orange);
			GL.Vertex3(-edge / 2, -edge / 2, -edge / 2);      // bottom
			GL.Vertex3(edge / 2, -edge / 2, -edge / 2);
			GL.Vertex3(edge / 2, -edge / 2, edge / 2);
			GL.Vertex3(-edge / 2, -edge / 2, edge / 2);

			GL.Normal3(-1.0f, 0.0f, 0.0f);
			GL.Color4(Color.Green);
			GL.Vertex3(-edge / 2, -edge / 2, -edge / 2);       // left
			GL.Vertex3(-edge / 2, -edge / 2, edge / 2);
			GL.Vertex3(-edge / 2, edge / 2, edge / 2);
			GL.Vertex3(-edge / 2, edge / 2, -edge / 2);

			GL.Normal3(1.0f, 0.0f, 0.0f);
			GL.Color4(Color.Brown);
			GL.Vertex3(edge / 2, -edge / 2, -edge / 2);        // right
			GL.Vertex3(edge / 2, edge / 2, -edge / 2);
			GL.Vertex3(edge / 2, edge / 2, edge / 2);
			GL.Vertex3(edge / 2, -edge / 2, edge / 2);

			GL.Normal3(0.0f, 0.0f, 1.0f);
			GL.Color4(Color.Purple);
			GL.Vertex3(-edge / 2, -edge / 2, edge / 2);        // front
			GL.Vertex3(edge / 2, -edge / 2, edge / 2);
			GL.Vertex3(edge / 2, edge / 2, edge / 2);
			GL.Vertex3(-edge / 2, edge / 2, edge / 2);

			GL.Normal3(0.0, 0.0f, -1.0f);
			GL.Color4(Color.DeepSkyBlue);
			GL.Vertex3(-edge / 2, -edge / 2, -edge / 2);       // back
			GL.Vertex3(-edge / 2, edge / 2, -edge / 2);
			GL.Vertex3(edge / 2, edge / 2, -edge / 2);
			GL.Vertex3(edge / 2, -edge / 2, -edge / 2);

			GL.End();
			GL.PopMatrix();
		}
		public static void DrawCubeReverse(float edge, Vector3 position)
		{
			GL.PushMatrix();
			GL.Translate(position);
			GL.Begin(BeginMode.Quads);

			GL.Normal3(0.0f, -1.0f, 0.0f);
			GL.Color4(Color.Blue);
			GL.Vertex3(edge / 2, edge / 2, -edge / 2);
			GL.Vertex3(edge / 2, edge / 2, edge / 2);
			GL.Vertex3(-edge / 2, edge / 2, edge / 2);
			GL.Vertex3(-edge / 2, edge / 2, -edge / 2);        // top

			GL.Normal3(0.0f, 1.0f, 0.0f);
			GL.Color4(Color.Orange);
			GL.Vertex3(-edge / 2, -edge / 2, edge / 2);
			GL.Vertex3(edge / 2, -edge / 2, edge / 2);
			GL.Vertex3(edge / 2, -edge / 2, -edge / 2);
			GL.Vertex3(-edge / 2, -edge / 2, -edge / 2);      // bottom

			GL.Normal3(1.0f, 0.0f, 0.0f);
			GL.Color4(Color.Green);
			GL.Vertex3(-edge / 2, edge / 2, -edge / 2);
			GL.Vertex3(-edge / 2, edge / 2, edge / 2);
			GL.Vertex3(-edge / 2, -edge / 2, edge / 2);
			GL.Vertex3(-edge / 2, -edge / 2, -edge / 2);       // left

			GL.Normal3(-1.0f, 0.0f, 0.0f);
			GL.Color4(Color.Brown);
			GL.Vertex3(edge / 2, -edge / 2, edge / 2);
			GL.Vertex3(edge / 2, edge / 2, edge / 2);
			GL.Vertex3(edge / 2, edge / 2, -edge / 2);
			GL.Vertex3(edge / 2, -edge / 2, -edge / 2);        // right

			GL.Normal3(0.0f, 0.0f, -1.0f);
			GL.Color4(Color.Purple);
			GL.Vertex3(-edge / 2, edge / 2, edge / 2);
			GL.Vertex3(edge / 2, edge / 2, edge / 2);
			GL.Vertex3(edge / 2, -edge / 2, edge / 2);
			GL.Vertex3(-edge / 2, -edge / 2, edge / 2);        // front

			GL.Normal3(0.0, 0.0f, 1.0f);
			GL.Color4(Color.DeepSkyBlue);
			GL.Vertex3(edge / 2, -edge / 2, -edge / 2);
			GL.Vertex3(edge / 2, edge / 2, -edge / 2);
			GL.Vertex3(-edge / 2, edge / 2, -edge / 2);
			GL.Vertex3(-edge / 2, -edge / 2, -edge / 2);       // back

			GL.End();
			GL.PopMatrix();
		}

	}
}
