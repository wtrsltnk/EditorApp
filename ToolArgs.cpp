// ToolArgs.cpp: implementation of the ToolArgs class.
//
//////////////////////////////////////////////////////////////////////

#include "ToolArgs.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ToolArgs::ToolArgs(Document* d)
{
	this->document = d;
}

ToolArgs::~ToolArgs()
{
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
Document* ToolArgs::Doc()
{
	return this->document;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
Collection <CWToolBox*> *ToolArgs::Views()
{
	return &this->propertieViews;
}