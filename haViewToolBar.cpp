#include <View.h>
#include "haViewToolBar.h"
#include "haConstants.h"
#include <stdio.h>


haViewToolBar::haViewToolBar(const char* name)
				: BView(name, B_WILL_DRAW)
{
	SetExplicitMaxSize(BSize(HA_TOOLBAR_WIDTH, 10000));
	SetViewColor(HA_TOOLBAR_COLOR);
	Draw(Frame());

}

void haViewToolBar::Draw(BRect updateRect)
{
		StrokeLine(BPoint(0,0),BPoint(10,100));
		BView::Draw(updateRect);
}
