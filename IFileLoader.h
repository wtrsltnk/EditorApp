#ifndef IFILELOADER_H
#define IFILELOADER_H

#define FILE_OK 0
#define FILE_ERROR -1

#include "IModel.h"

class IFileLoader
{
public: virtual int		GetExtension(char extension[]) = 0;
public:	virtual int		LoadFile(const char* filename, IModel& model) = 0;
public:	virtual int		SaveFile(const char* filename, IModel& model) = 0;
};

#endif