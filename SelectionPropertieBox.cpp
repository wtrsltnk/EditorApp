// SelectionPropertieBox.cpp: implementation of the SelectionPropertieBox class.
//
//////////////////////////////////////////////////////////////////////

#include "SelectionPropertieBox.h"
#include "resource.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SelectionPropertieBox::SelectionPropertieBox()
{
	this->m_strClassName = "SelectionPropertieBox";
    strcpy(this->m_strTitle, "Selection Properties");
	this->m_dwResource = IDD_SELECTION;
}

SelectionPropertieBox::~SelectionPropertieBox()
{
}
