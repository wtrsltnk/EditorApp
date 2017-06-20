// AnimationObject.h: interface for the AnimationObject class.
//
//////////////////////////////////////////////////////////////////////

#ifndef ANIMATIONOBJECT_H
#define ANIMATIONOBJECT_H

class AnimationObject
{
public:		virtual int GetFrameCount() = 0;
public:		virtual int GetCurrentFrame() = 0;
public:		virtual void AdvanceFrame(float amount) = 0;
public:		virtual void GotoFrame(int frame) = 0;
};

#endif