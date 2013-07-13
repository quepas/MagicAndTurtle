#ifndef MAGIC_AND_TURTLE_APP_H_
#define MAGIC_AND_TURTLE_APP_H_

#include <Polycode.h>
#include "PolycodeView.h"

class MagicAndTurtleApp : public Polycode::EventHandler
{
	public:
		MagicAndTurtleApp(PolycodeView* view);
		~MagicAndTurtleApp() {};

		void Init();
		bool Update();
	private:
		Polycode::Core* core;
};

#endif