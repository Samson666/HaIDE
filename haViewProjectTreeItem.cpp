#include <string>
#include "haViewProjectTreeItem.h"

haViewProjectTreeItem::haViewProjectTreeItem(const char* text)
	: BStringItem(text)
{
	
}


haViewProjectTreeItem::haViewProjectTreeItem(const char* text, std::string path)
	: BStringItem(text)
{
	filePath = path;
}
