// MS3DLoader.cpp: implementation of the MS3DLoader class.
//
//////////////////////////////////////////////////////////////////////

#include "MS3DLoader.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MS3DLoader::MS3DLoader()
{
}

MS3DLoader::~MS3DLoader()
{
}

int	MS3DLoader::GetExtension(char extension[])
{
	return FILE_OK;
}

int	MS3DLoader::LoadFile(const char* filename, IModel& model)
{
	return FILE_OK;
}

int	MS3DLoader::SaveFile(const char* filename, IModel& model)
{
	return FILE_OK;
}