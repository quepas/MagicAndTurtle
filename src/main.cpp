#include <Polycode.h>

#include "MagicAndTurtleApp.h"
#include "PolycodeView.h"

using namespace Polycode;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
	LPSTR lpCmdLine, int nCmdShow)
{
	PolycodeView *view = new PolycodeView(hInstance, 
		nCmdShow, "Magic&Turtle", false, true);
	MagicAndTurtleApp *app = new MagicAndTurtleApp(view, Vector2(800, 600), false);
	app -> Init();

	MSG msg;
	do {
		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	} while(app->Update());
	return msg.wParam;
}