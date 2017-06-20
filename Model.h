// Model.h: interface for the Model class.
//
//////////////////////////////////////////////////////////////////////

#ifndef MODEL_H
#define MODEL_H

#include "IModel.h"
#include "Collection.h"
#include "Skeleton.h"
#include "MeshGroup.h"
#include "Sequence.h"
#include "AnimationObject.h"

class Model : public AnimationObject, public IModel
{
private:
	char name[128];
	Skeleton skeleton;
	Collection <MeshGroup*> meshGroups;
	Collection <Sequence*> sequences;
	Sequence* currentSequence;

	void ClearMeshGroups();
	void ClearSequences();

	void SetupJoints();
public:
	Model(char* name);
	virtual ~Model();

	char* Name();
	void Name(char* name);

	int GetFrameCount();
	int GetCurrentFrame();
	void AdvanceFrame(float amount);
	void GotoFrame(int frame);

	void SetSkeleton(Skeleton* skeleton);
	Skeleton* GetSkeleton();

	void AddMeshGroup(MeshGroup* meshgroup);
	bool RemoveMeshGroup(char* meshgroup);
	MeshGroup* GetMeshGroup(char* meshgroup);
	int GetMeshGroupIndex(char* meshgroup);

	void AddSequence(Sequence* seq);
	bool RemoveSequence(char* seq);
	Sequence* GetSequence(char* seq);
	int GetSequenceIndex(char* seq);

	int GetMeshGroupCount();
	MeshGroup* GetMeshGroup(int index);

	int GetSequenceCount();
	Sequence* GetSequence(int index);

	void SetCurrentSequence(int index);
	void SetCurrentSequence(char* seq);
	Sequence* GetCurrentSequence();

	bool IsReady();
};

#endif
