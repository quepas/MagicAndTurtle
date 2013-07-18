#pragma once

#include <PolyScreenImage.h>

class Portal : public Polycode::ScreenImage
{
public:
	Portal(Number x, Number y, const Polycode::String& fileName);
	~Portal(void);
};

