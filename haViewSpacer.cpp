#include <View.h>
#include "haViewSpacer.h"
#include "haConstants.h"
#include <stdio.h>


haViewSpacer::haViewSpacer(const char* name)
				: BView(name, B_WILL_DRAW)
{
	SetViewColor(HA_TOOLBAR_COLOR);
	SetExplicitMaxSize(BSize(10000,10));

}

void haViewSpacer::Draw(BRect updateRect)
{
		
		//StrokeLine(BPoint(HA_TOOLBAR_WIDTH,0),BPoint(HA_TOOLBAR_WIDTH,Bounds().bottom));
		BView::Draw(updateRect);
}
