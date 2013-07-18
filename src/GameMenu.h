#pragma once
#include <PolyPhysicsScreen.h>
#include <Polycode.h>
#include <PolyString.h>
#include <PolyScreen.h>
#include <vector>
#include "PolycodeView.h"
#include "Dictionary.h"




class GameMenu
{
public:
	GameMenu(Polycode::Core* core,int intervalTop,int fontSize);
	~GameMenu(void);
	void GameMenu::handleEvent(Event* event);
	void goDown();
	void goUp();
	int  getcurrentActiveItemNumber();
private:
	ScreenImage* logo;
	vector<ScreenLabel*> menuItems;
	Polycode::Screen* screen;
	Polycode::Core* core;
	int menuItemsnumber;
	void handleInputEvent(Polycode::InputEvent* inputEvent);
	int currentActiveItemNumber;
	

};

