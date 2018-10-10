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

haStatusBar::haStatusBar(BRect frame, const char* name)
				: BView(frame, name, B_FOLLOW_BOTTOM | B_FOLLOW_LEFT_RIGHT,B_WILL_DRAW)
{
	//SetViewColor(HA_STATUSBAR_COLOR);
	//status = "StatusBar";
	textinset = BPoint(3,5);

	
}

void haStatusBar::writeStatus(void)
{
	DrawString("                  ",BPoint(textinset.x,(HA_STATUSBAR_HEIGHT/2)+textinset.y));
	DrawString(status.c_str(),BPoint(textinset.x,(HA_STATUSBAR_HEIGHT/2)+textinset.y));
}

void haStatusBar::Draw(BRect updateRect)
{
		SetHighColor(HA_EDIT_VIEW_TEXT_COLOR);
		StrokeLine(BPoint(0,0), BPoint(Bounds().Width(),0));
		writeStatus();
		BView::Draw(updateRect);	
}
