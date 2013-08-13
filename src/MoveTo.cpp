#include "MoveTo.h"

using namespace Polycode;

MoveTo::MoveTo(Polycode::ScreenEntity* entity, int time, 
	float intensity, Polycode::Vector2 position)
	: SingleEntityTransition(entity, time, intensity), 
	  startPosition(entity -> getPosition2D()),
	  endPosition(position)
{

}

void MoveTo::onTick()
{

}

void MoveTo::apply(Polycode::ScreenEntity* entity, int time, 
	float intensity, Polycode::Vector2 position)
{
	new MoveTo(entity, time, intensity, position);
}