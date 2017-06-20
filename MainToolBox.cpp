// MainToolBox.cpp: implementation of the MainToolBox class.
//
//////////////////////////////////////////////////////////////////////

#include "MainToolBox.h"
#include "ToolManager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MainToolBox::MainToolBox()
{
	this->m_dwResource = IDD_MAIN;
}

MainToolBox::~MainToolBox()
{
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
LRESULT MainToolBox::ViewProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_COMMAND:
		{
			switch (wParam)
			{
			case IDC_SELECTION:
				{
					ToolManager::Instance()->SetCurrentTool("selection");
					break;
				}
			}
			break;
		}
	}

	return CWToolBox::ViewProc(uMsg, wParam, lParam);
}
