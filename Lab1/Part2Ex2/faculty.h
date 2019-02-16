#pragma once
#include"student.h"
class faculty
{
	student * arr[200] ;
	int num;
public:
	faculty();
	~faculty(void);
	void addstudent(student *);
	void  dropstudent (student*);
	void passall() ;
	void printinfo ();

};

