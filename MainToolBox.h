// MainToolBox.h: interface for the MainToolBox class.
//
//////////////////////////////////////////////////////////////////////

#ifndef MAINTOOLBOX_H
#define MAINTOOLBOX_H

#include "controls.h"
#include "resource.h"

class MainToolBox : public CWToolBox
{
private:
	LRESULT ViewProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
	MainToolBox();
	virtual ~MainToolBox();
};

#endif
