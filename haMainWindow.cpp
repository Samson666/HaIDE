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
#include <ScrollView.h>
#include <stdio.h>
#include <File.h>
#include <FilePanel.h>
#include <Directory.h>
#include <NodeInfo.h>
#include <Path.h>
#include <TranslationUtils.h>
#include <StringItem.h>
#include <Font.h>

//Project include files
#include "haConstants.h"
#include "haMainWindow.h"
#include "haViewStatusBar.h"
#include "haViewToolBar.h"
#include "haViewOutput.h"
#include "haViewProjectTreeItem.h"

//for test purposes
#include <ListView.h>
#include <TextView.h>
#include <MenuBar.h>
#include <Messenger.h>
#include <iostream>

//haMainWindow constructor
haMainWindow::haMainWindow(void)
	:	BWindow(BRect(100,100,HA_WINDOW_WIDTH,HA_WINDOW_HEIGHT), HA_WINDOWTITLE, B_DOCUMENT_WINDOW, B_ASYNCHRONOUS_CONTROLS)
{
	//Creating the FilePanel controls for opening and saving the file
	BMessenger msgr(NULL, this);
	openFilePanel = new BFilePanel(B_OPEN_PANEL, &msgr, NULL, 0, false, NULL, NULL, true);
	saveFilePanel = new BFilePanel(B_SAVE_PANEL, &msgr, NULL, 0, false, NULL, NULL, true);
	
	//Creating the topView BView
	topView = new BView(Bounds(), "topview", B_FOLLOW_ALL, B_WILL_DRAW);
	topView->SetViewColor(HA_WINDOW_TOPVIEW_COLOR);
	AddChild(topView);
	
	BuildLayout();
}

haMainWindow::~haMainWindow(void)
{
	delete openFilePanel;
	delete saveFilePanel;
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
		
		case HA_MENU_MESSAGE_HELP_TEST_POPEN:
		{
			TestPopen();
			break;	
		}
		
		case HA_MENU_MESSAGE_FILE_OPEN:
		{
			openFilePanel->Show();
			break;
		}
		
		case HA_MENU_MESSAGE_FILE_SAVE:
		{
			if(filePath.CountChars() < 1)
				saveFilePanel->Show();
			else
				SaveFile(filePath.String());
			break;
		}
		
		case HA_MENU_MESSAGE_FILE_SAVE_AS:
		{
			saveFilePanel->Show();
			break;
		}
		
//		case HA_MENU_MESSAGE_FILE_NEW:
//		{
//			int dResult = FileChangedDialog();
//			if(dResult == 2)
//			{
//				if(filePath.CountChars() < 1)
//					saveFilePanel->Show();
//				else
//					SaveFile(filePath.String());
//			}
//			if(dResult == 0)break;
//			editorView->SetText("");
//			filePath = "";
//			editorView->fileChanged = false;
//			SetWindowTitle();
//			break;
//		}
		
		case B_SAVE_REQUESTED:
		{
			entry_ref dir;
			BString name;
			if(msg->FindRef("directory", &dir) == B_OK && msg->FindString("name", &name) == B_OK)
			{
				BPath path(&dir);
				path.Append(name);
				SaveFile(path.Path());
			}
			break;
		}
		
		case B_REFS_RECEIVED:
		{
			printf("B_REFS_RECEIVED\n");
			entry_ref ref;
			if(msg->FindRef("refs", &ref) != B_OK)
				break;
			OpenFile(ref);
			break;
		}
		
		case HA_MESSAGE_EDITVIEW_CHANGED:
		{
			SetWindowTitle();
			break;
		}
		
//		case HA_MESSAGE_PROJECTVIEW_DOUBLECLICK:
//		{
//			haViewProjectTreeItem* item;
//			std::string path;
//			item = (haViewProjectTreeItem*)projectView->ItemAt(projectView->CurrentSelection());
//			path = item->filePath;
//			std::cout << item->filePath << std::endl;
//			
//			int dResult = FileChangedDialog();
//			if(dResult == 2)
//			{
//				if(filePath.CountChars() < 1)
//					saveFilePanel->Show();
//				else
//					SaveFile(filePath.String());
//			}
//			if(dResult == 0)break;
//			editorView->SetText("");
//			filePath = "";
//			editorView->fileChanged = false;
//			OpenFile(path.c_str());
//		}
		
		default:
		{
			BWindow::MessageReceived(msg);
			break;
		}
	}
}


bool haMainWindow::QuitRequested(void)
{
//	int dResult = FileChangedDialog();
//	if(dResult == 2)
//	{
//		if(filePath.CountChars() < 1)
//		saveFilePanel->Show();
//		else
//		SaveFile(filePath.String());
//	}
//	if(dResult == 0)return false;
	be_app->PostMessage(B_QUIT_REQUESTED);
	return true;
}

//Function OpenFile
//Opens the file with the given path/entry and fills the editorView
void haMainWindow::OpenFile(const entry_ref &ref)
{
	BEntry entry(&ref, true);
	entry_ref realRef;
	entry.GetRef(&realRef);
	
	BFile file(&realRef, B_READ_ONLY);
	if(file.InitCheck() != B_OK)
		return;
//		
//	if(BTranslationUtils::GetStyledText(&file, editorView) == B_OK)
//	{
//		BPath path(&realRef);
//		filePath = path.Path();
//		editorView->fileChanged = false;
//		SetWindowTitle();
//	}
			
}

//Function OpenFile (overwritten with path argument)
void haMainWindow::OpenFile(const char* path)
{
	BFile file(path, B_READ_ONLY);
	if(file.InitCheck() != B_OK)
		return;
	
//	if(BTranslationUtils::GetStyledText(&file, editorView) == B_OK)
//	{
//		filePath = path;
//		editorView->fileChanged = false;
//		editorView->StyleCompleteText();
//		SetWindowTitle();
//	}
	
}

//Function SaveFile
//Saves the content of the editorView in the file with the given path 
void haMainWindow::SaveFile(const char* path)
{
	BFile file;
	if(file.SetTo(path, B_READ_WRITE | B_CREATE_FILE | B_ERASE_FILE)  != B_OK)
		return;
	
//	if(BTranslationUtils::PutStyledText(editorView, &file) == B_OK)
//	{
//		filePath = path;
//		BNodeInfo nodeInfo(&file);
//		nodeInfo.SetType("text/plain");
//		editorView->fileChanged = false;
//		SetWindowTitle();
//	}
}

void haMainWindow::TestPopen(void)
{
	file = popen("ls -la 2>&1","r");
	while(fgets(buff, 1024, file)!=NULL)
	{
		outputView->Insert(buff);
	}	
	pclose(file);
}

//Function SetWindowTitle
//Set the MainWindow Title with the Application Name and the filename + an asterix if file was changed
void haMainWindow::SetWindowTitle()
{
	BString title = HA_WINDOWTITLE;
	BPath* path = new BPath(filePath);
	title += ": ";
	title += path->Leaf();
	if(editorView->fileChanged) title += " *";
	SetTitle(title);
}

//Function FileChangedDialog
//Asking if the file should be saved (if changed before)
int haMainWindow::FileChangedDialog(void)
{
	int alertResult;
	if(editorView->fileChanged)
	{
		BAlert* filechanged = new BAlert("File New", "File was changed, do you want to save it?", "Cancel", "Don't save", "Save", B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_WARNING_ALERT);
		filechanged->SetShortcut(0, B_ESCAPE);
		alertResult = filechanged->Go();
	}
	return alertResult;
}

//BuildLayout()
//Build the GUI
void haMainWindow::BuildLayout()
{	
		//MenuBar
		menuBar = new haMenuBar(Bounds(),"menubar");
		BRect sr = topView->Bounds();
		
		//StatusBar
		sr.top += sr.Height() - HA_STATUSBAR_HEIGHT;
		statusBar = new haStatusBar(sr,"statusBar");
			
		topView->AddChild(menuBar);
		topView->AddChild(statusBar);
		
		//ToolBar
		BRect mr = menuBar->Bounds();
		BRect tr = topView->Bounds();
		tr = topView->Bounds();
		tr.right = HA_TOOLBAR_WIDTH;
		tr.top += mr.Height() + 1;
		tr.bottom -= HA_STATUSBAR_HEIGHT + 1;
		toolBar = new haViewToolBar(tr, "toolbar");
		topView->AddChild(toolBar);
		
		//ProjectTree
		BRect pr = topView->Bounds();
		pr.top += mr.Height() + 1;
		pr.bottom -= HA_STATUSBAR_HEIGHT + 1;
		pr.right = HA_PROJECTVIEW_WIDTH + HA_TOOLBAR_WIDTH - B_V_SCROLL_BAR_WIDTH -5;
		pr.left = HA_TOOLBAR_WIDTH;
		projectView = new haViewProjectTree(pr, "projectview");
		projectView->scrollview = new BScrollView("projectscrollview",projectView,B_FOLLOW_TOP_BOTTOM,0,false,true);
		topView->AddChild(projectView->scrollview);
		
		//EditorView
		BRect er = topView->Bounds();
		er.top += mr.Height() + 1;
		er.bottom -= HA_STATUSBAR_HEIGHT + B_H_SCROLL_BAR_HEIGHT + HA_OUTPUTVIEW_HEIGHT + 1;
		er.left += HA_PROJECTVIEW_WIDTH + HA_TOOLBAR_WIDTH;
		er.right -= B_V_SCROLL_BAR_WIDTH;
		editorView = new haEditor(er, "editorview");
		editorView->scrollview = new BScrollView("editorscrollview",editorView,B_FOLLOW_ALL,0,true,true);
		topView->AddChild(editorView->scrollview);
		
		//OutputView
		BRect ovr = topView->Bounds();
		ovr.top = ovr.bottom - HA_STATUSBAR_HEIGHT - HA_OUTPUTVIEW_HEIGHT;
		ovr.bottom -=HA_STATUSBAR_HEIGHT + B_H_SCROLL_BAR_HEIGHT + 3;
		ovr.left += HA_PROJECTVIEW_WIDTH + HA_TOOLBAR_WIDTH;
		ovr.right -= B_V_SCROLL_BAR_WIDTH;
		outputView = new haViewOutput(ovr, "outputview");
		outputView->scrollview = new BScrollView("outputscrollview",outputView,B_FOLLOW_BOTTOM | B_FOLLOW_LEFT_RIGHT,0,true,true);
		topView->AddChild(outputView->scrollview);
		
		editorView->MakeFocus(true);
		
}


