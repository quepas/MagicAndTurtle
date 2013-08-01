#pragma once

#include <PolyTimer.h>

/*
 *	@author: quepas
 */
class Transition : public Polycode::EventHandler
{
	public:
		// time in miliseconds [onTick() executed every 20 ms]
		Transition(int time = 1000, float intensity = 50.0f);
		virtual ~Transition();

		virtual void onTick() = 0;		
		void Pause(bool pause);
		void handleEvent(Polycode::Event* event);

	protected:
		Polycode::Timer* timer;
		void initTimer(int time, float intensity);

	private:

};