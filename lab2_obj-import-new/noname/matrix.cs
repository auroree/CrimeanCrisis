using OpenTK;
using OpenTK.Graphics.OpenGL;

namespace GrafikaKomputerowa
{
	class Matrix
	{
		public static Vector3 TranslatePosition(Vector3 position)
		{
			GL.PushMatrix();
			GL.Translate(position);			// light position must be multiplied by current modelview matrix
			Matrix4 matrix;
			GL.GetFloat(GetPName.ModelviewMatrix, out matrix);
			GL.PopMatrix();

			return matrix.Row3.Xyz;			// translated position
		}
	}
}
