#pragma once

#include <PolyScreen.h>
#include <PolyScreenEntity.h>
#include <PolyEventHandler.h>

class ScreenScroller : public Polycode::EventHandler
{
	public:
		ScreenScroller(Polycode::Screen* _screen, Polycode::ScreenEntity* _entity = nullptr);		

		void setCenterEntity(Polycode::ScreenEntity* _entity);
		void Scroll(Number x, Number y);
		void handleEvent(Polycode::Event* event);
	private:
		Polycode::Screen* screen;
		Polycode::ScreenEntity* entity;
};