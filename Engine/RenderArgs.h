// RenderArgs.h: interface for the RenderArgs class.
//
//////////////////////////////////////////////////////////////////////

#ifndef RENDERARGS_H
#define RENDERARGS_H

#include "Camera.h"
#include "Keys.h"

class RenderArgs  
{
public:
	enum EPolygonMode
	{
		Point,
		Line,
		Fill
	};

private:
	HWND wnd;
	HDC dc;
	HGLRC rc;

	int witdh;
	int height;

	float fieldOfView;
	float nearClipping;
	float farClipping;

	EPolygonMode polygonMode;
	Camera* camera;
	Keys keys;

	float ambience[4];
	float diffuse1[4];
	float diffuse2[4];
	float position1[4];
	float position2[4];

	float bgColor[3];
	float fgColor[3];
public:
	RenderArgs(HWND wnd, HDC dc, HGLRC rc, int w, int h, float fov = 45.0f, float nc = 0.01f, float fc = 100.0f, EPolygonMode p = Fill);
	virtual ~RenderArgs();

	HDC DC();
	HGLRC RC();

	int Width();
	int Height();
	float Aspect();
	void SetSize(int w, int h);

	float FieldOfView();
	float NearClipping();
	float FarClipping();

	EPolygonMode PolygonMode();

	void SetBgColor(float color[]);
	void SetBgColor(float r, float g, float b);
	void GetBgColor(float color[]);
	void SetFgColor(float color[]);
	void SetFgColor(float r, float g, float b);
	void GetFgColor(float color[]);

	void SetCameraType(ECameraType type);
	ECameraType GetCameraType();

	void Capture();
	void ReleaseCapture();

	void SetupCamera();
	Camera* Camera();
	Keys* KeysStatus();

	void SetupLighting();
};

#endif