#pragma once
#include"iostream"
class student
{ protected:
	char * name ;
	long long id ;
public:
	student(const char * ,long long );
	~student(void);
	virtual char * getname()=0 ;
	virtual long long getid() =0;
	virtual void printinfo()=0 ;
};

