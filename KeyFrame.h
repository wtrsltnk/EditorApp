// KeyFrame.h: interface for the KeyFrame class.
//
//////////////////////////////////////////////////////////////////////

#ifndef KEYFRAME_H
#define KEYFRAME_H

class KeyFrame  
{
private:
	int jointid;
	float time;
	float parameters[3];

public:
	KeyFrame();
	virtual ~KeyFrame();

};

#endif
