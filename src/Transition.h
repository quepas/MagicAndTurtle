#pragma once

#include <PolyTimer.h>
#include "GlobalDef.h"

/*
 *	@author: quepas
 */
class Transition : public Polycode::EventHandler
{
	public:
		// time in miliseconds [onTick() executed every 20 ms]
		Transition(uint32 time = 1000, Number intensity = 50.0f);
		virtual ~Transition();

		virtual void onTick() = 0;		
		void Pause(bool pause);
		void handleEvent(Polycode::Event* event);

	protected:
		Polycode::Timer* timer;
		void initTimer(uint32 time, Number intensity);

	private:

};