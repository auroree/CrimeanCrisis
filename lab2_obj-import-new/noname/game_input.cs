using System;
using System.Drawing;
using System.Windows.Forms;
using OpenTK;
using OpenTK.Graphics.OpenGL;
using OpenTK.Input;

namespace GrafikaKomputerowa
{
	partial class Game
	{
		public Vector3 positionCamera = new Vector3();
		public Vector3 lightpos		  = new Vector3();

		float mousex = 0, mousey = 0;	// cursor position
		
		float move			 = 0.5f;	// movement speed
		float mouseMoveScale = 0.1f;	// rotation speed

		bool cursor = true;				// true means its in window possession
		public string lighting="OFF";
		public double FPSAvarge;		// store avarge fps (updated once a second)
		public double FPSFramesCounter;	// sum of OnRenderFrame loops in a second (updated once a second)
		public static int UPS = 0;		// sum of OnUpdateFrame loops in a second (updated once a second)
		public static int updateCounter = 0;

		/// <summary>Called when it is time to setup the next frame. Add your game logic here.</summary>
		/// <param name="e">Contains timing information for framerate independent logic.</param>
		protected override void OnUpdateFrame(FrameEventArgs e) // 4th
		{
			updateCounter++;
			base.OnUpdateFrame(e);

			#region PLAYER MOVEMENT
			if( Keyboard[Key.Left] )
			{
				positionCamera.X -= (float)Math.Cos(Dtr(mousex)) * move;
				positionCamera.Z -= (float)Math.Sin(Dtr(mousex)) * move;
			}
			if( Keyboard[Key.Right] )
			{
				positionCamera.X += (float)Math.Cos(Dtr(mousex)) * move;
				positionCamera.Z += (float)Math.Sin(Dtr(mousex)) * move;
			}
			if( Keyboard[Key.Up] )
			{											 // without this cos(), cannot move directly up/down
				positionCamera .X += (float)Math.Sin(Dtr(mousex)) * (float)Math.Cos(Dtr(mousey)) * move;
				positionCamera .Z -= (float)Math.Cos(Dtr(mousex)) * (float)Math.Cos(Dtr(mousey)) * move;
				positionCamera .Y += (float)Math.Sin(Dtr(mousey)) * move;
			}
			if( Keyboard[Key.Down] )
			{
				positionCamera.X -= (float)Math.Sin(Dtr(mousex)) * (float)Math.Cos(Dtr(mousey)) * move;
				positionCamera.Z += (float)Math.Cos(Dtr(mousex)) * (float)Math.Cos(Dtr(mousey)) * move;
				positionCamera.Y -= (float)Math.Sin(Dtr(mousey)) * move;
			}
			if( Keyboard[Key.PageDown] )	positionCamera.Y -= move;
			if( Keyboard[Key.PageUp] )		positionCamera.Y += move;
			if( Keyboard[Key.R] ) { positionCamera = Vector3.Zero; }	// reset position
			#endregion PLAYER MOVEMENT

			#region CURSOR MANAGER
			if( Mouse[MouseButton.Left] )
			{
				if( !cursor )		// if cursor dont belongs to window
				{
					cursor = true;
					SetCursor();
				}
			}
			if( Mouse[MouseButton.Right] )
			{
				if( cursor )		// if cursor belong to window
				{
					cursor = false;
					Cursor.Clip = Screen.PrimaryScreen.Bounds;
					Cursor.Show();
				}
			}
			if( cursor )			// update position 
				Cursor.Position = new Point(centerX, centerY);
			#endregion CURSOR MANAGER

			if( Keyboard[Key.Escape] )
			{
				oneSecondTimer.Stop();
				Exit();
			}
		}
		// EVENT - For single key hit
		void Keyboard_KeyUp(object sender, KeyboardKeyEventArgs e)
		{
			if( e.Key == Key.F1 )
				WindowState = WindowState.Fullscreen;
			if( e.Key == Key.F2 )
				WindowState = WindowState.Normal;
		}
		// EVENT - Onece at every second
		protected void OnEverySecond(object sender, System.Timers.ElapsedEventArgs e)
		{
			if( renderCounter > 0 )
			{
				FPSAvarge = FPScounter / renderCounter;
				FPSFramesCounter = renderCounter;
			}
			else
			{
				FPSAvarge = 0;
				FPSFramesCounter = 0;
			}

			try
			{
				renderCounter = 0;		// fps counter
				FPScounter = 0;			// reset

				UPS = updateCounter;	// ups
				updateCounter = 0;		// ups counter reset
			}
			catch
			{
				Settings.Message("zdarzenie OnEverySecond w 'game_input.cs' nie uzyskało dostępu do zmiennych //wątki?");
			}
		}
		// EVENT - When cursor is in move inside window
		void Mouse_Move(object sender, MouseMoveEventArgs e)
		{
			if( cursor )
			{
				mousex += (Cursor.Position.X - centerX) * mouseMoveScale;
				mousey -= (Cursor.Position.Y - centerY) * mouseMoveScale;
				mousex %= 360;
				if( mousey > 90 )
					mousey = 90;
				if( mousey < -90 )
					mousey = -90;
			}
		}
		// EVENT - change movement speed
		void Mouse_WheelChanged(object sender, MouseWheelEventArgs e)
		{
			move += e.DeltaPrecise * 0.3f * move;
		}
		// degree to radian conversion
		double Dtr(double angle)
		{
			return Math.PI * angle / 180.0;
		}
	}
}
