/*
____________________________________________________________________
	Filename:		haViewStatusBar.h
	Author:			Johannes Jung			
	Copyright:		2018 Johannes Jung <johannes.jung@masacom.de>
	Description:	declaration of haStatusBar class
____________________________________________________________________	
*/

#ifndef HAVIEWSTATUSBAR_H
#define HAVIEWSTATUSBAR_H

#include <string>
#include <View.h>
#include <StringView.h>



class haStatusBar : public BView
{
	public:
			haStatusBar(const char* name);
			void Draw(BRect updateRect);
			std::string status;
			BStringView* text;
	
};

#endif
