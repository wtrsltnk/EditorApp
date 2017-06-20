// IModelLoader.h: IModelLoader interface.
//
//////////////////////////////////////////////////////////////////////

#ifndef IMODELLOADER_H
#define IMODELLOADER_H

#include "IModel.h"

class IModelLoader
{
public:		virtual bool LoadModel(IModel* model);
public:		virtual bool SaveModel(IModel* model);
};

#endif