// CameraPropertieBox.h: interface for the CameraPropertieBox class.
//
//////////////////////////////////////////////////////////////////////

#ifndef CAMERAPROPERTIEBOX_H
#define CAMERAPROPERTIEBOX_H

#include "controls.h"

class CameraPropertieBox : public CWToolBox
{
public:
	CameraPropertieBox();
	virtual ~CameraPropertieBox();

	void ShowCameraPosition(float pos[3]);
};

#endif
