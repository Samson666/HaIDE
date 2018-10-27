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
	textinset = BPoint(HA_STATUSBAR_INSET,HA_STATUSBAR_INSET);	
}

void haStatusBar::writeStatus(void)
{
	DrawString(status.c_str(),BPoint(textinset.x,(HA_STATUSBAR_HEIGHT/2)+textinset.y));
}

void haStatusBar::Draw(BRect updateRect)
{
		StrokeLine(BPoint(0,0), BPoint(Bounds().Width(),0));
		writeStatus();
		BView::Draw(updateRect);	
}
