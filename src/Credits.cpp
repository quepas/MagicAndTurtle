#include "Credits.h"
#include "I18n.h"

Credits::Credits(Polycode::Core* core)
{
	this->core=core;
	this->screen=new Polycode::Screen();
	int fontSize=20;
	int width=core->getXRes();

	background=new ScreenImage("res/credits/credits_background.png");
	background->setPosition(0,0);
	screen->addChild(background);

	I18n* creditsLocale = new I18n();
	creditsLocale->parseFile("res/i18n/credits.yaml");

	content.push_back(new ScreenLabel(creditsLocale->get("credits"), 30));
	content.push_back(new ScreenLabel(creditsLocale->get("credits"), fontSize));
	content.push_back(new ScreenLabel(creditsLocale->get("credits"), fontSize));
	content.push_back(new ScreenLabel(creditsLocale->get("credits"), fontSize));

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