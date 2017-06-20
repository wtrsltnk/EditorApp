// RenderObject.h: interface for the RenderObject class.
//
//////////////////////////////////////////////////////////////////////

#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H

#include "RenderArgs.h"

class RenderObject
{
public:		virtual void Render(RenderArgs* args) = 0;
};

#endif