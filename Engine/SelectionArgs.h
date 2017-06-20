// SelectionArgs.h: interface for the SelectionArgs class.
//
//////////////////////////////////////////////////////////////////////

#ifndef SELECTIONARGS_H
#define SELECTIONARGS_H

#include "RenderArgs.h"
#include "SelectionHandler.h"

#define MAX_BUFFER 512

class SelectionArgs  
{
private:
	RenderArgs* renderArgs;
	unsigned int selectionBuffer[MAX_BUFFER];

	int x;
	int y;
	int width;
	int height;

	SelectionHandler* selectionHandler;

public:
	SelectionArgs(RenderArgs* args, SelectionHandler* handler, int x, int y, int w = 1, int h = 1);
	virtual ~SelectionArgs();

	RenderArgs* RenderArguments();

	unsigned int *SelectionBuffer();
	int BufferSize();

	int X();
	int Y();
	int Width();
	int Height();

	int GatherHits();

};

#endif