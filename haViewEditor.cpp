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


haViewEditor::haViewEditor(BRect frame, const char* name)
			: BTextView(frame, name, BRect(5,5,10000,10000), B_FOLLOW_ALL,B_WILL_DRAW|B_PULSE_NEEDED)
{
	SetStylable(true);
	//font.SetSize(30.0);
}

void haViewEditor::Draw(BRect updateRect)
{
	
	BTextView::Draw(updateRect);
	
	//printf("View Editor: draw\n");		
}

void haViewEditor::InsertText(const char* text, int32 length, int32 offset, const text_run_array* runs)
{
	fileChanged = true;
	BLooper* looper = Looper();
	looper->PostMessage(HA_MESSAGE_EDITVIEW_CHANGED);
	rgb_color black = rgb_color{0,0,0};
	//Setting the color to Black
	SetFontAndColor(0,0,&font, B_FONT_ALL, &black);
	BTextView::InsertText(text, length, offset, runs);
	StyleText(offset, length);
}


void haViewEditor::DeleteText(int32 start, int32 finish)
{
	fileChanged = true;
	BLooper* looper = Looper();
	looper->PostMessage(HA_MESSAGE_EDITVIEW_CHANGED);
	BTextView::DeleteText(start, finish);
	StyleCompleteText();
}

//Styling the editorView text depending on words
void haViewEditor::StyleText(int32 offset, int32 length)
{
	rgb_color green = rgb_color{0,200,0};
	rgb_color black = rgb_color{0,0,0};
	std::string text;
	std::string lineText = Text();
	text=Text();
	//printf("Style Text length offset %d %d\n", length, offset);
	size_t pos=offset;
	
	int32 currentLine = CurrentLine();
	int i=0;
	std::cout << "Current Line" << currentLine <<std::endl;
	if(currentLine == 1)
	{
		i=text.find('\n',0);
		if(i >= 0)std::cout << "found new line at " << i << std::endl;
	}
		
	if((pos=text.find("#include",pos-8))!= std::string::npos)
	{
		SetFontAndColor(pos,pos+8,&font, B_FONT_ALL, &green);
		//std::cout << "found #include at " << pos << std::endl;
	}
}

void haViewEditor::StyleCompleteText()
{
	rgb_color green = rgb_color{0,200,0};
	rgb_color black = rgb_color{0,0,0};
	std::string text(Text());
	size_t length = text.length();
	size_t pos = 0;
	

	for(size_t i=pos; i<=(size_t)length + 8; i++)
	{
		std::cout << "searching #include at" << i << std::endl;
		if((pos=text.find("#include", i-8)) != std::string::npos)
		{
			SetFontAndColor(pos,pos+8,&font, B_FONT_ALL, &green);
			std::cout << "found #include at " << pos << std::endl;
			i=pos + 8;
		}
		if(i>(size_t)length)return;
	}
}

void haViewEditor::AttachedToWindow()
{
	BTextView::AttachedToWindow();
}
