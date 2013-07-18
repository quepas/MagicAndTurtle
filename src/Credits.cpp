#include "Credits.h"


Credits::Credits(Polycode::Core* core)
{
	this->core=core;
	this->screen=new Polycode::Screen();
	int fontSize=20;
	int width=core->getXRes();
	
	background=new ScreenImage("res/credits/credits_background.png");
	background->setPosition(0,0);
	screen->addChild(background);

	content.push_back(new ScreenLabel(Dictionary::CREDITS_TEXT_0, 30));
	content.push_back(new ScreenLabel(Dictionary::CREDITS_TEXT_1, fontSize));
	content.push_back(new ScreenLabel(Dictionary::CREDITS_TEXT_2, fontSize));
	content.push_back(new ScreenLabel(Dictionary::CREDITS_TEXT_3, fontSize));

	for(int x =0; x<content.size();x++){
			content[x]->setPositionMode(ScreenEntity::POSITION_CENTER);
			content[x]->setPosition(width/2,2*fontSize*x+fontSize);
			screen->addChild(content[x]);
			}
}


Credits::~Credits(void)
{
	delete background;
	for(int x =0; x<content.size();x++){
		delete content[x];}
	delete screen;

}
