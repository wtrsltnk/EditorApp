// SelectObject.h: interface for the SelectObject class.
//
//////////////////////////////////////////////////////////////////////

#ifndef SELECTIONOBJECT_H
#define SELECTIONOBJECT_H

#include "RenderObject.h"
#include "SelectionArgs.h"

enum SelectionState
{
	Normal = 0,
	Selected,
	Hidden,
	Deleted
};

class SelectionObject : public RenderObject
{
public:		int selectionState;
public:		virtual void Select(SelectionArgs* args) = 0;
};

#endif