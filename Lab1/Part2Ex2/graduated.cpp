#include "graduated.h"


graduated::graduated(const char * name,long long id ,int year ):student(name ,id)
{
	gradyear=year ;
}


graduated::~graduated(void)
{
}
void  graduated ::printinfo()
{
	std::cout<<name <<std::endl ;
	std::cout<<id <<std::endl; 
	std::cout<<	gradyear<<std::endl ; 
}
long long graduated::getid()
{

	return this->id ;

}
char * graduated::getname()
{
return name ;
}
/*graduated::graduated(const ungratuated& other):student(other.getname(),other.getid())
{
	

}*/