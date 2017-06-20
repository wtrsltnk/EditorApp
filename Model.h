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
    Model(const char* name);
	virtual ~Model();

    const char* Name();
    void Name(const char* name);

	int GetFrameCount();
	int GetCurrentFrame();
	void AdvanceFrame(float amount);
	void GotoFrame(int frame);

	void SetSkeleton(Skeleton* skeleton);
	Skeleton* GetSkeleton();

	void AddMeshGroup(MeshGroup* meshgroup);
    bool RemoveMeshGroup(const char* meshgroup);
    MeshGroup* GetMeshGroup(const char* meshgroup);
    int GetMeshGroupIndex(const char* meshgroup);

	void AddSequence(Sequence* seq);
    bool RemoveSequence(const char* seq);
    Sequence* GetSequence(const char* seq);
    int GetSequenceIndex(const char* seq);

	int GetMeshGroupCount();
	MeshGroup* GetMeshGroup(int index);

	int GetSequenceCount();
	Sequence* GetSequence(int index);

	void SetCurrentSequence(int index);
    void SetCurrentSequence(const char* seq);
	Sequence* GetCurrentSequence();

	bool IsReady();
};

#endif
