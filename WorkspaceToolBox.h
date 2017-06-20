// WorkspaceToolBox.h: interface for the WorkspaceToolBox class.
//
//////////////////////////////////////////////////////////////////////

#ifndef WORKSPACETOOLBOX_H
#define WORKSPACETOOLBOX_H

#include "controls.h"
#include "resource.h"
#include "Document.h"

#define ID_ADD_MODEL			8760
#define ID_ADD_MESHGROUP		8761
#define ID_ADD_SEQUENCE			8762
#define ID_ADD_MESH				8763

enum ItemTypes
{
	eTitle = 0,
	eWorkspace,
	eModel,
	eSkeleton,
	eMeshGroup,
	eSequence,
	eMesh
};

class WorkspaceToolBox : public CWToolBox
{
private:
	Document* document;
	CWTreeView* view;
	CWPopUpMenu workspaceMenu;
	CWPopUpMenu modelMenu;
	CWPopUpMenu meshgroupMenu;
	CWPopUpMenu sequenceMenu;
	CWPopUpMenu meshMenu;

	LRESULT ViewProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
	CWPopUpMenu* GetMenu();
	void InitView();

public:
	WorkspaceToolBox();
	virtual ~WorkspaceToolBox();

	void SetDocument(Document* document);
};

#endif
