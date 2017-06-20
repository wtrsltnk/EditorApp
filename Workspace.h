// Workspace.h: interface for the Workspace class.
//
//////////////////////////////////////////////////////////////////////

#ifndef WORKSPACE_H
#define WORKSPACE_H

#include "Collection.h"
#include "Model.h"

class Workspace
{
private:
	char name[128];
	Collection <Model*> models;
	Model* currentModel;

	void ClearModels();
public:
	Workspace(char* name);
	virtual ~Workspace();

	char* Name();
	void Name(char* name);

	void AddModel(Model* model);
	bool RemoveModel(char* model);
	Model* GetModel(char* model);
	int GetModelIndex(char* model);

	int GetModelCount();
	Model* GetModel(int index);

	void SetCurrentModel(int index);
	void SetCurrentModel(char* model);
	Model* GetCurrentModel();
};

#endif
