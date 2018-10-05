#ifndef HAPROJECT_H
#define HAPROJECT_H

#include <string>
#include <Path.h>

//static const char* projectTags[]
//{
//	"tagtest1", "tagtest2"
//};

class haProject
{
	public:
		haProject(std::string path);
	
		std::string		projectPath;
};	
	
#endif
