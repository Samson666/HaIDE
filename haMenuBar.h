#ifndef HAMENUBAR_H
#define HAMENUBAR_H

#include <string>
#include <MenuBar.h>
#include <MenuItem.h>

class haMenuBar : public BMenuBar
{
	public:
		haMenuBar(BRect frame, const char* name);
};

#endif //HAMENUBAR_H
