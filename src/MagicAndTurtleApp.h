#pragma once

#include <Polycode.h>
#include <PolyPhysicsScreen.h>

#include "PolycodeView.h"
#include "Player.h"
#include "Platform.h"

#include "GameMenu.h"
#include "ScreenScroller.h"
#include "ScreenWithBackground.h"

/*
 *	@author: quepas
 */
class MagicAndTurtleApp : public Polycode::EventHandler
{
	public:
		MagicAndTurtleApp(PolycodeView* view, Vector2 res = Vector2(640, 480), bool fullscreen = false);
		~MagicAndTurtleApp() {};
		bool menuShown;
		bool creditsShown;
		void Init();
		bool Update();
		void handleEvent(Polycode::Event* event);
		
		static Vector2 getResolution();
	private:
		ScreenWithBackground* screen;		
		Polycode::Core* core;
		ScreenScroller* screenScroller;
		Player* player;		
		GameMenu* menu;
		static Vector2 resolution;

		void initEvents();
		void handleInputEvent(Polycode::InputEvent* inputEvent);
		ParallaxBackground* prepareBackground();

};