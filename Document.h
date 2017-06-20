// Document.h: interface for the Document class.
//
//////////////////////////////////////////////////////////////////////

#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "RenderArgs.h"
#include "RenderObject.h"
#include "SelectionObject.h"
#include "SelectionArgs.h"
#include "SelectionHandler.h"
#include "AnimationObject.h"
#include "Workspace.h"

#define MAX_RENDERARGS 4

class Document  
{
private:
	int currentArgs;
	int numRenderArgs;
	RenderArgs* renderArgs[MAX_RENDERARGS];
	Workspace* workspace;
	SelectionHandler* selectionHandler;

	void SingleRender(RenderArgs* args, Workspace* ws);
	void RenderBorder(RenderArgs* args);
	void RenderWorkspace(RenderArgs* args, Workspace* ws);
	void SelectWorkspace(SelectionArgs* args, Workspace* ws);
public:
	Document();
	virtual ~Document();

	void SetWorkspace(Workspace* ws);
	Workspace* GetWorkspace();
	void SetSelectionHandler(SelectionHandler* h);

	int AddRenderArgs(RenderArgs* args);
	bool SetCurrentArgs(RenderArgs* args);
	RenderArgs* GetCurrentArgs();
	bool IsCurrentArgs(RenderArgs* args);

	void Render();
	void Render(RenderArgs* args);
	void RenderActive();
	void Select(int x, int y, int width, int height);
	void Animate();
};

#endif

