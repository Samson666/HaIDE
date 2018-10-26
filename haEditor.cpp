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
	GetFont(&font);
	//font.SetSize(20.0);
	//SetFont(&font);
	font_height fHeight;
	font.GetHeight(&fHeight);
	fontHeight = fHeight.ascent + fHeight.descent;
	addLine(""); //creating an empty line at the beginning of the text
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
	BLooper* l = Looper();
	l->PostMessage(HA_MESSAGE_EDITVIEW_STATUS_CHANGED);
}

void haEditor::DrawCursor()
{
	if(!IsFocus())return;
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

int haEditor::GetCurrentLineLength()
{
	std::string line = editorLines[currentLine-1];
	return(line.length());
}

//setting currentCursorPosF to the end of currentLine in coordinates (Pixels)
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

//adding text line add the end of the editorLines list
void haEditor::addLine(std::string text)
{
	editorLines.push_back(text);
	currentCursorPosF = font.StringWidth(text.c_str());
	currentCursorPos = text.length();
	lineCount++;
	currentLine = lineCount;
	Invalidate();
}

//inserting text line at pos
void haEditor::insertLine(std::string text, int pos)
{
	std::vector<std::string>::iterator it;
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

//inserting a character at currentLine/currentCursorPos
void haEditor::addChar(const char* c)
{
	std::string line = editorLines[currentLine-1];
	if(currentCursorPos > (int)line.length())currentCursorPos = line.length(); //check if the position is in limit
	line.insert(currentCursorPos++,c);
	editorLines[currentLine-1]=line;
	Invalidate();
}

//deleting a character at currentLine/currentCursorPos
void haEditor::deleteChar()
{
	std::string line = editorLines[currentLine-1];
	line.erase(--currentCursorPos, 1);
	editorLines[currentLine-1]=line;
	Invalidate();
	printf("Delete Char\n");
}

//inserting a new line after the current line
void haEditor::newLine()
{
	insertLine("", currentLine);
}

void haEditor::deleteLine(int line)
{	
	if(line > 1)
	{
		editorLines.erase(editorLines.begin()+line);
		//currentLine--;
		lineCount--;
		Invalidate();
	}
	
}

//Messages
//KeyDown
void haEditor::KeyDown(const char* bytes, int32 numBytes)
{
	//std::cout << "KeyDown received\n" << std::endl;
	//std::cout << bytes[0] << std::endl;
	switch(bytes[0])
	{
		//moving cursor
		case B_LEFT_ARROW:
		{			
			if(currentCursorPos>0) //is cursor not at first position in the line?
			{
				currentCursorPos--;	//move cursor one position to the left
				DrawCursor();
			}
			else //move cursor on line up
				if(currentLine > 1)	//is the current line not the first line?
				{
					currentLine--;	//move cursor one line up
					currentCursorPos = GetCurrentLineLength(); //move the cursor to end of the line
					DrawCursor();
				}
			break;
		}
		
		case B_RIGHT_ARROW:
		{
			if(currentCursorPos < (int)editorLines[currentLine-1].length()) //is cursor not at the end of the line?
			{
				currentCursorPos++;	//move cursor one position to the right
				DrawCursor();
			}
			break;
		}
		
		case B_UP_ARROW:
		{
			if(currentLine>1) //is the current line not the first line?
			{
				currentLine--; //move cursor one line up
				if(currentCursorPos > GetCurrentLineLength())currentCursorPos = GetCurrentLineLength(); //check if the position is in limit
				DrawCursor();
			}
			break;
		}
		
		case B_DOWN_ARROW:
		{
			if(currentLine<lineCount) //is the current line not the last line?
			{
				currentLine++; //move cursor one line down
				if(currentCursorPos > GetCurrentLineLength())currentCursorPos = GetCurrentLineLength(); //check if the position is in limit
				DrawCursor();
			}
			break;
		}
		
		case B_BACKSPACE:
		{
			if(currentCursorPos>0)
				deleteChar();
			else
				if(currentLine > 1)
				{
					currentLine--;
					deleteLine(currentLine);
				}
			break;
		}
		
		case B_ENTER:
		{
			newLine();
			break;
		}	
		
		default:
		{
			addChar(bytes);
			break;
		}
	}
	
	
}

//MouseDown
void haEditor::MouseDown(BPoint where)
{
	MakeFocus(true);
	mouseIsDown = true;

	CoordsToCursor(where);
	DrawCursor();
}

//MouseUp
void haEditor::MouseUp(BPoint where)
{
	mouseIsDown = false;
}

//MouseMove
//!!! adding here code to mark/unmark characters !!!
void haEditor::MouseMoved(BPoint where, uint32 code, const BMessage* dragMessage)
{
	//std::cout << "Mouse Moved" << std::endl;
	BView::MouseMoved(where, code, dragMessage);	
}

//finding the line and char at mousecoords and set the cursor 
void haEditor::CoordsToCursor(BPoint mousecoords)
{
	//getting the mouse coordinates in the editorView
	float mx = mousecoords.x;
	float my = mousecoords.y;
	
	//getting the height of the used font
	font_height fHeight;
	font.GetHeight(&fHeight);
	
	//!!!!! Hier Optimieren!!!!!
	for(int i = 1; i <= lineCount; i++)
	{
		float l = i * fontHeight;
		float lt = l - fHeight.ascent;
		float lb = l + fHeight.descent;
		if(my >=lt && my <=lb)
		{
			currentLine = i;
			break;
		}
	}
	
	std::string actline;
	int i=1;
	for( std::string s : editorLines)
	{	
		actline = s;
		i++;
		if(i>currentLine)break;
	}
	//tricky trying to get the font width :-) Its ok since we are using only a single font size...
	float fontwidth = font.StringWidth(actline.c_str()) / actline.length();
	currentCursorPos = mx/fontwidth;
	if(currentCursorPos < 0)currentCursorPos = 0; //dont let cursor position less then zero!
	DrawCursor();	 	
}

//Reading file from given filepath and put it our view
void haEditor::ReadFile(const char* filepath)
{
	std::string line;
	std::ifstream myfile(filepath);
	if(myfile.is_open())
	{
		while( getline (myfile, line))
		{
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

