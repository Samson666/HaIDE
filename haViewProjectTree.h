#ifndef HAVIEWPROJECTTREE_H
#define HAVIEWPROJECTTREE_H

#include <OutlineListView.h>
#include <string>
#include <StringItem.h>
#include "haConstants.h"
#include "haProject.h"


class haViewProjectTree : public BOutlineListView
{
	public:
			haViewProjectTree(BRect frame, const char* name);
			void	getProjectDir(std::string path, BStringItem* parent);
			haProject*	project;
			
			BScrollView*	scrollview;
};


#endif
