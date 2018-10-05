#include <iostream>
#include <Directory.h>
#include <Path.h>
#include <Message.h>
#include "haViewProjectTree.h"
#include "haViewProjectTreeItem.h"
#include "haConstants.h"
#include "haProject.h"
#include "Entry.h"

haViewProjectTree :: haViewProjectTree(BRect frame, const char* name)
		: BOutlineListView(frame, name, B_SINGLE_SELECTION_LIST, B_FOLLOW_LEFT | B_FOLLOW_TOP_BOTTOM)
{
	SetViewColor(HA_PROJECTVIEW_COLOR);
	SetInvocationMessage(new BMessage(HA_MESSAGE_PROJECTVIEW_DOUBLECLICK));
	MakeEmpty();
	project = new haProject("/boot/home/Desktop/Projects/projtest1");
	haViewProjectTreeItem* parent = new haViewProjectTreeItem("Project");
	AddItem(parent);
	getProjectDir(project->projectPath, parent);
}

//Filling the ProjectTreeView with the directory given by path
void haViewProjectTree::getProjectDir(std::string path, BStringItem* parent)
{
	BEntry* entry = new BEntry();
	BPath*	fpath = new BPath();
	
	char name[1024];
	
	BDirectory* dir = new BDirectory(path.c_str());
	while(dir->GetNextEntry(entry) == B_OK)
	{
		entry->GetName(name);
		if(entry->IsDirectory())
		{
			entry->GetPath(fpath);
			haViewProjectTreeItem* item = new haViewProjectTreeItem(name, fpath->Path());
			AddUnder(item, parent);
			Collapse(parent);
			getProjectDir(fpath->Path(), item);
		}
		if(entry->IsFile())
		{
			entry->GetPath(fpath);			
			AddUnder(new haViewProjectTreeItem(name, fpath->Path()), parent);
		}
	}
}

	
