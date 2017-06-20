// SelectionTool.h: interface for the SelectionTool class.
//
//////////////////////////////////////////////////////////////////////

#ifndef SELECTIONTOOL_H
#define SELECTIONTOOL_H

#include "Tool.h"
#include "SelectionPropertieBox.h"

#define SELECTION_TOOL "selection"

class SelectionTool : public Tool
{
private:
	SelectionPropertieBox propertieBox;
public:
	SelectionTool();
	virtual ~SelectionTool();

	void OnLDown(int keys, int x, int y);
	void OnLUp(int keys, int x, int y);
	void OnRDown(int keys, int x, int y);
	void OnRUp(int keys, int x, int y);
	void OnMDown(int keys, int x, int y);
	void OnMUp(int keys, int x, int y);
	void OnMouseMove(int keys, int x, int y);

	void UpdateTool();

	bool Load(ToolArgs* args);
	bool Unload();
	char* GetName();
	CWToolBox* GetPropertieBox();
};

#endif
