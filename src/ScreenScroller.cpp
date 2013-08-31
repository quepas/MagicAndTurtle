#include "ScreenScroller.h"

#include "MagicAndTurtleApp.h"
#include <iostream>
using namespace Polycode;

ScreenScroller::ScreenScroller(ScreenWithBackground* _screen, ScreenEntity* _entity /* = nullptr */)
	:	screen(_screen), 
		background(_screen->getBackground()), 
		bgHorizontalScroll(false)
{
	setCenterEntity(_entity);
}

void ScreenScroller::setCenterEntity(ScreenEntity* _entity)
{
	if(_entity)
	{
		entity = _entity;
		entity -> addEventListener(this, Event::EVENTBASE_NONPOLYCODE+113);
		Vector2 diff = calculateEntityDiffFromCenter();
		Scroll(diff);
		lastDiffFromCenter = diff;
	}	
}

void ScreenScroller::Scroll(Polycode::Vector2 diff)
{
	screen -> setScreenOffset(-diff.x, -diff.y);
}

void ScreenScroller::handleEvent(Event* event)
{
	// scroll screen & background event
	if(event->getEventCode() == Event::EVENTBASE_NONPOLYCODE+113)
	{
		Vector2 diff = calculateEntityDiffFromCenter();
		Scroll(diff);

		if(background) {
			Number yDiff = diff.y - lastDiffFromCenter.y;

			if(bgHorizontalScroll)
				yDiff = 0;

			background -> Scroll(diff.x - lastDiffFromCenter.x, 
								 yDiff);			
		}
		lastDiffFromCenter = diff;
	} 	
}

Polycode::Vector2 ScreenScroller::calculateEntityDiffFromCenter()
{
	Vector2 screenPosition = entity -> getScreenPosition();
	Number xDiff = screenPosition.x - MagicAndTurtleApp::getResolution().x/2.0;
	Number yDiff = screenPosition.y - MagicAndTurtleApp::getResolution().y/2.0;
	return Vector2(xDiff, yDiff);
}

void ScreenScroller::scrollBackgroundHorizontal( bool horizontalScroll )
{
	bgHorizontalScroll = horizontalScroll;
}
