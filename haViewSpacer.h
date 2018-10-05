#ifndef HAVIEWSPACER_H
#define HAVIEWSPACER_H

#include <View.h>

class haViewSpacer : public BView
{
	public:
			haViewSpacer(const char* name);
			void Draw(BRect updateRect);
	
};

#endif
