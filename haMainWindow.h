#ifndef HAMAINWINDOW_H
#define HAMAINWINDOW_H

#include <Window.h>
#include <View.h>
#include <LayoutBuilder.h>
#include <File.h>
#include <FilePanel.h>
#include <String.h>
#include <Entry.h>
#include <stdio.h>

#include "haViewToolBar.h"
#include "haMenuBar.h"
#include "haViewEditor.h"
#include "haViewOutput.h"
#include "haViewProjectTree.h"
#include "haViewStatusBar.h"
#include "haViewSpacer.h"

class haMainWindow : public BWindow
{
public:
						haMainWindow(void);
						~haMainWindow(void);
			void		MessageReceived(BMessage *msg);
			bool		QuitRequested(void);
			void		BuildLayout();
			void 		OpenFile(const entry_ref &ref);
			void 		OpenFile(const char* path);
			void		SaveFile(const char* path);
			void		SetWindowTitle();
			int			FileChangedDialog(void);
			
			BLayout*			layout;
			BView*				topView;
			BView*				layoutView;
			haMenuBar*			menuBar;
			haStatusBar*		statusBar;
			haViewToolBar*		toolBar;
			haViewProjectTree* 	projectView;
			haViewEditor*		editorView;
			haViewOutput*		outputView;
			BFilePanel*			openFilePanel;
			BFilePanel*			saveFilePanel;
			BString				filePath;
			
			//Testing
			char 				buff[1024];
			FILE				*file;
			void		TestPopen(void);
			
			
private:
};

#endif
