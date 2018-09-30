#include "App.h"
#include "haMainWindow.h"


App::App(void)
	:	BApplication("application/x-vnd.dw-TestApp")
{
	haMainWindow *mainwin = new haMainWindow();
	mainwin->Show();
}


int
main(void)
{
	App *app = new App();
	app->Run();
	delete app;
	return 0;
}
