// Camera2D.cpp: implementation of the Camera2D class.
//
//////////////////////////////////////////////////////////////////////

#include "Camera2D.h"
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Camera2D::Camera2D()
{
	this->cameraType = CameraTypeFront;
}

Camera2D::~Camera2D()
{
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Camera2D::SetupCamera()
{
	this->pitch = 0.0f;
	this->roll = 0.0f;
	this->yaw = 0.0f;
	switch (this->cameraType)
	{
	case CameraTypeTop:
		{
			this->pitch = -90.0f;
			break;
		}

	case CameraTypeBottom:
		{
			this->pitch = 90.0f;
			break;
		}

	case CameraTypeLeft:
		{
			this->roll = 90.0f;
			break;
		}

	case CameraTypeRight:
		{
			this->roll = -90.0f;
			break;
		}
	}
	BuildViewmatrix();
	viewMatrix.MatrixTranspose();

	::glLoadMatrixf(viewMatrix.Get());
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Camera2D::MoveForward(float units)
{
	if (units != 0)
	{
		position.X += viewMatrix.At(0, 2) * (units / (50 / this->zoom));
		position.Y += viewMatrix.At(1, 2) * (units / (50 / this->zoom));
		position.Z += viewMatrix.At(2, 2) * (units / (50 / this->zoom));
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Camera2D::MoveRight(float units)
{
	if (units != 0)
	{
		position.X += viewMatrix.At(0, 0) * (units / (50 / this->zoom));
		position.Y += viewMatrix.At(1, 0) * (units / (50 / this->zoom));
		position.Z += viewMatrix.At(2, 0) * (units / (50 / this->zoom));
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Camera2D::MoveUp(float units)
{
	if (units != 0)
	{
		position.X += viewMatrix.At(0, 1) * (units / (50 / this->zoom));
		position.Y += viewMatrix.At(1, 1) * (units / (50 / this->zoom));
		position.Z += viewMatrix.At(2, 1) * (units / (50 / this->zoom));
	}
}
