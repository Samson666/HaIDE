#ifndef HAEDITOR_H
#define HAEDITOR_H

#include <string>
#include <View.h>
#include <Font.h>
#include <Looper.h>

class haEditor : public BView
{
	public:
		haEditor(BRect frame, const char* name);
		void Draw(BRect updateRect);
		BScrollView*	scrollview;
		void			Pulse();
		void			insertText(std::string text);
		void			DrawCursor();
		void			KeyDown(const char* bytes, int32 numBytes);
		
		
		std::string		editorText;
		BLooper*		looper;
		BFont			font;
		BPoint			textOffset;
		float			fontHeight;
		bool			fileChanged = false;
		int				currentCursorLine = 0;
		int				currentCursorPos = 0;
		float			currentCursorPosF = 0;
		bool			cursorVisible = false;
		int				textLength = 0;
};

#endif
