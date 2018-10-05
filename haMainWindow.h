#ifndef HAMAINWINDOW_H
#define HAMAINWINDOW_H

#include <Window.h>
#include <View.h>
#include <LayoutBuilder.h>

#include "haViewToolBar.h"
#include "haMenuBar.h"
#include "haViewEditor.h"
#include "haViewOutput.h"
#include "haViewProjectTree.h"
#include "haViewStatusBar.h"

class haMainWindow : public BWindow
{
public:
						haMainWindow(void);
			void		MessageReceived(BMessage *msg);
			bool		QuitRequested(void);
			void		BuildLayout();
			
			BLayout*			layout;
			BView*				topView;
			haMenuBar*			menuBar;
			haStatusBar*		statusBar;
			haViewToolBar*		toolBar;
			haViewProjectTree* 	projectView;
			haViewEditor*		editorView;
			
			
			
private:
};

#endif
