#pragma once

#include <PolyScreenEntity.h>
#include "SingleEntityTransition.h"

class MoveTo : public SingleEntityTransition
{
	public:
		MoveTo(Polycode::ScreenEntity* entity, int time,
			float intensity, Polycode::Vector2 position);

		void onTick();

		static void apply(Polycode::ScreenEntity* entity, int time,
			float intensity, Polycode::Vector2 position);
	private:
		Polycode::Vector2 startPosition, endPosition;
};