// RenderWindow.h: interface for the RenderWindow class.
//
//////////////////////////////////////////////////////////////////////

#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

#include "controls.h"
#include "RenderArgs.h"
#include "SelectionArgs.h"
#include "SelectionHandler.h"
#include "Document.h"

class RenderWindow : public CWCustomControl
{
private:
	RenderArgs* renderArgs;
	SelectionHandler handler;
	Document* doc;

	int InitPixelformat(HDC hDC);

public:
	RenderWindow();
	virtual ~RenderWindow();

	LRESULT ViewProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

	RenderArgs* InitRender(HWND parent, int id, Document* doc, ECameraType cameraType);
	void StopRender();

};

#endif
