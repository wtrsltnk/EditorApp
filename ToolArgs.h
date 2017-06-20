// ToolArgs.h: interface for the ToolArgs class.
//
//////////////////////////////////////////////////////////////////////

#ifndef TOOLARGS_H
#define TOOLARGS_H

#include "Document.h"
#include "Collection.h"
#include "controls.h"

class ToolArgs  
{
private:
	Document* document;
	Collection <CWToolBox*> propertieViews;

public:
	ToolArgs(Document* d);
	virtual ~ToolArgs();

	Document* Doc();
	Collection <CWToolBox*> *Views();

};

#endif
