#pragma once

#include <PolyScreen.h>
#include <PolyScreenEntity.h>
#include <PolyEventHandler.h>

#include "ParallaxBackground.h"

class ScreenScroller : public Polycode::EventHandler
{
	public:
		ScreenScroller(Polycode::Screen* _screen, Polycode::ScreenEntity* _entity = nullptr);

		void setCenterEntity(Polycode::ScreenEntity* _entity);		
		void setBackground(ParallaxBackground* _background);
		void Scroll(Polycode::Vector2 diff);
		void handleEvent(Polycode::Event* event);
	private:
		Polycode::Screen* screen;
		Polycode::ScreenEntity* entity;
		Polycode::Vector2 lastDiffFromCenter;
		ParallaxBackground* background;

		Polycode::Vector2 calculateEntityDiffFromCenter();
};