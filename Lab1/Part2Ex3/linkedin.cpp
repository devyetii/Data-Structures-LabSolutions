#include "linkedin.h"
linkedin::linkedin(const char *name, const char * uni, const char * work) :profile(name)
{
	this->work = new char[strlen(work) + 1];
	strcpy(this->work, work);
	this->uni = new char[strlen(uni) + 1];
	strcpy(this->uni, uni);
}

void linkedin::setwork(const char * work )
{
	this->work = new char[strlen(work) + 1];
	strcpy(this->work, work);
}

void linkedin::setuni(const char * uni)
{
	this->uni = new char[strlen(uni) + 1];
	strcpy(this->uni, uni);

}

char * linkedin::getname()
{
	return name;
}

char * linkedin::getwork()
{
	return work ;
}

void linkedin::follow(profile *p1)
{
	if (dynamic_cast<linkedin*>(p1)) 
	{	
		if (strcmp(work, static_cast<linkedin*>(p1)->work) || strcmp(uni, static_cast<linkedin*>(p1)->uni)) 
		{
			p1->add_follwers(this);
			this->add_follwing(p1);
		}
	}
}

void linkedin::printinfo()
{
	std::cout << " the name of the user is  " << name
		<< "\n and his work is " << work
		<< " \n and his uni is " << uni
		<< "\n and his number if followers is " << N_follwers
		<< " \n  and his number of following is " << N_follwing << std::endl;
}


linkedin::~linkedin()
{
}
