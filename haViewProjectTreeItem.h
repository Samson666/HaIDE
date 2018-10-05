#ifndef HAVIEWPROJECTTREEITEM_H
#define HAVIEWPROJECTTREEITEM_H

#include <string>
#include <StringItem.h>
#include <Entry.h>


class haViewProjectTreeItem : public BStringItem
{
	public:
			haViewProjectTreeItem(const char* text);
			haViewProjectTreeItem(const char* text, std::string path);
			std::string	filePath;
			
};



#endif
