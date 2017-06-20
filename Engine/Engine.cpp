// Engine.cpp: implementation of the Engine class.
//
//////////////////////////////////////////////////////////////////////

#include "Engine.h"
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Engine::Use(RenderArgs* args)
{
	if (args)
	{
		::wglMakeCurrent(args->DC(), args->RC());
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Engine::PreRender(RenderArgs* args)
{
	float color[3];
	if (args)
	{
		Use(args);
		args->GetBgColor(color);

		::glMatrixMode(GL_PROJECTION);
		::glLoadIdentity();

		::glClearColor(color[0], color[1], color[2], 0.0f);
		::glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Engine::PostRender(RenderArgs* args)
{
	if (args)
	{
		SwapBuffers(args->DC());
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Engine::Resize(RenderArgs* args)
{
	if (args)
	{	
		::glViewport(0, 0, args->Width(), args->Height());
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Engine::PreSelect(SelectionArgs* args)
{
	int viewport[4];

	if (args)
	{
		RenderArgs* r = args->RenderArguments();

		Use(r);

		::glGetIntegerv(GL_VIEWPORT, viewport);
		::glSelectBuffer(args->BufferSize(), args->SelectionBuffer());
		
		::glRenderMode(GL_SELECT);
		::glInitNames();
		::glPushName(-1);

		::glMatrixMode(GL_PROJECTION);
		::glLoadIdentity();

		::gluPickMatrix((GLdouble)args->X(), (GLdouble) (viewport[3] - args->Y()), 1, 1, viewport);
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Engine::PostSelect(SelectionArgs* args)
{
	if (args)
	{
		args->GatherHits();
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Engine::Goto2D(RenderArgs* args)
{
	float zoomFactor = args->Camera()->GetZoom();
	if (args)
	{
		::glPushMatrix();
		::glOrtho(-zoomFactor*args->Aspect(), zoomFactor*args->Aspect(), -zoomFactor, zoomFactor, -args->FarClipping(), args->FarClipping());
//		::glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		::glMatrixMode(GL_MODELVIEW);
		::glLoadIdentity();
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Engine::Leave2D(RenderArgs* args)
{
	if (args)
	{
		::glPopMatrix();

		::glMatrixMode(GL_PROJECTION);
		::glLoadIdentity();
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Engine::Goto2DFromArgs(RenderArgs* args)
{
	if (args)
	{
		::glPushMatrix();
		::glOrtho(0.0f, (float)args->Width(), 0.0f, (float)args->Height(), -1.0f, 1.0f);
//		::glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		::glMatrixMode(GL_MODELVIEW);
		::glLoadIdentity();
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Engine::Leave2DFromArgs(RenderArgs* args)
{
	if (args)
	{
		::glPopMatrix();

		::glMatrixMode(GL_PROJECTION);
		::glLoadIdentity();
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Engine::Goto3D(RenderArgs* args)
{
	float zoomFactor = 0.05f;
	if (args)
	{
		::glPushMatrix();
		::gluPerspective(args->FieldOfView(), args->Aspect(), args->NearClipping(), args->FarClipping());
//		::glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		::glMatrixMode(GL_MODELVIEW);
		::glLoadIdentity();
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Engine::Leave3D(RenderArgs* args)
{
	if (args)
	{
		::glPopMatrix();

		::glMatrixMode(GL_PROJECTION);
		::glLoadIdentity();
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
int Engine::AddFont(RenderArgs* args, char* fontface, int size)
{
	int result = -1;

	if (args)
	{
		int list = glGenLists(255);

		if (list)
		{
			HFONT font = CreateFont(	size, 0, 0, 0, FW_MEDIUM, FALSE,
										FALSE, FALSE, DEFAULT_CHARSET, OUT_TT_PRECIS,
										CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY,
										FF_DONTCARE | DEFAULT_PITCH, fontface);
			if (font)
			{
				HFONT hFont = (HFONT)::SelectObject(args->DC(), font);

				::wglUseFontBitmaps(args->DC(), 1, 255, result);

				::SelectObject(args->DC(), hFont);
			}
		}
	}
	return result;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Engine::RenderText(RenderArgs* args, int x, int y, int font, const char *format, ...)
{
    va_list argp;
    char text[256];

    va_start(argp, format);
    vsprintf(text, format, argp);
    va_end(argp);

	for (int i = 0; i < (int)strlen(text); i++)
	{
		text[i] -= 1;
	}

	glRasterPos2i(x, y);
    glListBase(font);
    glCallLists(strlen(text), GL_BYTE, text);
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Engine::RenderCube(float size, float position[])
{

	::glPushMatrix();

	::glTranslatef(position[0], position[1], position[2]);

	::glBegin(GL_QUADS);
	// Front Face
//	::glColor3f(1.0f, 0.0f, 0.0f);
	::glNormal3f( 0.0f, 0.0f, 1.0f);					// Normal Pointing Towards Viewer
	::glTexCoord2f(0.0f, 0.0f); ::glVertex3f( -(size/2),  -(size/2),  size/2);			// Point 1 (Front)
	::glTexCoord2f(1.0f, 0.0f); ::glVertex3f( size/2,  -(size/2),  size/2);		// Point 2 (Front)
	::glTexCoord2f(1.0f, 1.0f); ::glVertex3f( size/2,  size/2,  size/2);	// Point 3 (Front)
	::glTexCoord2f(0.0f, 1.0f); ::glVertex3f( -(size/2),  size/2,  size/2);		// Point 4 (Front)
	// Back Face
//	::glColor3f(1.0f, 1.0f, 0.0f);
	::glNormal3f( 0.0f, 0.0f,-1.0f);					// Normal Pointing Away From Viewer
	::glTexCoord2f(1.0f, 0.0f); ::glVertex3f( -(size/2),  -(size/2),  -(size/2));				// Point 1 (Back)
	::glTexCoord2f(1.0f, 1.0f); ::glVertex3f( -(size/2),  size/2,  -(size/2));			// Point 2 (Back)
	::glTexCoord2f(0.0f, 1.0f); ::glVertex3f( size/2,  size/2,  -(size/2));		// Point 3 (Back)
	::glTexCoord2f(0.0f, 0.0f); ::glVertex3f( size/2,  -(size/2),  -(size/2));			// Point 4 (Back)
	// Top Face
//	::glColor3f(0.0f, 1.0f, 0.0f);
	::glNormal3f( 0.0f, 1.0f, 0.0f);					// Normal Pointing Up
	::glTexCoord2f(0.0f, 1.0f); ::glVertex3f( -(size/2),  size/2,  -(size/2));			// Point 1 (Top)
	::glTexCoord2f(0.0f, 0.0f); ::glVertex3f( -(size/2),  size/2,  size/2);		// Point 2 (Top)
	::glTexCoord2f(1.0f, 0.0f); ::glVertex3f( size/2,  size/2,  size/2);	// Point 3 (Top)
	::glTexCoord2f(1.0f, 1.0f); ::glVertex3f( size/2,  size/2,  -(size/2));		// Point 4 (Top)
	// Bottom Face
//	::glColor3f(0.0f, 1.0f, 1.0f);
	::glNormal3f( 0.0f,-1.0f, 0.0f);					// Normal Pointing Down
	::glTexCoord2f(0.0f, 0.0f); ::glVertex3f( -(size/2),  -(size/2),  -(size/2));				// Point 1 (Bottom)
	::glTexCoord2f(1.0f, 0.0f); ::glVertex3f( size/2,  -(size/2),  -(size/2));			// Point 2 (Bottom)
	::glTexCoord2f(1.0f, 1.0f); ::glVertex3f( size/2,  -(size/2),  size/2);		// Point 3 (Bottom)
	::glTexCoord2f(0.0f, 1.0f); ::glVertex3f( -(size/2),  -(size/2),  size/2);			// Point 4 (Bottom)
	// Right face
//	::glColor3f(0.0f, 0.0f, 1.0f);
	::glNormal3f( 1.0f, 0.0f, 0.0f);					// Normal Pointing Right
	::glTexCoord2f(1.0f, 0.0f); ::glVertex3f( size/2,  -(size/2),  -(size/2));			// Point 1 (Right)
	::glTexCoord2f(1.0f, 1.0f); ::glVertex3f( size/2,  size/2,  -(size/2));		// Point 2 (Right)
	::glTexCoord2f(0.0f, 1.0f); ::glVertex3f( size/2,  size/2,  size/2);	// Point 3 (Right)
	::glTexCoord2f(0.0f, 0.0f); ::glVertex3f( size/2,  -(size/2),  size/2);		// Point 4 (Right)
	// Left Face
//	::glColor3f(1.0f, 0.0f, 1.0f);
	::glNormal3f(-1.0f, 0.0f, 0.0f);					// Normal Pointing Left
	::glTexCoord2f(0.0f, 0.0f); ::glVertex3f( -(size/2),  -(size/2),  -(size/2));				// Point 1 (Left)
	::glTexCoord2f(1.0f, 0.0f); ::glVertex3f( -(size/2),  -(size/2),  size/2);			// Point 2 (Left)
	::glTexCoord2f(1.0f, 1.0f); ::glVertex3f( -(size/2),  size/2,  size/2);		// Point 3 (Left)
	::glTexCoord2f(0.0f, 1.0f); ::glVertex3f( -(size/2),  size/2,  -(size/2));	

	::glEnd();

	::glPopMatrix();
}