#include "Platform.h"

Platform::Platform(Number x, Number y, const Polycode::String& fileName)
	: ScreenImage(fileName)
{		
	setPosition(x, y);
}