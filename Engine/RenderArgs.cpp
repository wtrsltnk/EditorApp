// RenderArgs.cpp: implementation of the RenderArgs class.
//
//////////////////////////////////////////////////////////////////////

#include "RenderArgs.h"
#include "Camera3D.h"
#include "Camera2D.h"

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

RenderArgs::RenderArgs(HWND wnd, HDC dc, HGLRC rc, int w, int h, float fov, float nc, float fc, EPolygonMode p)
{
	if (h <= 0)
		h = 1;

	if (w <= 0)
		w = 1;

	if (nc < 0)
		nc = 0.01f;

	this->wnd = wnd;
	this->dc = dc;
	this->rc = rc;
	
	this->witdh = w;
	this->height = h;

	this->fieldOfView = fov;
	this->nearClipping = nc;
	this->farClipping = fc;

	this->polygonMode = p;
	this->camera = 0;

	this->bgColor[0] = 0.0f;
	this->bgColor[1] = 0.0f;
	this->bgColor[2] = 0.0f;

	this->fgColor[0] = 0.0f;
	this->fgColor[1] = 1.0f;
	this->fgColor[2] = 0.0f;

	this->ambience[0] = 0.3f;
	this->ambience[1] = 0.3f;
	this->ambience[2] = 0.3f;
	this->ambience[3] = 0.1f;

	this->diffuse1[0] = 0.005f;
	this->diffuse1[1] = 0.005f;
	this->diffuse1[2] = 0.005f;
	this->diffuse1[3] = 0.1f;

	this->diffuse2[0] = 0.01f;
	this->diffuse2[1] = 0.01f;
	this->diffuse2[2] = 0.01f;
	this->diffuse2[3] = 0.1f;

	this->position1[1] = -1000.0f;
	this->position1[2] = -1000.0f;
	this->position1[0] = 0.0f;
	this->position1[3] = 1.0f;

	this->position2[2] = 1000.0f;
	this->position2[1] = 1000.0f;
	this->position2[0] = 0.0f;
	this->position1[3] = 1.0f;

}

RenderArgs::~RenderArgs()
{
	if (this->camera)
	{
		delete this->camera;
		this->camera = 0;
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
HDC RenderArgs::DC()
{
	return this->dc;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
HGLRC RenderArgs::RC()
{
	return this->rc;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
int RenderArgs::Width()
{
	return this->witdh;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
int RenderArgs::Height()
{
	return this->height;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
float RenderArgs::Aspect()
{
	return (float) this->witdh / this->height;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void RenderArgs::SetSize(int w, int h)
{
	this->witdh = w;
	this->height = h;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
float RenderArgs::FieldOfView()
{
	return this->fieldOfView;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
float RenderArgs::NearClipping()
{
	return this->nearClipping;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
float RenderArgs::FarClipping()
{
	return this->farClipping;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
RenderArgs::EPolygonMode RenderArgs::PolygonMode()
{
	return this->polygonMode;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void RenderArgs::SetBgColor(float color[])
{
	for (int i = 0; i < 3; i++)
	{
		if (color[i] >= 0.0f && color[i] <= 1.0f)
			this->bgColor[i] = color[i];
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void RenderArgs::SetBgColor(float r, float g, float b)
{
	if (r >= 0.0f && r <= 1.0f)
		this->bgColor[0] = r;
	
	if (g >= 0.0f && g <= 1.0f)
		this->bgColor[1] = g;

	if (b >= 0.0f && b <= 1.0f)
		this->bgColor[2] = b;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void RenderArgs::GetBgColor(float color[])
{
	for (int i = 0; i < 3; i++)
	{
		color[i] = this->bgColor[i];
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void RenderArgs::SetFgColor(float color[])
{
	for (int i = 0; i < 3; i++)
	{
		if (color[i] >= 0.0f && color[i] <= 1.0f)
			this->fgColor[i] = color[i];
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void RenderArgs::GetFgColor(float color[])
{
	for (int i = 0; i < 3; i++)
	{
		color[i] = this->fgColor[i];
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void RenderArgs::SetFgColor(float r, float g, float b)
{
	if (r >= 0.0f && r <= 1.0f)
		this->fgColor[0] = r;
	
	if (g >= 0.0f && g <= 1.0f)
		this->fgColor[1] = g;

	if (b >= 0.0f && b <= 1.0f)
		this->fgColor[2] = b;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void RenderArgs::SetCameraType(ECameraType type)
{
	if (this->camera)
	{
		if (type == CameraTypePerspective && this->camera->GetCameraType() != CameraTypePerspective)
		{
			delete this->camera;
			this->camera = new Camera3D();
		}
		else if (type != CameraTypePerspective && this->camera->GetCameraType() == CameraTypePerspective)
		{
			delete this->camera;
			this->camera = new Camera2D();		// TODO : Camera2D implementeren
		}
	}
	else
	{
		if (type == CameraTypePerspective)
		{
			this->camera = new Camera3D();
		}
		else
		{
			this->camera = new Camera2D();		// TODO : Camera2D implementeren
		}
	}
	this->camera->SetCameraType(type);
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
ECameraType RenderArgs::GetCameraType()
{
	if (!this->camera)
	{
		this->camera = new Camera3D();
	}
	
	return this->camera->GetCameraType();
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void RenderArgs::Capture()
{
	::SetCapture(this->wnd);
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void RenderArgs::ReleaseCapture()
{
	::ReleaseCapture();
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void RenderArgs::SetupCamera()
{
	if (this->camera)
	{
		this->camera->SetupCamera();
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
Camera* RenderArgs::Camera()
{
	//if (!this->camera)
	//	this->camera = new Camera3D();

	return this->camera;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
Keys* RenderArgs::KeysStatus()
{
	return &this->keys;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void RenderArgs::SetupLighting()
{
	glLightfv(GL_LIGHT0, GL_AMBIENT,  this->ambience);
	glLightfv(GL_LIGHT0, GL_DIFFUSE,  this->diffuse1);
	glLightfv(GL_LIGHT0, GL_POSITION, this->position1);

	glLightfv(GL_LIGHT1, GL_AMBIENT,  this->ambience);
	glLightfv(GL_LIGHT1, GL_DIFFUSE,  this->diffuse2);
	glLightfv(GL_LIGHT1, GL_POSITION, this->position2);

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);

	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);


}