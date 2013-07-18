#pragma once
#include <Polycode.h>
#include <PolyString.h>
#include <PolyScreen.h>
#include <vector>
#include "PolycodeView.h"
#include "Dictionary.h"

class Credits
{
public:
	Credits(Polycode::Core* core);
	~Credits(void);

private:
	Polycode::Screen* screen;
	Polycode::Core* core;
	Polycode::ScreenImage* background;
	vector<ScreenLabel*> content;

};

