#ifndef HAEDITOR_H
#define HAEDITOR_H

#include <string>
#include <View.h>
#include <list>
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
		void 			insertLine(std::string text, int pos);
		void			DrawCursor();
		void			KeyDown(const char* bytes, int32 numBytes);
		void			ReadFile(const char* filepath);
		void			SaveFile(const char* filepath);
		void			ClearText();
		
		std::list<std::string> editorLines;
		
		BScrollView*	scrollview;
		BLooper*		looper;
		BFont			font;
		BPoint			textOffset;
		float			fontHeight;
		bool			fileChanged = false;
		int				lineCount = 0;
		int				currentLine = 0;
		int				currentCursorPos = 0;
		float			currentCursorPosF = 0;
		bool			cursorVisible = false;
		int				textLength = 0;
};

#endif
