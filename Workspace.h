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
    Workspace(const char* name);
	virtual ~Workspace();

	char* Name();
    void Name(const char* name);

	void AddModel(Model* model);
    bool RemoveModel(const char* model);
    Model* GetModel(const char* model);
    int GetModelIndex(const char* model);

	int GetModelCount();
	Model* GetModel(int index);

	void SetCurrentModel(int index);
    void SetCurrentModel(const char* model);
	Model* GetCurrentModel();
};

#endif
