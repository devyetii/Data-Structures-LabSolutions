#include "ungratuated.h"


ungratuated::ungratuated(const char * name ,long long id ,int year ):student(name ,id)
{
	if (year>4||year<0)
	{
		this->year =0 ;//default value ;
	
	}
	else 
	{
		this->year=year ;
	
	}
}


ungratuated::~ungratuated(void)
{
}
void ungratuated:: printinfo()
{
	std::cout<<name <<std::endl;
	std::cout<<id <<std::endl ;
	std::cout<<year<<std::endl ;

}
char *  ungratuated::getname()
{

return name ;
}
long long ungratuated::getid()
{
	return id ;


}
bool ungratuated::pass()
{
	this->year++ ;
	if (year>4)
	{
		return 1 ;
	
	}  
	else 
	{
		return 0 ;
	}

}
