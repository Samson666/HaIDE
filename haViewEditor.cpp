#include <stdio.h>
#include <string.h>
#include <string>
#include <Application.h>
#include <Looper.h>
#include <Handler.h>
#include <Message.h>
#include <iostream>
#include <Font.h>
#include <TextView.h>

#include "haConstants.h"
#include "haViewOutput.h"
#include "haMainWindow.h"
#include "haViewEditor.h"


haViewEditor::haViewEditor(BRect frame, const char* name, BFont* font, const rgb_color* color)
			: BTextView(frame, name, BRect(5,5,10000,10000), font, color, B_FOLLOW_ALL,B_WILL_DRAW|B_PULSE_NEEDED)
{
	SetStylable(true);
}

void haViewEditor::Draw(BRect updateRect)
{
	BTextView::Draw(updateRect);		
}

void haViewEditor::InsertText(const char* text, int32 length, int32 offset, const text_run_array* runs)
{
	std::string textcopy(text);
	fileChanged = true;
	BLooper* looper = Looper();
	looper->PostMessage(HA_MESSAGE_EDITVIEW_CHANGED);
	textcopy = StyleText(textcopy);
	std::cout << textcopy << std::endl;
	BTextView::InsertText(textcopy.c_str(), length, offset, runs);
	
}


void haViewEditor::DeleteText(int32 start, int32 finish)
{
	fileChanged = true;
	BLooper* looper = Looper();
	looper->PostMessage(HA_MESSAGE_EDITVIEW_CHANGED);
	BTextView::DeleteText(start, finish);
}

//Styling the editorView text depending on words
std::string haViewEditor::StyleText(std::string text)
{
	std::cout << "Style Text" << std::endl;
	std::string::size_type pos=0;
	//pos = text.find("#");
	while((pos=text.find("#"))!= std::string::npos)
	{
		text.replace(pos,1,"?");
		std::cout << "found # at " << pos << std::endl;	
		std::cout << text << std::endl;
		pos++;
	}
	return text;
}

void haViewEditor::AttachedToWindow()
{
	BTextView::AttachedToWindow();
}
