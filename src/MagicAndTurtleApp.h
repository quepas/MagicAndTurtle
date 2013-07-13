#pragma once

#include <Polycode.h>

#include "PolycodeView.h"
#include "Player.h"

/*
 *	@author: quepas
 */
class MagicAndTurtleApp : public Polycode::EventHandler
{
	public:
		MagicAndTurtleApp(PolycodeView* view);
		~MagicAndTurtleApp() {};

		void Init();
		bool Update();
		void handleEvent(Polycode::Event* event);
	private:
		Polycode::Core* core;
		Player* player;

		void initEvents();
		void handleInputEvent(Polycode::InputEvent* inputEvent);
};