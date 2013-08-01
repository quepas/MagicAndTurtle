#include "Transition.h"
#include "TransitionMgr.h"

using namespace Polycode;

Transition::Transition(int time /* = 1000 */, float intensity /* = 50.0f */)
{
	initTimer(time, intensity);
	TransitionMgr::getInstance().add(this);
}

Transition::~Transition()
{
	TransitionMgr::getInstance().remove(this);
	delete timer;
}

void Transition::initTimer(int time, float intensity)
{
	timer = new Timer(true, time / intensity);
	timer -> addEventListener(this, Timer::EVENT_TRIGGER);
}

void Transition::Pause(bool pause)
{
	timer -> Pause(pause);
}

void Transition::handleEvent(Polycode::Event* event)
{
	if(event -> getDispatcher() == timer)
	{
		onTick();
	}
}