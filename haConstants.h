/*
__________________________________________________
	Filename:		haConstants.h
	Author:			Johannes Jung			
	Copyright:		2018 Johannes Jung <johannes.jung@masacom.de>
	Description:	Definition of global constants for HaIDE project
__________________________________________________	
*/


#ifndef HACONSTANTS_H
#define HACONSTANTS_H

#define HA_LANGUAGE_GERMAN

//------------------------------------------------------------------------------------------
//haMainWindow
#define HA_WINDOWTITLE	"HaIDE"
#define HA_WINDOW_WIDTH 700
#define HA_WINDOW_HEIGHT 500
#define HA_WINDOW_TOPVIEW_COLOR rgb_color{255,255,255}
#define HA_WINDOW_SPLIT_SEPERATOR_WIDTH 0

//------------------------------------------------------------------------------------------
//haMenuBar

//haMenuBar message constants
//File Menu
#define HA_MENU_MESSAGE_FILE_OPEN 'MMFO'
#define HA_MENU_MESSAGE_FILE_CLOSE 'MMFC'
#define HA_MENU_MESSAGE_FILE_SAVE 'MMFS'
#define HA_MENU_MESSAGE_FILE_SAVE_AS 'MMSA'
#define HA_MENU_MESSAGE_FILE_QUIT 'MMFQ'
#define HA_MENU_MESSAGE_FILE_NEW 'MMFN'

//Edit Menu
#define HA_MENU_MESSAGE_EDIT_CUT 'MMEC'
#define HA_MENU_MESSAGE_EDIT_PASTE 'MMEP'

//Project Menu
#define HA_MENU_MESSAGE_PROJECT_NEW 'MMPN'

//Help Menu
#define HA_MENU_MESSAGE_HELP_ABOUT 'MMHA'
#define HA_MENU_MESSAGE_HELP_TEST_POPEN 'MMTP'

//haMenuBar GERMAN
#ifdef HA_LANGUAGE_GERMAN
	#define HA_MENU_FILE "Datei"
		#define HA_MENU_FILE_OPEN "Öffnen ..."
		#define HA_MENU_FILE_CLOSE "Schließen"
		#define HA_MENU_FILE_SAVE "Speichern"
		#define HA_MENU_FILE_SAVE_AS "Speichern unter..."
		#define HA_MENU_FILE_NEW "Neu"
		#define HA_MENU_FILE_QUIT "Beenden"
	#define HA_MENU_EDIT "Bearbeiten"
		#define HA_MENU_EDIT_CUT "Kopieren"
		#define HA_MENU_EDIT_PASTE "Einfügen"
	#define HA_MENU_PROJECT "Projekt"
		#define HA_MENU_PROJECT_NEW "Neu"
	#define HA_MENU_HELP "Hilfe"
		#define HA_MENU_HELP_ABOUT "Über"
		#define HA_MENU_HELP_TEST_POPEN "Test popen"
#endif //haMenuBar GERMAN

//haMenuBar ENGLISH
#ifdef HA_LANGUAGE_ENGLISH
	#define HA_MENU_FILE "File"
		#define HA_MENU_FILE_OPEN "Open"
		#define HA_MENU_FILE_CLOSE "Close"
		#define HA_MENU_FILE_SAVE "Save"
		#define HA_MENU_FILE_SAVE_AS "Save as..."
		#define HA_MENU_FILE_NEW "New"
		#define HA_MENU_FILE_QUIT "Quit"
	#define HA_MENU_EDIT "Edit"
		#define HA_MENU_EDIT_CUT "Copy"
		#define HA_MENU_EDIT_PASTE "Paste"
	#define HA_MENU_PROJECT "Project"
		#define HA_MENU_PROJECT_NEW "New"
	#define HA_MENU_HELP "Help"
		#define HA_MENU_HELP_ABOUT "About"
#endif //haMenuBar ENGLISH

//__________________________________________________________________________________________

//haViewStatusBar
#define HA_STATUSBAR_HEIGHT 20
#define HA_STATUSBAR_INSET 50
#define HA_STATUSBAR_COLOR rgb_color{200,200,200}
//__________________________________________________________________________________________

//haViewToolBar
#define HA_TOOLBAR_WIDTH 32
#define HA_TOOLBAR_COLOR rgb_color{200,200,200}

//haViewProjectTree
#define HA_PROJECTVIEW_COLOR rgb_color{180,180,180}
#define HA_PROJECTVIEW_WIDTH 200
#define HA_MESSAGE_PROJECTVIEW_DOUBLECLICK 'mpvd'
#define HA_MESSAGE_PROJECTVIEW_SELECTED 'mpvs'

//haViewEdit
#define HA_EDITVIEW_INSET 5
#define HA_MESSAGE_EDITVIEW_CHANGED 'MEVC'
#define HA_MESSAGE_EDITVIEW_STATUS_CHANGED 'MEVS'
#define HA_EDIT_VIEW_TEXT_COLOR rgb_color{0,0,0}

//haViewOuput
#define HA_OUTPUTVIEW_HEIGHT 100

#endif // HACONSTANTS_H
