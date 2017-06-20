// ToolManager.cpp: implementation of the ToolManager class.
//
//////////////////////////////////////////////////////////////////////

#include "ToolManager.h"

//////////////////////////////////////////////////////////////////////
// Statics
//////////////////////////////////////////////////////////////////////

ToolManager* ToolManager::instance = 0;

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
ToolManager* ToolManager::Instance()
{
	if (ToolManager::instance == 0)
	{
		ToolManager::instance = new ToolManager();
	}

	return ToolManager::instance;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ToolManager::ToolManager()
{
	this->currentTool = -1;
	this->toolArgs = 0;
	this->toolBoxContainer = 0;
	this->cameraActive = false;
}

ToolManager::~ToolManager()
{
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
int ToolManager::GetToolIndex(const char* tool)
{
	for (int i = 0; i < this->tools.Size(); i++)
	{
        const char* name = this->tools.Get(i)->GetName();
		if (strcmp(name, tool) ==0)
		{
			return i;
		}
	}
	return -1;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
Tool* ToolManager::GetTool(const char* tool)
{
	int index = GetToolIndex(tool);
	
	if (index >= 0)
	{
		return this->tools.Get(index);
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void ToolManager::UnloadCurrent()
{	
	if (Tool* curr = this->tools.Get(this->currentTool))
		curr->Unload();
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void ToolManager::SetToolBoxContainer(CWToolBoxContainer* boxes)
{
	this->toolBoxContainer = boxes;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void ToolManager::SetArguments(ToolArgs* args)
{
	this->toolArgs = args;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
int ToolManager::AddTool(Tool* tool)
{
	int res = -1;

	this->tools.Add(tool);

	return res;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
Tool* ToolManager::SetCurrentTool(const char* name)
{
	Tool* tool = GetTool(name);
	if (this->toolArgs && this->toolBoxContainer && tool)
	{
		Collection <CWToolBox*> *views = this->toolArgs->Views();
		
		for (int i = 0; i < views->Size(); i++)
		{
			int id = views->Get(i)->GetID();
			this->toolBoxContainer->RemoveToolBox(id);
		}
		
		this->toolArgs->Views()->Clear();

		UnloadCurrent();

		this->currentTool = GetToolIndex(name);

		this->cameraTool->Load(this->toolArgs);
		tool->Load(this->toolArgs);

		for (int k = 0; k < views->Size(); k++)
		{
			this->toolBoxContainer->AddToolBox((CWToolBox*)views->Get(k));
		}
	}

	return tool;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void ToolManager::ClearTools()
{
	for (int i = 0; i < this->tools.Size(); i++)
	{
		Tool* tl = this->tools.Get(i);
		delete tl;
	}
	this->tools.Clear();
	this->currentTool = -1;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void ToolManager::SetCameraTool(Tool* tool)
{
	this->cameraTool = tool;
	if (this->cameraTool)
	{
		this->cameraTool->Load(this->toolArgs);
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
Tool* ToolManager::GetCameraTool()
{
	return this->cameraTool;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void ToolManager::OnLDown(int keys, int x, int y)
{
	if (this->currentTool >= 0 && this->currentTool < this->tools.Size())
	{
		if (keys & MK_CONTROL)
		{
			if (this->cameraTool)
			{
				this->cameraActive = true;
				this->cameraTool->OnLDown(keys, x, y);
			}
		}
		else
		{
			this->cameraActive = false;
			Tool* current = this->tools.Get(this->currentTool);
			if (current)
			{
				current->OnLDown(keys, x, y);
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void ToolManager::OnLUp(int keys, int x, int y)
{
	if (this->currentTool >= 0 && this->currentTool < this->tools.Size())
	{
		if (keys & MK_CONTROL && this->cameraActive)
		{
			if (this->cameraTool)
			{
				this->cameraActive = false;
				this->cameraTool->OnLUp(keys, x, y);
			}
		}
		else
		{
			this->cameraActive = false;
			Tool* current = this->tools.Get(this->currentTool);
			if (current)
			{
				current->OnLUp(keys, x, y);
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void ToolManager::OnRDown(int keys, int x, int y)
{
	if (this->currentTool >= 0 && this->currentTool < this->tools.Size())
	{
		if (keys & MK_CONTROL)
		{
			if (this->cameraTool)
			{
				this->cameraActive = true;
				this->cameraTool->OnRDown(keys, x, y);
			}
		}
		else
		{
			Tool* current = this->tools.Get(this->currentTool);
			if (current)
			{
				current->OnRDown(keys, x, y);
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void ToolManager::OnRUp(int keys, int x, int y)
{
	if (this->currentTool >= 0 && this->currentTool < this->tools.Size())
	{
		if (keys & MK_CONTROL)
		{
			if (this->cameraTool)
			{
				this->cameraActive = true;
				this->cameraTool->OnRUp(keys, x, y);
			}
		}
		else
		{
			Tool* current = this->tools.Get(this->currentTool);
			if (current)
			{
				current->OnRUp(keys, x, y);
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void ToolManager::OnMDown(int keys, int x, int y)
{
	if (this->currentTool >= 0 && this->currentTool < this->tools.Size())
	{
		if (keys & MK_CONTROL)
		{
			if (this->cameraTool)
			{
				this->cameraActive = true;
				this->cameraTool->OnMDown(keys, x, y);
			}
		}
		else
		{
			Tool* current = this->tools.Get(this->currentTool);
			if (current)
			{
				current->OnMDown(keys, x, y);
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void ToolManager::OnMUp(int keys, int x, int y)
{
	if (this->currentTool >= 0 && this->currentTool < this->tools.Size())
	{
		if (keys & MK_CONTROL)
		{
			if (this->cameraTool)
			{
				this->cameraActive = true;
				this->cameraTool->OnMUp(keys, x, y);
			}
		}
		else
		{
			Tool* current = this->tools.Get(this->currentTool);
			if (current)
			{
				current->OnMUp(keys, x, y);
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void ToolManager::OnMouseMove(int keys, int x, int y)
{
	if (this->currentTool >= 0 && this->currentTool < this->tools.Size())
	{
		if (keys & MK_CONTROL && this->cameraActive)
		{
			if (this->cameraTool)
			{
				this->cameraTool->OnMouseMove(keys, x, y);
			}
		}
		else
		{
			this->cameraActive = false;
			Tool* current = this->tools.Get(this->currentTool);
			if (current)
			{
				current->OnMouseMove(keys, x, y);
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void ToolManager::UpdateTool()
{
	if (this->currentTool >= 0 && this->currentTool < this->tools.Size())
	{
		if (this->toolArgs->Doc()->GetCurrentArgs()->KeysStatus()->IsKey(VK_CONTROL))
		{
			if (this->cameraTool)
			{
				this->cameraTool->UpdateTool();
			}
		}
		else
		{
			Tool* current = this->tools.Get(this->currentTool);
			if (current)
			{
				this->cameraActive = false;
				current->UpdateTool();
			}
		}
	}
}
