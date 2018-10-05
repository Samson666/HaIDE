#include <View.h>
#include "haViewToolBar.h"
#include "haConstants.h"
#include <stdio.h>


haViewToolBar::haViewToolBar(BRect frame, const char* name)
				: BView(frame, name, B_FOLLOW_LEFT | B_FOLLOW_TOP_BOTTOM, B_WILL_DRAW)
{
	SetViewColor(HA_TOOLBAR_COLOR);	

}

void haViewToolBar::Draw(BRect updateRect)
{
		
		BView::Draw(updateRect);
}
