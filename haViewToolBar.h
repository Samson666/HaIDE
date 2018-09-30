#ifndef HAVIEWTOOLBAR_H
#define HAVIEWTOOLBAR_H

#include <View.h>

class haViewToolBar : public BView
{
	public:
			haViewToolBar(const char* name);
			void Draw(BRect updateRect);
	
};


#endif
