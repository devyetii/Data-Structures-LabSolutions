#pragma once
#include"student.h"
class ungratuated:public student 
{
	int year ;
public:
	ungratuated(const char * ,long long ,int );
	~ungratuated(void);
	void printinfo() ;
	long long getid() ;
	char * getname();
	bool pass() ;
};

