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
#define HA_MENU_MESSAGE_FILE_QUIT 'MMFQ'

//Edit Menu
#define HA_MENU_MESSAGE_EDIT_CUT 'MMEC'
#define HA_MENU_MESSAGE_EDIT_PASTE 'MMEP'

//Project Menu
#define HA_MENU_MESSAGE_PROJECT_NEW 'MMPN'

//Help Menu
#define HA_MENU_MESSAGE_HELP_ABOUT 'MMHA'

//haMenuBar GERMAN
#ifdef HA_LANGUAGE_GERMAN
	#define HA_MENU_FILE "Datei"
		#define HA_MENU_FILE_OPEN "Öffnen"
		#define HA_MENU_FILE_CLOSE "Schließen"
		#define HA_MENU_FILE_SAVE "Speichern"
		#define HA_MENU_FILE_QUIT "Beenden"
	#define HA_MENU_EDIT "Bearbeiten"
		#define HA_MENU_EDIT_CUT "Kopieren"
		#define HA_MENU_EDIT_PASTE "Einfügen"
	#define HA_MENU_PROJECT "Projekt"
		#define HA_MENU_PROJECT_NEW "Neu"
	#define HA_MENU_HELP "Hilfe"
		#define HA_MENU_HELP_ABOUT "Über"
#endif //haMenuBar GERMAN

//haMenuBar ENGLISH
#ifdef HA_LANGUAGE_ENGLISH
	#define HA_MENU_FILE "File"
		#define HA_MENU_FILE_OPEN "Open"
		#define HA_MENU_FILE_CLOSE "Close"
		#define HA_MENU_FILE_SAVE "Save"
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

//StatusBar
#define HA_STATUSBAR_HEIGHT 20
#define HA_STATUSBAR_INSET 50
#define HA_STATUSBAR_COLOR rgb_color{200,200,200}
//__________________________________________________________________________________________

//ToolBar
#define HA_TOOLBAR_WIDTH 32
#define HA_TOOLBAR_COLOR rgb_color{180,180,180}

//Project View
#define HA_PROJECT_VIEW_COLOR rgb_color{180,180,180}

#endif // HACONSTANTS_H
