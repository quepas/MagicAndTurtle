#pragma once
#include <PolyPhysicsScreen.h>
#include <Polycode.h>
#include <PolyString.h>
#include <vector>
#include "PolycodeView.h"
#include "Dictionary.h"
#include <iostream>



class GameMenu
{
public:
	GameMenu(Polycode::PhysicsScreen* screen,Polycode::Core* core,int intervalTop,int fontSize);
	~GameMenu(void);
private:
	vector<ScreenLabel*> menuItems;
	Polycode::Core* core;

	int menuItemsnumber;
	

};

