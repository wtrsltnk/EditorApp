// SelectionHandler.h: interface for the SelectionHandler class.
//
//////////////////////////////////////////////////////////////////////

#ifndef SELECTIONHANDLER_H
#define SELECTIONHANDLER_H

class SelectionHandler  
{
public:
	SelectionHandler();
	virtual ~SelectionHandler();

	virtual int GatherHits(unsigned int selectionBuffer[]);
};

#endif
