#pragma once

#include <vector>

#include "Transition.h"

/*
 *	@author: quepas
 */
class TransitionMgr
{
	public:
		void add(Transition* transition);
		void remove(Transition* transition);
		void pauseAll(bool pause);

		static TransitionMgr& getInstance() 
		{
			static TransitionMgr instance;
			return instance;
		}

	private:		
		TransitionMgr() {}
		TransitionMgr(const TransitionMgr&) {}
		TransitionMgr& operator=(const TransitionMgr&) {}

		std::vector<Transition*> transitions;
};