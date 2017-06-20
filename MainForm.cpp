// MainForm.cpp: implementation of the MainForm class.
//
//////////////////////////////////////////////////////////////////////

#include "MainForm.h"
#include "ToolFactory.h"

//////////////////////////////////////////////////////////////////////
// Winmain
//////////////////////////////////////////////////////////////////////

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MainForm app;

	if (!app.Init(hInstance))
	{
		::MessageBox(NULL, "Unable to create Form", "ERROR :", MB_OK | MB_ICONEXCLAMATION);
		return 0;
	}
	
	return app.Run();
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MainForm::MainForm()
{
	this->m_strWindowClass		 = "MainForm";
	this->m_dwExWindowStyle		 = WS_EX_WINDOWEDGE;
	this->m_hbrWindowColor		 = (HBRUSH)COLOR_WINDOW;
	this->m_dwCreationFlags		 = SW_SHOWMAXIMIZED;
	this->m_hIcon				 = LoadIcon(this->m_hInstance, MAKEINTRESOURCE(IDI_SNOWFLAKE));
	this->m_strWindowTitle		 = "3D editor";

	this->document				 = new Document();
	this->document->SetSelectionHandler(&handler);
	this->toolArgs				 = new ToolArgs(document);
	this->workspace				 = new Workspace("Wouter\'s Working area");
	this->workspace->AddModel(new Model("Model01"));
	if (Model* mdl = this->workspace->GetModel(0))
	{
/*		if (Skeleton* skt = mdl->GetSkeleton())
		{
			skt->AddBone(new Bone(2));
			skt->AddBone(new Bone(3, 2));
			skt->AddBone(new Bone(4, 2));
			skt->AddBone(new Bone(5, 3));
		}
*/
		mdl->AddMeshGroup(new MeshGroup("MeshGroup01"));
		if (MeshGroup* grp = mdl->GetMeshGroup(0))
		{
			grp->AddMesh(new Mesh("Mesh01"));
			grp->AddMesh(new Mesh("Mesh02"));
			grp->AddMesh(new Mesh("Mesh03"));

			grp->GetCurrentMesh()->AddPoint(0.0f, 0.0f, 0.0f);
			grp->GetCurrentMesh()->AddPoint(0.0f, 1.0f, 1.0f);
			grp->GetCurrentMesh()->AddPoint(0.0f, 1.0f, 0.0f);

			grp->GetCurrentMesh()->AddVertex(0);
			grp->GetCurrentMesh()->AddVertex(1);
			grp->GetCurrentMesh()->AddVertex(2);

			grp->GetCurrentMesh()->AddTriangle(0, 1, 2, 0);
			grp->GetCurrentMesh()->AddMaterial();
		}


		mdl->AddMeshGroup(new MeshGroup("MeshGroup02"));
		if (MeshGroup* grp = mdl->GetMeshGroup(1))
		{
			grp->AddMesh(new Mesh("Mesh01"));
			grp->AddMesh(new Mesh("Mesh02"));
			grp->AddMesh(new Mesh("Mesh03"));
		}

		mdl->AddSequence(new Sequence("Sequence01"));
		mdl->AddSequence(new Sequence("Sequence02"));
		mdl->AddSequence(new Sequence("Sequence03"));
		mdl->AddSequence(new Sequence("Sequence04"));
	}
	
	this->document->SetWorkspace(this->workspace);

	ToolManager::Instance()->SetArguments(this->toolArgs);
	ToolManager::Instance()->AddTool(ToolFactory::CreateTool(SELECTION_TOOL));
	ToolManager::Instance()->SetCameraTool(ToolFactory::CreateTool(CAMERA_TOOL));

	this->m_pMenu				 = new CWMenu();
	this->m_pBestand			 = new CWMenu("Bestand");
	this->m_pHelp				 = new CWMenu("Help");

	this->m_pBestand->AddItem("Open", ID_BESTAND_OPEN);
	this->m_pBestand->AddItem("Sluiten", ID_BESTAND_SLUITEN);
	
	this->m_pHelp->AddItem("About", ID_HELP_ABOUT);

	this->m_pMenu->AddSubMenu(this->m_pBestand);
	this->m_pMenu->AddSubMenu(this->m_pHelp);

}

MainForm::~MainForm()
{
	ToolManager::Instance()->ClearTools();
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
LRESULT MainForm::ViewProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		{
			this->renderWindow1.InitRender(this->m_hWnd, 1, this->document, CameraTypeTop);
			this->renderWindow2.InitRender(this->m_hWnd, 2, this->document, CameraTypeLeft);
			this->renderWindow3.InitRender(this->m_hWnd, 3, this->document, CameraTypeFront);
			this->renderWindow4.InitRender(this->m_hWnd, 4, this->document, CameraTypePerspective);

			this->animationTrackbar.SetExStyle(WS_EX_STATICEDGE);
			this->animationTrackbar.Create(this->m_hWnd, 45);
			this->animationTrackbar.SetRange(0, 36);

			this->propertieWindow.SetExStyle(WS_EX_STATICEDGE);
			this->propertieWindow.Create(this->m_hWnd, 5);

			ToolManager::Instance()->SetToolBoxContainer(&this->propertieWindow);

			this->mainToolBox = new MainToolBox();
			this->mainToolBox->Initialize(80, ID_MAINTOOLBOX);
			this->mainToolBox->SetTitle("Main Properties");

			this->workspaceToolBox = new WorkspaceToolBox();
			this->workspaceToolBox->Initialize(320, ID_WORKSPACETOOLBOX);
			this->workspaceToolBox->SetTitle("Workspace");
			this->workspaceToolBox->SetDocument(this->document);

			this->propertieWindow.AddToolBox(this->mainToolBox);
			this->propertieWindow.AddToolBox(this->workspaceToolBox);
			ToolManager::Instance()->SetCurrentTool(SELECTION_TOOL);

			::SetTimer(this->m_hWnd, ID_RENDER_TIMER, 40, NULL);
			break;
		}

	case WM_ACTIVATE:
		{
			WORD fActive = LOWORD(wParam);

			switch (fActive)
			{
			case WA_ACTIVE:
				{
					::SetTimer(this->m_hWnd, ID_RENDER_TIMER, 40, NULL);
					break;
				}
			case WA_CLICKACTIVE:
				{
					::SetTimer(this->m_hWnd, ID_RENDER_TIMER, 40, NULL);
					break;
				}
			case WA_INACTIVE:
				{
					::KillTimer(this->m_hWnd, ID_RENDER_TIMER);
					break;
				}
			}
			break;
		}

	case WM_SIZE:
		{
			int width = LOWORD(lParam) - 182;
			int height = HIWORD(lParam) - 40;

			this->renderWindow1.Resize(2, 2, (width/2)-4, (height/2)-4);
			this->renderWindow2.Resize((width/2)+2, 2, (width/2)-4, (height/2)-4);
			this->renderWindow3.Resize(2, (height/2)+2, (width/2)-4, (height/2)-4);
			this->renderWindow4.Resize((width/2)+2, (height/2)+2, (width/2)-4, (height/2)-4);

			this->propertieWindow.Resize(width, 2, 180, height+36);

			this->animationTrackbar.Resize(2, height, width-4, 38);
			break;
		}

	case WM_TIMER:
		{
			switch (wParam)
			{
			case ID_RENDER_TIMER:
				{
					this->document->RenderActive();
					break;
				}
			}
			break;
		}

	case WM_COMMAND:
		{
			switch (wParam)
			{
			case ID_BESTAND_OPEN:
				{
					this->document->Render();
					break;
				}

			case ID_BESTAND_SLUITEN:
				{
					this->document->Render();
					break;
				}

			case ID_HELP_ABOUT:
				{
					break;
				}
			}
			break;
		}
	}
	return CWBaseApp::ViewProc(uMsg, wParam, lParam);
}

void MainForm::InitPropertieWindow()
{
	this->propertieWindow.ClearToolBoxes();
}