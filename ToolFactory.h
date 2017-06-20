// ToolFactory.h: interface for the ToolFactory class.
//
//////////////////////////////////////////////////////////////////////

#ifndef TOOLFACTORY_H
#define TOOLFACTORY_H

#include "Tool.h"
#include "SelectionTool.h"
#include "CameraTool.h"

class ToolFactory  
{
public:
	ToolFactory();
	virtual ~ToolFactory();

	static Tool* CreateTool(char* name);
};

#endif
