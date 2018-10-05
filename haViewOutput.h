/*
____________________________________________________________________
	Filename:		haViewOutput.h
	Author:			Johannes Jung			
	Copyright:		2018 Johannes Jung <johannes.jung@masacom.de>
	Description:	declaration of haViewOutput class
____________________________________________________________________	
*/

#ifndef HAVIEWOUTPUTTAB_H
#define HAVIEWOUTPUTTAB_H

#include <TextView.h>
#include <ScrollView.h>

class haViewOutput : public BTextView
{
	public:
			haViewOutput(BRect frame, const char* name);
			void Draw(BRect updateRect);
			void InsertText(const char* text, int32 length, int32 offset, const text_run_array* runs);
			BScrollView*	scrollview;
			
};

#endif
