#pragma once

#include "ScreenWithBackground.h"

class ScreenFactory
{
	public:
		static ScreenWithBackground* prepareScreenWithLayeredBgFromFile(Polycode::String file);
		static Polycode::PhysicsScreen* prepareScreenFromFile(Polycode::String file);
		static ParallaxBackground* prepareParallaxBackgroundFromFile(Polycode::String file);
};