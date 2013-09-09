#include "Transition.h"
#include "TransitionMgr.h"

#include "GlobalDef.h"

using namespace Polycode;

Transition::Transition(uint32 time /* = 1000 */, Number intensity /* = 50.0f */)
{
	initTimer(time, intensity);
	TransitionMgr::getInstance().add(this);
}

Transition::~Transition()
{
	TransitionMgr::getInstance().remove(this);
	delete timer;
}

void Transition::initTimer(uint32 time, Number intensity)
{
	timer = new Timer(true, _round(time / intensity));
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