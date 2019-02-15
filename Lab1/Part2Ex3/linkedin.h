#pragma once
#include"profile.h"
class linkedin:public profile 
{
	char * uni, *work;

public:
	linkedin(const char * ,const char* ="",const char* ="");
	void setwork(const char *);
	void setuni(const char *);
	char * getname();
	char * getwork();
	virtual void follow(profile*);
	virtual void printinfo();
	~linkedin();
};

