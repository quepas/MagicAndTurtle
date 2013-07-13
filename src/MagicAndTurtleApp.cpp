#include "MagicAndTurtleApp.h"

#include <PolyWinCore.h>

using namespace Polycode;

MagicAndTurtleApp::MagicAndTurtleApp(PolycodeView* view) : EventHandler() 
{
	core = new POLYCODE_CORE(view, 640,480,false,false,0,0,90);			
}

void MagicAndTurtleApp::Init()
{
	CoreServices::getInstance()->getResourceManager()->addArchive("res/default.pak");
	CoreServices::getInstance()->getResourceManager()->addDirResource("default", false);

	Screen *screen = new Screen();				
	ScreenLabel* label = new ScreenLabel("Wild text ftw", 33);
	label -> setPosition(30, 30);
	screen->addChild(label);
}

bool MagicAndTurtleApp::Update()
{
	return core -> updateAndRender();
}