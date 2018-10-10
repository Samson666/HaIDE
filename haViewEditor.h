#ifndef HAVIEWEDITOR_H
#define HAVIEWEDITOR_H

#include <TextView.h>
#include <ScrollView.h>
#include <string>
#include <Font.h>

class haViewEditor : public BTextView
{
	public:
			haViewEditor(BRect frame, const char* name);
			void Draw(BRect updateRect);
			void InsertText(const char* text, int32 length, int32 offset, const text_run_array* runs);
			void DeleteText(int32 start, int32 finish);
			void StyleText(int32 offset, int32 length);
			void StyleCompleteText();
			void AttachedToWindow();
			
			BFont			font;
			BScrollView*	scrollview;
			bool			fileChanged = false;
			std::string		buf;
			
};

#endif
