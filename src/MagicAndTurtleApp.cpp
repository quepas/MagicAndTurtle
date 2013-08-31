#include "MagicAndTurtleApp.h"

#include <PolyWinCore.h>
#include <PolyPhysicsScreenEntity.h>
#include <PolyColor.h>
#include <iostream>

#include "ColorToColor.h"
#include "TransitionMgr.h"
#include "LayeredEntity.h"
#include "SpellFactory.h"
#include "MoveTo.h"

using namespace Polycode;

Vector2 MagicAndTurtleApp::resolution;

MagicAndTurtleApp::MagicAndTurtleApp(PolycodeView* view, 
	Vector2 res /* = Vector2(640, 480) */, bool fullscreen /* = false*/)
	: EventHandler()
{
	resolution = res;
	core = new POLYCODE_CORE(view, resolution.x, resolution.y, fullscreen, true, 0, 0, 60);			
	screen = new ScreenWithBackground(prepareBackground());
	creditsShown = false;		
}

Vector2 MagicAndTurtleApp::getResolution()
{
	return resolution;
}

void MagicAndTurtleApp::Init()
{
	CoreServices::getInstance()->getResourceManager()->addArchive("res/default.pak");
	CoreServices::getInstance()->getResourceManager()->addDirResource("default", false);

	initEvents();
	menuShown=true;
	menu = new GameMenu(core, 40, 32);			
	player = new Player(screen, 88, 0, "res/wizard/wizard.png");	
	player -> setPositionMode(ScreenEntity::POSITION_CENTER);
	screen -> addPhysicsChild(player, PhysicsScreenEntity::ENTITY_MESH, false,0.1,1,0,false,true);

	screenScroller = new ScreenScroller(screen, player);				
	screenScroller -> scrollBackgroundHorizontal(true);
	
	Platform* platform = new Platform(0, 300, "res/platform/normal_1.png");	
	screen -> addPhysicsChild(platform, PhysicsScreenEntity::ENTITY_RECT, true);		
}

bool MagicAndTurtleApp::Update()
{
	return core -> updateAndRender();
}

void MagicAndTurtleApp::handleEvent(Event* event)
{
	if(event -> getDispatcher() == core -> getInput())
	{
		handleInputEvent(dynamic_cast<InputEvent*>(event));
	}
}

void MagicAndTurtleApp::initEvents()
{
	core -> getInput() -> addEventListener(this, InputEvent::EVENT_KEYDOWN);
	core -> getInput() -> addEventListener(this, InputEvent::EVENT_KEYUP);	
}

void MagicAndTurtleApp::handleInputEvent(InputEvent* inputEvent)
{		
	if(inputEvent) 
	{
		switch(inputEvent -> getEventCode()) 
		{	
			case InputEvent::EVENT_KEYDOWN:
				if(menuShown){
					switch (inputEvent -> getKey())
					{
						case KEY_UP:
							menu->goUp();
							break;
						case KEY_DOWN:
							menu->goDown();
							break;
						case KEY_SPACE:
							menu->performAction();
								if(menu->getcurrentActiveItemNumber()!=2){
									menuShown=false;
									delete menu;
									return;
									}
							if(menu->getcurrentActiveItemNumber()==2){
								this->creditsShown=true;
							}
							break;
					}
				}
				else if(creditsShown){
					switch (inputEvent -> getKey())
					{
					case KEY_ESCAPE:
							creditsShown=false();
							menu->deleteCredits();
							return;
					}			
				}
				else{
					switch (inputEvent -> getKey())
						{
							case KEY_LEFT:								
								player -> beginMove(Player::LEFT);
								break;
							case KEY_RIGHT:						
								player -> beginMove(Player::RIGHT);
								break;
							case KEY_UP:
								player -> beginMove(Player::UP);
								break;
							case KEY_DOWN:
								player -> beginMove(Player::DOWN);
								break;
							case KEY_SPACE:
								player -> Jump();
								break;
							case KEY_w:
								player -> Cast(Spell::FIRE_BALL);
								break;
							case KEY_ESCAPE:
								exit(0);
						}
						break;
					}
			case InputEvent::EVENT_KEYUP:
				switch(inputEvent -> getKey())
				{
					case KEY_LEFT:
						player -> endMove(Player::LEFT);
						break;
					case KEY_RIGHT:
						player -> endMove(Player::RIGHT);
						break;
					case KEY_UP:
						player -> endMove(Player::UP);
						break;
					case KEY_DOWN:
						player -> endMove(Player::DOWN);
						break;
					case KEY_SPACE:						
						ColorToColor::apply(player, 1000, 50.0f, 
							Color(1.0, 0.0, 0.0, 1.0));						
						break;				
					case KEY_p:
						TransitionMgr::getInstance().pauseAll(true);
						break;
					case KEY_u:
						TransitionMgr::getInstance().pauseAll(false);
						break;								
				}				
				break;
		}
	}
}

ParallaxBackground* MagicAndTurtleApp::prepareBackground()
{
	std::string trees[] = {
		"res/tree/tree1.png", 
		"res/tree/tree2.png", 
		"res/tree/tree3.png" 
	};
	ParallaxBackground* forest = new ParallaxBackground(3);

	static int tree_1_width = -300;
	static int tree_2_width = -400;
	static int tree_3_width = -500;

	for(int i = 0; i < 10; ++i)
	{
		ScreenImage* tree = new ScreenImage(trees[0]);
		tree -> setPosition(tree_1_width += 300, 0);
		tree -> setScale(0.5, 0.5, 0.5);
		forest -> Add(tree, 3);

		ScreenImage* tree2 = new ScreenImage(trees[1]);
		tree2 -> setPosition(tree_2_width += 300, 10);
		tree2 -> setScale(0.5, 0.5, 0.5);
		forest -> Add(tree2, 2);
		
		ScreenImage* tree3 = new ScreenImage(trees[2]);
		tree3 -> setPosition(tree_3_width += 400, 30);
		tree3 -> setScale(0.5, 0.5, 0.5);
		forest -> Add(tree3, 1);
	}	

	return forest;
}
