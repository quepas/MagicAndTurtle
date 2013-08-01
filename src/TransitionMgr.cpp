#include "TransitionMgr.h"

void TransitionMgr::add(Transition* transition)
{
	transitions.push_back(transition);
}

void TransitionMgr::remove(Transition* transition)
{
	for(auto it = transitions.begin(); it != transitions.end(); ++it)
	{
		if((*it) == transition)
		{
			transitions.erase(it);
			break;
		}
	}
}

void TransitionMgr::pauseAll(bool pause)
{
	for(auto it = transitions.begin(); it != transitions.end(); ++it)
	{
		(*it) -> Pause(pause);
	}
}