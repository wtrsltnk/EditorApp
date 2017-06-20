// Document.cpp: implementation of the Document class.
//
//////////////////////////////////////////////////////////////////////

#include "Document.h"
#include "Engine.h"
#include "ToolManager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Document::Document()
{
	this->currentArgs			 = -1;
	this->numRenderArgs			 = 0;
	this->renderArgs[0]			 = 0;
	this->selectionHandler		 = 0;
	this->workspace				 = 0;
}

Document::~Document()
{
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Document::SetWorkspace(Workspace* ws)
{
	this->workspace = ws;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
Workspace* Document::GetWorkspace()
{
	return this->workspace;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Document::SetSelectionHandler(SelectionHandler* h)
{
	this->selectionHandler		 = h;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
int Document::AddRenderArgs(RenderArgs* args)
{
	if (this->numRenderArgs < MAX_RENDERARGS)
	{
		this->renderArgs[this->numRenderArgs] = args;

		if (this->currentArgs == -1)
			this->currentArgs = this->numRenderArgs;

		return this->numRenderArgs++;
	}
	return -1;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
bool Document::SetCurrentArgs(RenderArgs* args)
{
	bool res = false;

	if (args)
	{
		for (int i = 0; i < this->numRenderArgs; i++)
		{
			if (this->renderArgs[i] == args)
			{
				if (this->currentArgs == i)
					res = true;

				int backup = this->currentArgs;

				this->currentArgs = i;

				if (backup >= 0)
					Render(this->renderArgs[backup]);
				
				RenderActive();
				
				return res;
			}
		}
	}

	return res;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
RenderArgs* Document::GetCurrentArgs()
{
	if (this->currentArgs >= 0)
	{
		return this->renderArgs[this->currentArgs];
	}

	return 0;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
bool Document::IsCurrentArgs(RenderArgs* args)
{
	if (args)
	{
		for (int i = 0; i < this->numRenderArgs; i++)
		{
			if (this->renderArgs[i] == args)
			{
				if (this->currentArgs == i)
					return true;
				else
					return false;
			}
		}
	}

	return false;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Document::SingleRender(RenderArgs* args, Workspace* ws)
{
	float color[4];

	if (args)
	{
		args->GetBgColor(color);

		Engine::PreRender(args);

		if (args->GetCameraType() == CameraTypePerspective)
			Engine::Goto3D(args);
		else
			Engine::Goto2D(args);

		Animate();

		args->SetupCamera();

		args->SetupLighting();

		::glCullFace(GL_BACK);
		::glDisable(GL_CULL_FACE);
		::glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		RenderWorkspace(args, ws);

		if (args->GetCameraType() == CameraTypePerspective)
			Engine::Leave3D(args);
		else
			Engine::Leave2D(args);

		RenderBorder(args);

		Engine::PostRender(args);
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Document::RenderBorder(RenderArgs* args)
{
	float borderWidth = 6.0f;

	if (args)
	{
		Engine::Goto2DFromArgs(args);

		if (IsCurrentArgs(args))
			::glColor4f(0.0f, 0.5f, 0.8f, 1.0f);
		else
			::glColor4f(0.0f, 0.3f, 0.5f, 1.0f);

		::glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		::glRectf(0.0f, 0.0f, (float)args->Width(), borderWidth);
		::glRectf((float)args->Width(), (float)args->Height(), 0.0f, (float)args->Height() - borderWidth);

		::glRectf(0.0f, 0.0f, borderWidth, (float)args->Height());
		::glRectf((float)args->Width(), (float)args->Height(), (float)args->Width() - borderWidth, 0.0f);

		Engine::Leave2DFromArgs(args);
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Document::RenderWorkspace(RenderArgs* args, Workspace* ws)
{
	if (ws && args)
	{
		if (Model* mdl = ws->GetCurrentModel())
		{
			for (int i = 0; i < mdl->GetMeshGroupCount(); i++)
			{
				if (MeshGroup* grp = mdl->GetMeshGroup(i))
				{
					if (Mesh* mesh = grp->GetCurrentMesh())
					{
						mesh->Render(args);
					}
				}
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Document::SelectWorkspace(SelectionArgs* args, Workspace* ws)
{
	if (ws && args)
	{
		if (Model* mdl = ws->GetCurrentModel())
		{
			for (int i = 0; i < mdl->GetMeshGroupCount(); i++)
			{
				if (MeshGroup* grp = mdl->GetMeshGroup(i))
				{
					if (Mesh* mesh = grp->GetCurrentMesh())
					{
						mesh->Select(args);
					}
				}
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Document::Render()
{
	for (int i = 0; i < this->numRenderArgs; i++)
	{
		SingleRender(this->renderArgs[i], this->workspace);
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Document::Render(RenderArgs* args)
{
	SingleRender(args, this->workspace);
}


//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Document::RenderActive()
{
	if (this->currentArgs > -1 && this->currentArgs < this->numRenderArgs)
	{
		ToolManager::Instance()->UpdateTool();
		
		SingleRender(this->renderArgs[this->currentArgs], this->workspace);
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Document::Select(int x, int y, int width, int height)
{
	if (this->workspace)
	{
		RenderArgs* args = this->renderArgs[this->currentArgs];

		if (args && this->selectionHandler)
		{
			if (args == this->renderArgs[this->currentArgs])
			{
				SelectionArgs s(args, this->selectionHandler, x, y, width, height);

				Engine::PreSelect(&s);

				if (args->GetCameraType() == CameraTypePerspective)
					Engine::Goto3D(args);
				else
					Engine::Goto2D(args);

				args->SetupCamera();

				SelectWorkspace(&s, this->workspace);

//				this->object->Select(&s);
				
				if (args->GetCameraType() == CameraTypePerspective)
					Engine::Leave3D(args);
				else
					Engine::Leave2D(args);

				Engine::PostSelect(&s);

				RenderActive();
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Document::Animate()
{
	if (this->workspace)
	{
		static float previousTick;
		float currentTick;

		currentTick = (float)GetTickCount() / 100.0f;
		this->workspace->GetCurrentModel()->AdvanceFrame((float)currentTick - previousTick);	// TODO : implement animationspeed				
		previousTick = currentTick;
	}
}