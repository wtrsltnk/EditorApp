// Camera2D.h: interface for the Camera2D class.
//
//////////////////////////////////////////////////////////////////////

#ifndef CAMERA2D_H
#define CAMERA2D_H

#include "Camera.h"

class Camera2D : public Camera
{
public:
	Camera2D();
	virtual ~Camera2D();

	void MoveForward(float units);
	void MoveRight(float units);
	void MoveUp(float units);

	void SetupCamera();
};

#endif
