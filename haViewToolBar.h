#ifndef HAVIEWTOOLBAR_H
#define HAVIEWTOOLBAR_H

#include <View.h>
#include <Box.h>

class haViewToolBar : public BView
{
	public:
			haViewToolBar(BRect frame, const char* name);
			void Draw(BRect updateRect);
	
};


#endif
