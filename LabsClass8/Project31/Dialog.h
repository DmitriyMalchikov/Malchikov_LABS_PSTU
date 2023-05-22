#pragma once
#include "Event.h"
class Dialog :
    public Vector
{
public:
	Dialog();
	~Dialog();
	void GetEvent(TEvent& event);	
	void Execute();
	void HandleEvent(TEvent& event);
	void ClearEvent(TEvent& event);
	bool Valid();
	void EndExec();
protected:
	int EndState;
};

