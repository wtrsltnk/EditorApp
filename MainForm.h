// MainForm.h: interface for the MainForm class.
//
//////////////////////////////////////////////////////////////////////

#ifndef MAINFORM_H
#define MAINFORM_H

#include "controls.h"
#include "RenderWindow.h"
#include "Document.h"
#include "SelectionHandler.h"
#include "ToolManager.h"
#include "MainToolBox.h"
#include "Workspace.h"
#include "WorkspaceToolBox.h"
#include "resource.h"

#define ID_RENDER_TIMER 3543425

#define ID_BESTAND_OPEN 3653456
#define ID_BESTAND_SLUITEN 3653457

#define ID_HELP_ABOUT 3653556

#define ID_MAINTOOLBOX 87654
#define ID_WORKSPACETOOLBOX 87655

class MainForm : public CWBaseApp
{
private:
	RenderWindow renderWindow1;
	RenderWindow renderWindow2;
	RenderWindow renderWindow3;
	RenderWindow renderWindow4;
	CWTrackbar animationTrackbar;

	CWToolBoxContainer propertieWindow;
	Workspace* workspace;
	SelectionHandler handler;

	Document* document;
	ToolArgs* toolArgs;
	MainToolBox* mainToolBox;
	WorkspaceToolBox* workspaceToolBox;

	CWMenu* m_pBestand;
	CWMenu* m_pHelp;

	void InitPropertieWindow();
public:
    MainForm(HINSTANCE hInstance);
	virtual ~MainForm();

	LRESULT ViewProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

};

#endif
