// Tool.h: interface for the Tool class.
//
//////////////////////////////////////////////////////////////////////

#ifndef TOOL_H
#define TOOL_H

#include "controls.h"
#include "ToolArgs.h"

#define TOOL "tool"

class Tool  
{
protected:
	ToolArgs* toolArgs;

public:

	virtual void OnLDown(int keys, int x, int y) = 0;
	virtual void OnLUp(int keys, int x, int y) = 0;
	virtual void OnRDown(int keys, int x, int y) = 0;
	virtual void OnRUp(int keys, int x, int y) = 0;
	virtual void OnMDown(int keys, int x, int y) = 0;
	virtual void OnMUp(int keys, int x, int y) = 0;
	virtual void OnMouseMove(int keys, int x, int y) = 0;

	virtual void UpdateTool() = 0;

	virtual bool Load(ToolArgs* args) = 0;
	virtual bool Unload() = 0;
    virtual const char* GetName() = 0;
	virtual CWToolBox* GetPropertieBox() = 0;
};

#endif
