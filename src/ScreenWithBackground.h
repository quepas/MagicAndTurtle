#pragma once

#include <PolyPhysicsScreen.h>
#include <PolyScreenEntity.h>

#include "ParallaxBackground.h"

class ScreenWithBackground : public Polycode::PhysicsScreen
{
	public:
		ScreenWithBackground(ParallaxBackground* bg);
		~ScreenWithBackground();	

		ParallaxBackground* getBackground() { return background; }

	private:
		ParallaxBackground* background;
}; 