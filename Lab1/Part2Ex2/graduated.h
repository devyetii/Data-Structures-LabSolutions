#pragma once
#include"student.h"
#include"ungratuated.h"
class graduated:public student 
{
	int gradyear;
public:
	graduated(const char  *,long long ,int  );
	~graduated(void);
	//graduated(const ungratuated &);
	virtual void printinfo() ;
	virtual long long getid(); 
	virtual char * getname() ;
	
};

