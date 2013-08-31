#include "ScreenWithBackground.h"

using namespace Polycode;

ScreenWithBackground::ScreenWithBackground(ParallaxBackground* bg)
	:	background(bg)
{
	addChild(background);
}

ScreenWithBackground::~ScreenWithBackground()
{

}
