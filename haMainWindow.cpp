/*
______________________________________________________________________
	Filename:		haMainWindow.cpp
	Author:			Johannes Jung	
	Copyright:		2018 Johannes Jung <johannes.jung@masacom.de>
	Description:	Definition of haMainWindow (MainWindow of HaIDE)
______________________________________________________________________	
*/
//API & System include files
#include <Application.h>
#include <Alert.h>

//Project include files
#include "haConstants.h"
#include "haMainWindow.h"
#include "haViewStatusBar.h"
#include "haViewToolBar.h"

//for test purposes
#include <ListView.h>
#include <TextView.h>
#include <MenuBar.h>

//haMainWindow constructor
haMainWindow::haMainWindow(void)
	:	BWindow(BRect(100,100,HA_WINDOW_WIDTH,HA_WINDOW_HEIGHT),HA_WINDOWTITLE,B_DOCUMENT_WINDOW, B_ASYNCHRONOUS_CONTROLS)
{
	topView = new BView(Bounds(), "topview", B_FOLLOW_ALL, B_WILL_DRAW);
	topView->SetViewColor(HA_WINDOW_TOPVIEW_COLOR);
	AddChild(topView);
	menuBar = new haMenuBar("menubar");
	statusBar = new haStatusBar("statusBar");
	BuildLayout();
}


//haMainWindow message handler
void haMainWindow::MessageReceived(BMessage *msg)
{
	switch (msg->what)
	{
		case HA_MENU_MESSAGE_FILE_QUIT:
		{
			QuitRequested();
			break;
		}
		
		case HA_MENU_MESSAGE_HELP_ABOUT:
		{
			BAlert* about = new BAlert("HaIDE About", "HaIDE (c) 2018 by JJ", "OK");
			about->Go();
		}
		default:
		{
			BWindow::MessageReceived(msg);
			break;
		}
	}
}


bool haMainWindow::QuitRequested(void)
{
	be_app->PostMessage(B_QUIT_REQUESTED);
	return true;
}

void haMainWindow::BuildLayout()
{	
		statusBar  = new haStatusBar("statusbar");
		toolBar = new haViewToolBar("toolbar");
		projectView = new haViewProjectTree("projectview");
		editorView = new haViewEditor("editorview");
		
		layout = BLayoutBuilder::Group<>(topView,B_HORIZONTAL,0)
		.SetInsets(0)
		
		.AddGroup(B_VERTICAL,0)
			.Add(menuBar)
			.AddGroup(B_HORIZONTAL,0)
			.Add(toolBar)
				.AddGroup(B_VERTICAL,0)
					.AddSplit(B_HORIZONTAL, HA_WINDOW_SPLIT_SEPERATOR_WIDTH,3)
						.Add(projectView,1)
						.Add(editorView,2)
					.End()
				.End()
			.End()
			.Add(statusBar,1)
		.End();
		
}

