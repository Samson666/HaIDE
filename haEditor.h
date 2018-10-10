#ifndef HAEDITOR_H
#define HAEDITOR_H

#include <string>
#include <View.h>
#include <list>
#include <vector>
#include <Font.h>
#include <Looper.h>
#include <File.h>

class haEditor : public BView
{
	public:
		haEditor(BRect frame, const char* name);
		void Draw(BRect updateRect);
		
		
		void			Pulse();
		void			addLine(std::string text);
		void 			addChar(const char* c);
		void			deleteChar();
		void 			insertLine(std::string text, int pos);
		void			newLine();
		void			deleteLine();
		void			DrawCursor();
		void			KeyDown(const char* bytes, int32 numBytes);
		void			MouseDown(BPoint where);
		void			MouseUp(BPoint where);
		void			MouseMoved(BPoint where, uint32 code, const BMessage* dragMessage);
		void			ReadFile(const char* filepath);
		void			SaveFile(const char* filepath);
		void			ClearText();
		void			SetCurrentCursorPosF();
		void			CoordsToCursor(BPoint mousecoords);
		
		std::vector<std::string> editorLines;
		
		bool			mouseIsDown = false;
		bool			mouseIsUp = false;
		BScrollView*	scrollview;
		BLooper*		looper;
		BFont			font;
		BPoint			textOffset;
		float			fontHeight;
		bool			fileChanged = false;
		int				lineCount = 0;
		int				currentLine = 1;
		int				currentCursorPos = 0;
		float			currentCursorPosF = 0;
		bool			cursorVisible = false;
		int				textLength = 0;
};

#endif
