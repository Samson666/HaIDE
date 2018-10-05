#include "haMenuBar.h"
#include "haConstants.h"

haMenuBar::haMenuBar(BRect frame, const char* name)
			: BMenuBar(frame, name)
{
	BMenu* fileMenu = new BMenu(HA_MENU_FILE);
	AddItem(fileMenu);
	fileMenu->AddItem(new BMenuItem(HA_MENU_FILE_OPEN, new BMessage(HA_MENU_MESSAGE_FILE_OPEN)));	
	fileMenu->AddItem(new BMenuItem(HA_MENU_FILE_SAVE, new BMessage(HA_MENU_MESSAGE_FILE_SAVE)));
	fileMenu->AddItem(new BMenuItem(HA_MENU_FILE_SAVE_AS, new BMessage(HA_MENU_MESSAGE_FILE_SAVE_AS)));
	fileMenu->AddItem(new BMenuItem(HA_MENU_FILE_NEW, new BMessage(HA_MENU_MESSAGE_FILE_NEW)));
	fileMenu->AddItem(new BMenuItem(HA_MENU_FILE_CLOSE, new BMessage(HA_MENU_MESSAGE_FILE_CLOSE)));
	fileMenu->AddSeparatorItem();
	fileMenu->AddItem(new BMenuItem(HA_MENU_FILE_QUIT, new BMessage(HA_MENU_MESSAGE_FILE_QUIT)));
	
	BMenu* editMenu = new BMenu(HA_MENU_EDIT);
	AddItem(editMenu);
	editMenu->AddItem(new BMenuItem(HA_MENU_EDIT_CUT, new BMessage(HA_MENU_MESSAGE_EDIT_CUT)));
	editMenu->AddItem(new BMenuItem(HA_MENU_EDIT_PASTE, new BMessage(HA_MENU_MESSAGE_EDIT_PASTE)));
	
	BMenu* projectMenu = new BMenu(HA_MENU_PROJECT);
	AddItem(projectMenu);
	projectMenu->AddItem(new BMenuItem(HA_MENU_PROJECT_NEW, new BMessage(HA_MENU_MESSAGE_PROJECT_NEW)));
	
	BMenu* helpMenu = new BMenu(HA_MENU_HELP);
	AddItem(helpMenu);
	helpMenu->AddItem(new BMenuItem(HA_MENU_HELP_ABOUT, new BMessage(HA_MENU_MESSAGE_HELP_ABOUT)));
	helpMenu->AddItem(new BMenuItem(HA_MENU_HELP_TEST_POPEN, new BMessage(HA_MENU_MESSAGE_HELP_TEST_POPEN)));
	
}
