// SelectionHandler.cpp: implementation of the SelectionHandler class.
//
//////////////////////////////////////////////////////////////////////

#include "SelectionHandler.h"
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <stdio.h>

#include "SelectionObject.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SelectionHandler::SelectionHandler()
{
}

SelectionHandler::~SelectionHandler()
{
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
int SelectionHandler::GatherHits(unsigned int selectionBuffer[])
{
	int iHits;

	::glFlush();
	iHits = ::glRenderMode(GL_RENDER);

	if (iHits <= 0)
		return 0;

	int *ptr, names;
	ptr = (int*)selectionBuffer;
	for (int i = 0; i < iHits; i++)
	{
		names = *ptr;
		ptr++;
//		m_pSelection[i].fDepth[0] = (float) *ptr / 0x7fffffff;
		ptr++;
//		m_pSelection[i].fDepth[1] = (float) *ptr / 0x7fffffff;
		ptr++;
		for (int j = 0; j < names; j++)
		{
//			m_pSelection[i].iIndex = *ptr;
//			m_pSelection[i].pObj = reinterpret_cast <ISelectObject*> (*ptr);

			SelectionObject* obj = reinterpret_cast <SelectionObject*> (*ptr);
			obj->selectionState = !obj->selectionState;
			ptr++;
		}
	}

	return iHits;
}