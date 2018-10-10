//for Debug reasons
#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>

//includes
#include "haConstants.h"
#include "haEditor.h"


haEditor::haEditor(BRect frame, const char* name)
			: BView(frame, name, B_FOLLOW_ALL, B_WILL_DRAW | B_PULSE_NEEDED)
{
	looper = new BLooper();
	GetFont(&font);
	//font.SetSize(30.0);
	//SetFont(&font);
	font_height fHeight;
	font.GetHeight(&fHeight);
	fontHeight = fHeight.ascent + fHeight.descent;
	addLine("This a Text");
	addLine("{Another Text");
	addLine("{Blubbel}{i}");
	insertLine("blabla", 1);
	insertLine("blabla1", 1);
	insertLine("blabla7}", 0);
}

void haEditor::Draw(BRect updateRect)
{
	SetHighColor(HA_EDIT_VIEW_TEXT_COLOR);
	int i=1;
	for( std::string s : editorLines)
	{
		MovePenTo(0, fontHeight  * i);
		DrawString(s.c_str());	
		i++;
	}
	
	DrawCursor();
	BView::Draw(updateRect);
}

void haEditor::DrawCursor()
{
	SetHighColor(255,0,0);
	SetCurrentCursorPosF();	
	font_height fHeight;
	font.GetHeight(&fHeight);
	MovePenTo(currentCursorPosF, (float)currentLine * fontHeight + fHeight.descent);
	if(cursorVisible)
		StrokeLine(BPoint(currentCursorPosF,(float)currentLine * fontHeight - fHeight.ascent));
	else
		StrokeLine(BPoint(currentCursorPosF,(float)currentLine * fontHeight - fHeight.ascent), B_SOLID_LOW);
	//only invalidate the cursor rect
	Invalidate(BRect(currentCursorPosF,(float)currentLine * fontHeight - fHeight.ascent,currentCursorPosF,(float)currentLine * fontHeight + fHeight.descent));
}

void haEditor::SetCurrentCursorPosF()
{
	std::string actline;
	int i=1;
	for( std::string s : editorLines)
	{	
		actline = s;
		i++;
		if(i>currentLine)break;
	}
	//std::cout << "Cursor active line" << actline.substr(0,currentCursorPos) << std::endl;
	currentCursorPosF = font.StringWidth(actline.substr(0,currentCursorPos).c_str());
}

//adding Text add the end of the editorLines list
void haEditor::addLine(std::string text)
{
	editorLines.push_back(text);
	currentCursorPosF = font.StringWidth(text.c_str());
	currentCursorPos = text.length();
	lineCount++;
	currentLine = lineCount;
	Invalidate();
}

void haEditor::insertLine(std::string text, int pos)
{
	std::list<std::string>::iterator it;
	it = editorLines.begin();
	for(int i=0; i<pos; i++)
		it++;
	editorLines.insert(it, text);
	currentCursorPosF = font.StringWidth(text.c_str());
	currentCursorPos = text.length();
	currentLine = pos+1;
	lineCount++;
	Invalidate();
}

void haEditor::KeyDown(const char* bytes, int32 numBytes)
{
	//std::cout << "KeyDown received\n" << std::endl;
	//std::cout << bytes[0] << std::endl;
	switch(bytes[0])
	{
		case B_LEFT_ARROW:
		{
			std::cout << "Left Arrow key" << std::endl;
			currentCursorPos--;
			DrawCursor();
			break;
		}
		
		case B_RIGHT_ARROW:
		{
			std::cout << "Right Arrow key" << std::endl;
			currentCursorPos++;
			DrawCursor();
			break;
		}
		
		case B_UP_ARROW:
		{
			std::cout << "Up Arrow key" << std::endl;
			if(currentLine>1)
			{
				currentLine--;
				DrawCursor();
			}
			break;
		}
		
		case B_DOWN_ARROW:
		{
			std::cout << "Down Arrow key" << std::endl;
			if(currentLine<lineCount)
			{
				currentLine++;
				DrawCursor();
			}
			break;
		}
	}
	
}

//Reading file from given filepath and put it our view
void haEditor::ReadFile(const char* filepath)
{
	//std::cout << "ReadFile " << filepath << std::endl;
	std::string line;
	std::ifstream myfile(filepath);
	if(myfile.is_open())
	{
		while( getline (myfile, line))
		{
			//std::cout << "new line read" << std::endl;
			//std::cout << line << std::endl;
			//filtering out styled text tags
			if((line.compare(0,4,"STXT")!=0) && (line.compare(0,4,"STYL")!=0))
				addLine(line);
		}
		myfile.close();
		MakeFocus(true);
	}
	else std::cout << "unable to open file" << std::endl;
}

void haEditor::SaveFile(const char* filepath)
{
	//std::cout << "Saving File " << filepath << std::endl;
	std::ofstream myfile(filepath);
	if(myfile.is_open())
	{
		for( std::string s : editorLines)
			myfile << s << std::endl;
		myfile.close();
	}
}

void haEditor::ClearText()
{
	//clear the lines list
	editorLines.clear();
	
	//setting all cursor and line position to 0
	lineCount = 0;
	currentLine = 0;
	currentCursorPos = 0;
	currentCursorPosF = 0;
	
}

void haEditor::Pulse()
{
	cursorVisible = !cursorVisible;
	//Invalidate();
}

