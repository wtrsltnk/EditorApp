// MS3DLoader.h: interface for the MS3DLoader class.
//
//////////////////////////////////////////////////////////////////////

#ifndef MS3DLOADER_H
#define MS3DLOADER_H

#include "IFileLoader.h"

class MS3DLoader : public IFileLoader
{
public:
	MS3DLoader();
	virtual ~MS3DLoader();

	int		GetExtension(char extension[]);
	int		LoadFile(const char* filename, IModel& model);
	int		SaveFile(const char* filename, IModel& model);
};

#endif
