#include "ScreenScroller.h"

#include "MagicAndTurtleApp.h"

using namespace Polycode;

ScreenScroller::ScreenScroller(Screen* _screen, ScreenEntity* _entity /* = nullptr */)
	: screen(_screen)
{
	setCenterEntity(_entity);
}

void ScreenScroller::setCenterEntity(ScreenEntity* _entity)
{
	if(_entity != nullptr)
	{
		entity = _entity;
		entity -> addEventListener(this, Event::EVENTBASE_NONPOLYCODE+1);
	}	
}

void ScreenScroller::Scroll(Number x, Number y)
{
	screen -> setScreenOffset(-x, -y);
}

void ScreenScroller::handleEvent(Event* event)
{
	Vector2 position = entity -> getPosition2D();

	Scroll(position.x - MagicAndTurtleApp::getResolution().x/2.0, 
		   position.y - MagicAndTurtleApp::getResolution().y/2.0);
}