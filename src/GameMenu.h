#pragma once
#include <PolyPhysicsScreen.h>
#include <Polycode.h>
#include <PolyString.h>
#include <PolyScreen.h>
#include <vector>
#include "PolycodeView.h"
#include "Dictionary.h"
#include "Credits.h"


class GameMenu
{
public:
	GameMenu(Polycode::Core* core,int intervalTop,int fontSize);
	~GameMenu(void);
	void goDown();
	void goUp();
	int  getcurrentActiveItemNumber();
	void performAction();
	void deleteCredits();
private:
	ScreenImage* logo;
	vector<ScreenLabel*> menuItems;
	Polycode::Screen* screen;
	Polycode::Core* core;
	Credits* credits;
	int menuItemsnumber;
	int currentActiveItemNumber;
	};

