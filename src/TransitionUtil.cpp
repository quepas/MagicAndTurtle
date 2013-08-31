#include "TransitionUtil.h"

using namespace Polycode;

Color TransitionUtil::calculateColorDiff( 
	Color base, Color dest, Number intensity )
{
	Color colorDiff = Color(
		dest.r - base.r,
		dest.g - base.g,
		dest.b - base.b,
		dest.a - base.a);

	return colorDiff * (1.0 / intensity);
}

Vector2 TransitionUtil::calculatePositionDiff( 
	Vector2 start, Vector2 end, Number intensity )
{
	Number xDiff = end.x - start.x;
	Number yDiff = end.y - start.y;

	return Vector2(xDiff / intensity, 
				   yDiff / intensity);
}

