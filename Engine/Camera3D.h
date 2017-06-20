// Camera3D.h: interface for the Camera3D class.
//
//////////////////////////////////////////////////////////////////////

#ifndef CAMERA3D_H
#define CAMERA3D_H

#include "Camera.h"

class Camera3D : public Camera
{
public:
	Camera3D();
	virtual ~Camera3D();

	void SetupCamera();
};

#endif
