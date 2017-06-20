// Camera.h: interface for the Camera class.
//
//////////////////////////////////////////////////////////////////////

#ifndef CAMERA_H
#define CAMERA_H

#include "MathLib.h"

enum ECameraType
{
	CameraTypeNone,
	CameraTypePerspective,
	CameraTypeFront,
	CameraTypeBack,
	CameraTypeTop,
	CameraTypeBottom,
	CameraTypeLeft,
	CameraTypeRight
};

class Camera
{
protected:
	Matrix viewMatrix;
	Vector position;

	float zoom;

	float pitch;
	float roll;
	float yaw;

	ECameraType cameraType;
	float frameInterval;

	void BuildViewmatrix();

public:
	Camera();
	virtual ~Camera();

	void CalculateFrameInterval();
	float GetFrameInterval();

	void SetCameraType(ECameraType type);
	ECameraType GetCameraType();
	
	void Reset();

	void MoveForward(float units);
	void MoveRight(float units);
	void MoveUp(float units);

	void MoveX(float units);
	void MoveY(float units);
	void MoveZ(float units);

	void Zoom(float amount);

	void Pitch(float degrees);
	void Roll(float degrees);
	void Yaw(float degrees);

	void GetPosition(float pos[]);
	float GetZoom();

	virtual void SetupCamera() = 0;
};

#endif
