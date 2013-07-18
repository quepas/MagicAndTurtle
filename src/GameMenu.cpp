#include "GameMenu.h"



GameMenu::GameMenu(Polycode::Core* core,int intervalTop,int fontSize)
{	
	int height=0;
	int width=0;
	this->currentActiveItemNumber=0;

	screen= new Polycode::Screen();
	width=core->getXRes();
	height=core->getYRes();

	logo=new ScreenImage("res/HUD/menu_logo.png");
	int logoHeight=logo->getHeight();
	logo->setPositionMode(ScreenEntity::POSITION_CENTER);
	logo->setPosition(width/2,logoHeight/2);
	
	
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

	screen->addChild(logo);
	for(int x=0;x<menuItems.size();x++){
		menuItems[x]->setPosition(width/2,(((height-logoHeight)/((menuItems.size()+1))*x))+intervalTop+logoHeight);
		screen->addChild(menuItems[x]);
	}


}

GameMenu::~GameMenu(void)
{
	
	for(int x=0;x<menuItems.size();x++){
		delete menuItems[x];
	}
	delete screen;

}

int GameMenu::getcurrentActiveItemNumber(){
		return this->currentActiveItemNumber;
}

void GameMenu::goDown(){
	if(currentActiveItemNumber<menuItems.size()-1){
		menuItems[currentActiveItemNumber]->setColorInt(255,255,255,255);
		currentActiveItemNumber++;
		menuItems[currentActiveItemNumber]->setColorInt(255,0,0,255);
		}

}

void GameMenu::goUp(){
		if(currentActiveItemNumber>0){
		menuItems[currentActiveItemNumber]->setColorInt(255,255,255,255);
		currentActiveItemNumber--;
		menuItems[currentActiveItemNumber]->setColorInt(255,0,0,255);
		}
	}