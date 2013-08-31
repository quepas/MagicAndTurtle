#include "MoveTo.h"
#include "TransitionUtil.h"
#include <PolyVector3.h>

using namespace Polycode;

MoveTo::MoveTo(Polycode::ScreenEntity* entity, int time, 
	Number intensity, Polycode::Vector2 position)
	: SingleEntityTransition(entity, time, intensity), 
	  startPosition(entity -> getPosition2D()),
	  currentPosition(entity -> getPosition2D()),
	  endPosition(position)
{	
	diffScaledPosition = TransitionUtil::calculatePositionDiff(
		startPosition, endPosition, intensity);
}

void MoveTo::onTick()
{
	entity -> Translate(Vector3(diffScaledPosition.x, diffScaledPosition.y, 0.0f));
	//currentPosition += diffScaledPosition;
}

void MoveTo::apply(Polycode::ScreenEntity* entity, int time, 
	Number intensity, Polycode::Vector2 position)
{
	new MoveTo(entity, time, intensity, position);
}