#pragma once

#include <PolyScreen.h>
#include <PolyScreenEntity.h>
#include <PolyEventHandler.h>

#include "ScreenWithBackground.h"
#include "ParallaxBackground.h"

class ScreenScroller : public Polycode::EventHandler
{
	public:
		ScreenScroller(ScreenWithBackground* _screen, Polycode::ScreenEntity* _entity = nullptr);

		void setCenterEntity(Polycode::ScreenEntity* _entity);
		void Scroll(Polycode::Vector2 diff);
		void handleEvent(Polycode::Event* event);
		void scrollBackgroundHorizontal(bool horizontalScroll);
	private:
		ScreenWithBackground* screen;
		Polycode::ScreenEntity* entity;
		Polycode::Vector2 lastDiffFromCenter;
		ParallaxBackground* background;
		bool bgHorizontalScroll;

		Polycode::Vector2 calculateEntityDiffFromCenter();
};