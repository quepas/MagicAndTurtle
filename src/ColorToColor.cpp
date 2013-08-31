#include "ColorToColor.h"

using namespace Polycode;

ColorToColor::ColorToColor(ScreenEntity* entity, int time, float intensity, 
	Polycode::Color _dest, Polycode::Color _base /* = Polycode::Color(1.0, 1.0, 1.0, 1.0) */)
	: SingleEntityTransition(entity, time, intensity), base(_base), dest(_dest)
{
	entity -> setColor(base);
	diffScaled = TransitionUtil::calculateColorDiff(base, dest, intensity);	
}

void ColorToColor::apply(Polycode::ScreenEntity* entity, int time, 
	float intensity, Polycode::Color _dest, Polycode::Color _base /* = Polycode::Color */)
{
	new ColorToColor(entity, time, intensity, _dest, _base);
}

void ColorToColor::onTick()
{
	entity -> setColor(current);
	current = current + diffScaled;
}