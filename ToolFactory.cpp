// ToolFactory.cpp: implementation of the ToolFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "ToolFactory.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ToolFactory::ToolFactory()
{
}

ToolFactory::~ToolFactory()
{
}

Tool* ToolFactory::CreateTool(char* name)
{
	if (strcmp(name, SELECTION_TOOL) == 0)
	{
		return new SelectionTool();
	}
	else if (strcmp(name, CAMERA_TOOL) == 0)
	{
		return new CameraTool();
	}
	return 0;
}