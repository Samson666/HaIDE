/*
____________________________________________________________________
	Filename:		haViewStatusBar.cpp
	Author:			Johannes Jung			
	Copyright:		2018 Johannes Jung <johannes.jung@masacom.de>
	Description:	definition of haStatusBar class
____________________________________________________________________	
*/

#include "haViewStatusBar.h"
#include "haConstants.h"

haStatusBar::haStatusBar(const char* name)
				: BView(name, B_WILL_DRAW)
{
	SetExplicitMaxSize(BSize(10000, HA_STATUSBAR_HEIGHT));
	text = new BStringView(BRect(HA_STATUSBAR_INSET,0,1000,20),"text","StatusBar");
	//AddChild(text);
	SetViewColor(HA_STATUSBAR_COLOR);

	
}

void haStatusBar::Draw(BRect updateRect)
{
		StrokeLine(BPoint(0,0), BPoint(Bounds().Width(),0));
		BView::Draw(updateRect);	
}
