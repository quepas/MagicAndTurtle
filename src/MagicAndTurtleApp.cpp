#include "MagicAndTurtleApp.h"

#include <PolyWinCore.h>
#include <PolyPhysicsScreenEntity.h>

using namespace Polycode;

MagicAndTurtleApp::MagicAndTurtleApp(PolycodeView* view) : EventHandler() 
{
	core = new POLYCODE_CORE(view, 640, 480, false, false, 0, 0, 60);			
	screen = new PhysicsScreen();	
}

void MagicAndTurtleApp::Init()
{
	CoreServices::getInstance()->getResourceManager()->addArchive("res/default.pak");
	CoreServices::getInstance()->getResourceManager()->addDirResource("default", false);

	initEvents();

	menuShown=true;
	menu = new GameMenu(screen,core,40,32);
		
	player = new Player(screen, 320, 240, "res/wizard/walk_1.png");	
	player -> setPositionMode(ScreenEntity::POSITION_CENTER);
	screen -> addPhysicsChild(player, PhysicsScreenEntity::ENTITY_MESH, false);

	Platform* platform = new Platform(320, 500, "res/platform/normal_1.png");	
	screen -> addPhysicsChild(platform, PhysicsScreenEntity::ENTITY_RECT, true);

	Platform* platform2 = new Platform(400, 200, "res/platform/small_1.png");	
	screen -> addPhysicsChild(platform2, PhysicsScreenEntity::ENTITY_RECT, true);
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
				}
				break;
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
						break;
					case KEY_ESCAPE:
						exit(0);
				}
				break;
		}
	}
}