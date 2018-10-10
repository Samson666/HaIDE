//for Debug reasons
#include <string>
#include <iostream>
#include <stdio.h>

//includes
#include "haEditor.h"

haEditor::haEditor(BRect frame, const char* name)
			: BView(frame, name, B_FOLLOW_ALL, B_WILL_DRAW | B_PULSE_NEEDED)
{
	looper = new BLooper();
	GetFont(&font);
	font_height fHeight;
	font.GetHeight(&fHeight);
	fontHeight = fHeight.ascent + fHeight.descent;
}

void haEditor::Draw(BRect updateRect)
{
	currentCursorLine = 0;
	SetHighColor(0,200,0);
	MovePenTo(0,fontHeight);
	insertText("This is a Text String");
	SetHighColor(200,0,0);
	insertText("This is a Text String 2");
	DrawCursor();
	BView::Draw(updateRect);
}

void haEditor::DrawCursor()
{
	SetHighColor(0,0,200);
	MovePenTo(currentCursorPosF,currentCursorLine * fontHeight);
	if(cursorVisible)
		DrawString("!");
	else
		DrawString(" ");
}

void haEditor::insertText(std::string text)
{
	editorText.append(text);
	editorText+='\n';
	std::cout << editorText << std::endl;
	MovePenTo(0, fontHeight * (currentCursorLine + 1));
	currentCursorLine ++;
	currentCursorPos = text.length();
	currentCursorPosF = font.StringWidth(text.c_str());
	DrawString(text.c_str());
}


void haEditor::KeyDown(const char* bytes, int32 numBytes)
{
	std::cout << "KeyDown received\n" << std::endl;
	std::cout << bytes[0] << std::endl;
	MovePenTo(10,100);
	DrawChar(bytes[0]);
	Invalidate();
}
void haEditor::Pulse()
{
	cursorVisible = !cursorVisible;
	Invalidate();
}

