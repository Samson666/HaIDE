/*
____________________________________________________________________
	Filename:		haViewOutput.cpp
	Author:			Johannes Jung			
	Copyright:		2018 Johannes Jung <johannes.jung@masacom.de>
	Description:	definition of haViewOutput class
____________________________________________________________________	
*/

#include "haViewOutput.h"
#include "haConstants.h"
#include <stdio.h>

haViewOutput::haViewOutput(BRect frame, const char* name)
			: BTextView(frame, name, BRect(5,5,10000,10000), B_FOLLOW_ALL,B_WILL_DRAW)
{
	MakeEditable(false);
}

void haViewOutput::Draw(BRect updateRect)
{
	BTextView::Draw(updateRect);		
}

void haViewOutput::InsertText(const char* text, int32 length, int32 offset, const text_run_array* runs)
{
	BTextView::InsertText(text, length, offset, runs);
}
