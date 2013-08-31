#pragma once

#include "SingleEntityTransition.h"
#include "TransitionUtil.h"
#include <PolyColor.h>
#include <PolyScreenEntity.h>

/*
 *	@author: quepas
 */
class ColorToColor : public SingleEntityTransition
{
	public:
		ColorToColor(Polycode::ScreenEntity* entity, int time, 
			float intensity, Polycode::Color _dest,
			Polycode::Color _base = Polycode::Color(1.0, 1.0, 1.0, 1.0));
		
		void onTick();

		static void apply(Polycode::ScreenEntity* entity, int time, 
			float intensity, Polycode::Color _dest,
			Polycode::Color _base = Polycode::Color(1.0, 1.0, 1.0, 1.0));
	private:
		Polycode::Color base, dest, current, diffScaled;		
};