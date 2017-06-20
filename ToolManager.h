// ToolManager.h: interface for the ToolManager class.
//
//////////////////////////////////////////////////////////////////////

#ifndef TOOLMANAGER_H
#define TOOLMANAGER_H

#include "controls.h"
#include "Tool.h"
#include "Collection.h"

class ToolManager  
{
private:
	static ToolManager* instance;
public:
	static ToolManager* Instance();

private:
	int currentTool;
	Collection <Tool*> tools;
	Tool* cameraTool;
	bool cameraActive;

	CWToolBoxContainer* toolBoxContainer;
	ToolArgs* toolArgs;

private:
	ToolManager();
	virtual ~ToolManager();

	int GetToolIndex(char* tool);
	Tool* GetTool(char* tool);
	void UnloadCurrent();
public:
	void SetToolBoxContainer(CWToolBoxContainer* boxes);
	void SetArguments(ToolArgs* args);

	int AddTool(Tool* tool);
	Tool* SetCurrentTool(char* name);
	void ClearTools();
	void SetCameraTool(Tool* tool);
	Tool* GetCameraTool();
	
	void OnLDown(int keys, int x, int y);
	void OnLUp(int keys, int x, int y);
	void OnRDown(int keys, int x, int y);
	void OnRUp(int keys, int x, int y);
	void OnMDown(int keys, int x, int y);
	void OnMUp(int keys, int x, int y);
	void OnMouseMove(int keys, int x, int y);

	void UpdateTool();

};

#endif
