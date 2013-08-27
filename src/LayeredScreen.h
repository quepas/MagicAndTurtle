#pragma once

#include <PolyPhysicsScreen.h>
#include <PolyScreenEntity.h>

class LayeredScreen : public Polycode::PhysicsScreen
{
	public:
		LayeredScreen();
		~LayeredScreen();



	private:
		Polycode::ScreenEntity *root, *background;
};