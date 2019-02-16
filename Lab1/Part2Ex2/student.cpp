#include "student.h"


student::student(const char * name ,long long id )
{
	int size  =strlen(name ) ;
	this->name=new char [size +1 ] ;
	strcpy(this->name,name );
	this->id=id ;
}
student::~student(void)
{
}
