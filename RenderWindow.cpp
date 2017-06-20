// RenderWindow.cpp: implementation of the RenderWindow class.
//
//////////////////////////////////////////////////////////////////////

#include "RenderWindow.h"
#include "Engine.h"
#include "ToolManager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

RenderWindow::RenderWindow()
{
	this->m_strClassName = "RenderWindow";
	this->m_dwStyle = WS_CHILD;
	this->m_dwExStyle = WS_EX_STATICEDGE;

	this->doc = NULL;
	this->renderArgs = NULL;
}

RenderWindow::~RenderWindow()
{
	if (this->renderArgs)
	{
		delete this->renderArgs;
		this->renderArgs = NULL;
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
RenderArgs* RenderWindow::InitRender(HWND parent, int id, Document* doc, ECameraType cameraType)
{
	CWCustomControl::Create(parent, id);

	HDC hDC = ::GetDC(this->m_hWnd);

	if (InitPixelformat(hDC) == S_OK)
	{
		if (HGLRC hRC = ::wglCreateContext(hDC))
		{
			if (::wglMakeCurrent(hDC, hRC))
			{
				if (this->renderArgs)
					delete this->renderArgs;

				this->renderArgs = new RenderArgs(this->m_hWnd, hDC, hRC, this->m_nWidth, this->m_nHeight);
				this->renderArgs->SetBgColor(0.0f, 0.3f, 0.5f);
				if (doc)
				{
					doc->AddRenderArgs(this->renderArgs);
					this->renderArgs->SetCameraType(cameraType);
					this->doc = doc;
				}
			}
		}
	}
	return this->renderArgs;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void RenderWindow::StopRender()
{
	if (this->renderArgs)
	{
		::wglMakeCurrent(NULL,NULL);

		::wglDeleteContext(this->renderArgs->RC());

		::ReleaseDC(this->m_hWnd, this->renderArgs->DC());
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
int RenderWindow::InitPixelformat(HDC hDC)
{
	PIXELFORMATDESCRIPTOR pfd;
	int format;

	ZeroMemory( &pfd, sizeof( pfd ) );
	pfd.nSize = sizeof( pfd );
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 24;
	pfd.cDepthBits = 16;
	pfd.iLayerType = PFD_MAIN_PLANE;

	if (format = ::ChoosePixelFormat(hDC, &pfd))
		if (::SetPixelFormat(hDC, format, &pfd))
			return S_OK;

	return S_FALSE;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
LRESULT RenderWindow::ViewProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		{
			break;
		}

	case WM_PAINT:
		{
			if (this->doc)
			{
				this->doc->Render(this->renderArgs);
				::ValidateRect(this->m_hWnd, NULL);
			}
			break;
		}

	case WM_SIZE:
		{			
			if (this->renderArgs)
			{
				this->renderArgs->SetSize(LOWORD(lParam), HIWORD(lParam));
				Engine::Use(this->renderArgs);
				Engine::Resize(this->renderArgs);
			}
			break;
		}

	case WM_DESTROY:
		{
			StopRender();
			break;
		}

	case WM_KEYDOWN:
		{
			this->renderArgs->KeysStatus()->KeyDown(wParam);
			break;
		}

	case WM_KEYUP:
		{
			this->renderArgs->KeysStatus()->KeyUp(wParam);
			break;
		}

	case WM_LBUTTONDOWN:
	case WM_RBUTTONDOWN:
	case WM_MBUTTONDOWN:
		{
			Focus();

			if (this->doc)
			{
				if (this->doc->IsCurrentArgs(this->renderArgs))
				{
					switch (uMsg)
					{
					case WM_LBUTTONDOWN:
						{
							ToolManager::Instance()->OnLDown(wParam, LOWORD(lParam), HIWORD(lParam));
							break;
						}
					case WM_RBUTTONDOWN:
						{
							ToolManager::Instance()->OnRDown(wParam, LOWORD(lParam), HIWORD(lParam));
							break;
						}
					case WM_MBUTTONDOWN:
						{
							ToolManager::Instance()->OnMDown(wParam, LOWORD(lParam), HIWORD(lParam));
							break;
						}
					}
				}
			}
			break;
		}

	case WM_LBUTTONUP:
	case WM_MBUTTONUP:
	case WM_RBUTTONUP:
		{
			if (this->doc)
			{
				if (this->doc->SetCurrentArgs(this->renderArgs))
				{
					switch (uMsg)
					{
					case WM_LBUTTONUP:
						{
							ToolManager::Instance()->OnLUp(wParam, LOWORD(lParam), HIWORD(lParam));
							break;
						}
					case WM_RBUTTONUP:
						{
							ToolManager::Instance()->OnRUp(wParam, LOWORD(lParam), HIWORD(lParam));
							break;
						}
					case WM_MBUTTONUP:
						{
							ToolManager::Instance()->OnMUp(wParam, LOWORD(lParam), HIWORD(lParam));
							break;
						}
					}
				}
			}
			break;
		}

	case WM_MOUSEMOVE:
		{
			if (this->doc)
			{
				if (this->doc->IsCurrentArgs(this->renderArgs))
				{
					ToolManager::Instance()->OnMouseMove(wParam, LOWORD(lParam), HIWORD(lParam));
				}
			}
			break;
		}
	}
	return CWCustomControl::ViewProc(uMsg, wParam, lParam);
}
