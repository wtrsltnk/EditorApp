// CameraPropertieBox.cpp: implementation of the CameraPropertieBox class.
//
//////////////////////////////////////////////////////////////////////

#include "CameraPropertieBox.h"
#include "resource.h"
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CameraPropertieBox::CameraPropertieBox()
{
	this->m_strClassName = "CameraPropertieBox";
	this->m_strTitle = "Camera Properties";
	this->m_dwResource = IDD_CAMERA;
}

CameraPropertieBox::~CameraPropertieBox()
{
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void CameraPropertieBox::ShowCameraPosition(float pos[3])
{
	char buffer[64];
	sprintf(buffer, "%3.3f", pos[0]);
	this->m_Dialog.SetItemText(IDC_POS_X, buffer);
	sprintf(buffer, "%3.3f", pos[1]);
	this->m_Dialog.SetItemText(IDC_POS_Y, buffer);
	sprintf(buffer, "%3.3f", pos[2]);
	this->m_Dialog.SetItemText(IDC_POS_Z, buffer);
}