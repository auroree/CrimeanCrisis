using System;
using System.Collections.Generic;
using System.Drawing;
using System.Threading;
using OpenTK;
using OpenTK.Graphics;
using OpenTK.Graphics.OpenGL;
using OpenTK.Input;

namespace GrafikaKomputerowa
{
	partial class Game : GameWindow
	{
		#region VARIABLES

		DateTime time = new DateTime();			// scene loading time
		public TimeSpan loadingTime;

		bool firstTime = true;					// first frame
		int centerX, centerY;					// center mouse pointer in the middle of the window
		public static int renderCounter = 0;	// render loop counter
		public static int FPScounter = 0;		// FPS counter by adding RenderFrequency value and than avarged by renderCounter value

		public static System.Timers.Timer oneSecondTimer;	// event for once in a second purposes

		#endregion VARIABLES

		/// <summary>
		/// Creates a window with the specified resolution and title.
		/// </summary>
		public Game(): base(800, 600, GraphicsMode.Default, "HELLO BZYK") // 1st
		{
			time = DateTime.Now;
			VSync = VSyncMode.On;
		}
		/// <summary>
		/// Called when your window is resized. Set your viewport here. It is also a good place to
		/// set up your projection matrix (which probably changes along when the aspect ratio of your window).
		/// </summary>
		/// <param name="e">Not used.</param>
		protected override void OnResize(EventArgs e) // 2nd
		{
			base.OnResize(e);
			
			GL.Viewport(ClientRectangle);

			// Create and load projection matrix
			Matrix4 projection = Matrix4.CreatePerspectiveFieldOfView((float)Math.PI / 4, Width / (float)Height, 0.1f, 10000.0f);
			GL.MatrixMode(MatrixMode.Projection);	// set mode
			GL.LoadMatrix(ref projection);			// load
			
			// Set modelview matrix and load identity matrix
			GL.MatrixMode(MatrixMode.Modelview);	// set mode
			GL.LoadIdentity();						// load (identity)

		}
		/// <summary>
		/// Load resources here.
		/// </summary>
		/// <param name="e">Not used.</param>
		protected override void OnLoad(EventArgs e) // 3rd
		{
			base.OnLoad(e);
			
			//// game_init.cs ////
			OpenGLInit();		// - OpenGL initialization
			EngineInit();		// - Load scene, models, interface, etc
			SetCursor();		// - Set cursor position and working area
			Lighting();			// - Set lighting
			//////////////////////
			#region HANDY EVENTS

			// set handy events
			Mouse.Move += new EventHandler<MouseMoveEventArgs>(Mouse_Move);
			Keyboard.KeyUp += new EventHandler<KeyboardKeyEventArgs>(Keyboard_KeyUp);
			Mouse.WheelChanged += new EventHandler<MouseWheelEventArgs>(Mouse_WheelChanged);
			// Handy function for once in a time changes
			oneSecondTimer  = new System.Timers.Timer(1000);
			oneSecondTimer.Elapsed += new System.Timers.ElapsedEventHandler(OnEverySecond);
			oneSecondTimer.Start();

			#endregion HANDY EVENTS



		}
		/// <summary>
		/// Called when it is time to render the next frame.
		/// </summary>
		/// <param name="e">Contains timing information.</param>
		protected override void OnRenderFrame(FrameEventArgs e)	// 5th
		{
			#region FPS counter and loading time calc.
			base.OnRenderFrame(e);
			if( firstTime ) { loadingTime = time - DateTime.Now; firstTime = false; mousex = 0; mousey = 0; }	// loading time
			FPScounter += (int)RenderFrequency;	// avarged in oneSecondTimer event and displayed in interface
			renderCounter++;
			#endregion

			GL.Clear(ClearBufferMask.ColorBufferBit | ClearBufferMask.DepthBufferBit);

			GL.LoadIdentity();
			GL.Rotate(-mousey, 1.0f, 0.0f, 0.0f);
			GL.Rotate(mousex, 0.0f, 1.0f, 0.0f);
			GL.Translate(-positionCamera);		// translate world [ Free Look in First Person Perspective ]

			GL.Light(LightName.Light0, LightParameter.Position, new Vector4(positionCamera, 0.0f));

			GL.Disable(EnableCap.Texture2D);			// DISABLE TEXTURING
			//// HERE DRAW TEXTURELESS! OBJECTS ////

				Models.DrawAxises();

			GL.Enable(EnableCap.Texture2D);				// ENABLE TEXTURING
			//// HERE DRAW TEXTURED OBJECTS ////



			GL.Disable(EnableCap.Texture2D);			// DISABLE TEXTURING
			SwapBuffers();
		}

		/// <summary>The main entry point for the application.</summary>
		[STAThread]
		static void Main()
		{
			// The 'using' idiom guarantees proper resource cleanup. We request 30 UpdateFrame
			// events per second, and unlimited RenderFrame events (as fast as the computer can handle).
			using( Game game = new Game() )
			{
				game.Run(25.0);
			}
		}
	}
}