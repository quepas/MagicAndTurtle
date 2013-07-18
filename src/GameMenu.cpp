#include "GameMenu.h"



GameMenu::GameMenu(Polycode::PhysicsScreen* screen,Polycode::Core* core,int intervalTop,int fontSize)
{	
	
	int height=0;
	int width=0;


	width=core->getXRes();
	height=core->getYRes();
	ScreenLabel* newgame=new ScreenLabel(Dictionary::MENU_NEW_GAME, fontSize);
	newgame->setPositionMode(ScreenEntity::POSITION_CENTER);
	newgame->setColor(1.0,0.0,0.0,1.0);
	menuItems.push_back(newgame);

	ScreenLabel* loadgame=new ScreenLabel(Dictionary::MENU_LOAD_GAME, fontSize);
	loadgame->setPositionMode(ScreenEntity::POSITION_CENTER);
	menuItems.push_back(loadgame);
	
	ScreenLabel* credits=new ScreenLabel(Dictionary::MENU_CREDITS, fontSize);
	credits->setPositionMode(ScreenEntity::POSITION_CENTER);
	menuItems.push_back(credits);

	ScreenLabel* exit=new ScreenLabel(Dictionary::MENU_EXIT, fontSize);
	exit->setPositionMode(ScreenEntity::POSITION_CENTER);
	menuItems.push_back(exit);


	for(int x=0;x<menuItems.size();x++){
		menuItems[x]->setPosition(width/2,((height/(menuItems.size()+1))*x)+intervalTop);
		screen->addChild(menuItems[x]);
	}
}


GameMenu::~GameMenu(void)
{
	for(int x=0;x<menuItems.size();x++){
		delete menuItems[x];
	}

}
