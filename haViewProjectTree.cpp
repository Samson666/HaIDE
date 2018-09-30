#include "haViewProjectTree.h"
#include "haConstants.h"

haViewProjectTree :: haViewProjectTree(const char* name)
		: BOutlineListView(name)
{
	SetViewColor(HA_PROJECT_VIEW_COLOR);
	BListItem* test1 = new BStringItem("Test1");
	BListItem* test2 = new BStringItem("Test2");
	AddItem(test1);
	AddUnder(test2, test1);
	AddItem(new BStringItem("Test3"));
}
