// CameraTool.cpp: implementation of the CameraTool class.
//
//////////////////////////////////////////////////////////////////////

#include "CameraTool.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CameraTool::CameraTool()
{
	this->toolArgs = 0;
	this->propertieBox.Initialize(70, 7889);
	this->leftDrag = false;
	this->middleDrag = false;
	this->rightDrag = false;
}

CameraTool::~CameraTool()
{
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void CameraTool::OnLDown(int keys, int x, int y)
{
	if (this->toolArgs)
	{
		POINT mousePos;
		GetCursorPos(&mousePos);

		this->leftX = mousePos.x;
		this->leftY = mousePos.y;

		this->leftDrag = true;
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void CameraTool::OnLUp(int keys, int x, int y)
{
	if (this->toolArgs)
	{
		this->leftDrag = false;
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void CameraTool::OnRDown(int keys, int x, int y)
{
	POINT mousePos;
	GetCursorPos(&mousePos);

	this->rightX = mousePos.x;
	this->rightY = mousePos.y;

	this->rightDrag = true;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void CameraTool::OnRUp(int keys, int x, int y)
{
	this->rightDrag = false;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void CameraTool::OnMDown(int keys, int x, int y)
{
	POINT mousePos;
	GetCursorPos(&mousePos);

	this->middleX = mousePos.x;
	this->middleY = mousePos.y;

	this->middleDrag = true;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void CameraTool::OnMUp(int keys, int x, int y)
{
	this->middleDrag = false;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void CameraTool::OnMouseMove(int keys, int x, int y)
{
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void CameraTool::UpdateTool()
{
	float pos[3];

	if (this->toolArgs)
	{
		Camera* cam = this->toolArgs->Doc()->GetCurrentArgs()->Camera();
		Keys* keys = this->toolArgs->Doc()->GetCurrentArgs()->KeysStatus();

		if (cam && keys)
		{
			if (cam->GetCameraType() == CameraTypePerspective)
			{
				cam->GetPosition(pos);
				this->propertieBox.ShowCameraPosition(pos);

				cam->CalculateFrameInterval();

				if (keys->IsKey('W'))
					cam->MoveForward(cam->GetFrameInterval() * SPEED);
				else if (keys->IsKey('S'))
					cam->MoveForward(cam->GetFrameInterval() * -SPEED);
				else
					cam->MoveForward(0.0f);

				if (keys->IsKey('A'))
					cam->MoveRight(cam->GetFrameInterval() * SPEED);
				else if (keys->IsKey('D'))
					cam->MoveRight(cam->GetFrameInterval() * -SPEED);
				else
					cam->MoveRight(0.0f);

				if (this->leftDrag && !this->middleDrag)
				{
					POINT mousePos;
					GetCursorPos(&mousePos);

					if( (mousePos.x != leftX) || (mousePos.y != leftY) )
					{
						SetCursorPos(leftX, leftY);

						cam->Roll(mousePos.x - leftX);
						cam->Pitch(mousePos.y - leftY);
					}
				}
				else if (this->middleDrag && !this->leftDrag)
				{
					POINT mousePos;
					GetCursorPos(&mousePos);

					if( (mousePos.x != middleX) || (mousePos.y != middleY) )
					{
						SetCursorPos(middleX, middleY);

						cam->MoveRight((float)(mousePos.x - middleX) / 4);
						cam->MoveUp(-(float)(mousePos.y - middleY) / 4);
					}
				}
			}
			else
			{
				if (this->leftDrag && !this->middleDrag)
				{
					POINT mousePos;
					GetCursorPos(&mousePos);

					if( (mousePos.x != leftX) || (mousePos.y != leftY) )
					{
						SetCursorPos(leftX, leftY);

						cam->Zoom((float)(mousePos.y - leftY) / 10);
					}
				}
				else if (this->middleDrag && !this->leftDrag)
				{
					POINT mousePos;
					GetCursorPos(&mousePos);

					if( (mousePos.x != middleX) || (mousePos.y != middleY) )
					{
						SetCursorPos(middleX, middleY);

						cam->MoveRight((float)(mousePos.x - middleX) / 20);
						cam->MoveUp(-(float)(mousePos.y - middleY) / 20);
					}
				}
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
bool CameraTool::Load(ToolArgs* args)
{
	this->toolArgs = args;
	if (this->toolArgs)
	{
		this->toolArgs->Views()->Add(&this->propertieBox);
	}
	return true;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
bool CameraTool::Unload()
{
	this->toolArgs = 0;
	return true;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
const char* CameraTool::GetName()
{
	return CAMERA_TOOL;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
CWToolBox* CameraTool::GetPropertieBox()
{
	return &this->propertieBox;
}
