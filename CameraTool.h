// CameraTool.h: interface for the CameraTool class.
//
//////////////////////////////////////////////////////////////////////

#ifndef CAMERATOOL_H
#define CAMERATOOL_H

#include "Tool.h"
#include "CameraPropertieBox.h"

#define CAMERA_TOOL "camera"

#define SPEED 1.0f
#define SPEED_REDUCE 0.5f

class CameraTool : public Tool
{
private:
	int leftX;
	int leftY;
	int middleX;
	int middleY;
	int rightX;
	int rightY;
	bool leftDrag;
	bool middleDrag;
	bool rightDrag;

	CameraPropertieBox propertieBox;

public:
	CameraTool();
	virtual ~CameraTool();

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
