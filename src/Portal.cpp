#include "Portal.h"


Portal::Portal(Number x, Number y, const Polycode::String& fileName) :Polycode::ScreenImage(fileName)
{
	setPosition(x,y);
}


Portal::~Portal(void)
{
}
