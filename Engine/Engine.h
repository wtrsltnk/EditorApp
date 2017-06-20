// Engine.h: interface for the Engine class.
//
//////////////////////////////////////////////////////////////////////

#ifndef ENGINE_H
#define ENGINE_H

#include "RenderArgs.h"
#include "SelectionArgs.h"

class Engine  
{
public:
	static void Use(RenderArgs* args);
	static void PreRender(RenderArgs* args);
	static void PostRender(RenderArgs* args);
	static void Resize(RenderArgs* args);

	static void PreSelect(SelectionArgs* args);
	static void PostSelect(SelectionArgs* args);

	static void Goto2D(RenderArgs* args);
	static void Leave2D(RenderArgs* args);

	static void Goto2DFromArgs(RenderArgs* args);
	static void Leave2DFromArgs(RenderArgs* args);

	static void Goto3D(RenderArgs* args);
	static void Leave3D(RenderArgs* args);

	static int AddFont(RenderArgs* args, char* fontface, int size);
	static void RenderText(RenderArgs* args, int x, int y, int font, const char *format, ...);




	static void RenderCube(float size, float position[]);
};

#endif