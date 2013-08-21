#include "ScreenScroller.h"

#include "MagicAndTurtleApp.h"

using namespace Polycode;

ScreenScroller::ScreenScroller(Screen* _screen, ScreenEntity* _entity /* = nullptr */)
	: screen(_screen), background(nullptr)
{
	setCenterEntity(_entity);
}

void ScreenScroller::setCenterEntity(ScreenEntity* _entity)
{
	if(_entity)
	{
		entity = _entity;
		entity -> addEventListener(this, Event::EVENTBASE_NONPOLYCODE+1);
	}	
}

void ScreenScroller::setBackground(ParallaxBackground* _background)
{
	if(_background)
	{
		background = _background;
		screen -> addChild(background);		
	}
}

void ScreenScroller::Scroll(Number x, Number y)
{
	screen -> setScreenOffset(-x, -y);
}

void ScreenScroller::handleEvent(Event* event)
{
	// scroll screen & background event
	if(event->getEventCode() == Event::EVENTBASE_NONPOLYCODE+1)
	{
		Vector2 position = entity -> getPosition2D();
		Number xDiff = position.x - MagicAndTurtleApp::getResolution().x/2.0;
		Number yDiff = position.y - MagicAndTurtleApp::getResolution().y/2.0;

		Scroll(xDiff, yDiff);
		if(background)
			background -> Scroll(xDiff, yDiff);
	} 	
}