#pragma once

#include "Transition.h"
#include <PolyScreenEntity.h>

class SingleEntityTransition : public Transition
{
	public:
		SingleEntityTransition(Polycode::ScreenEntity* _entity, 
			int time, float intensity) 
			: Transition(time, intensity), entity(_entity) 
		{};
	
	protected:
		Polycode::ScreenEntity* entity;
};