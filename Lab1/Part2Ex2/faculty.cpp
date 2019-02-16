#include "faculty.h"
#include"ungratuated.h"
#include"graduated.h"
faculty::faculty(void)
{
	for (int i =0 ;i<200 ;i++)
	{
	
		arr[i]=NULL ;
	}
	num =0 ;
}


faculty::~faculty(void)
{
}
void faculty::addstudent(student* sp)
{
	arr[num]=sp ;
	num++ ;

}
void faculty::dropstudent(student* sp)
{
	for (int i = 0;i<num;i++)
	{
		if (arr[i]==sp)
		{
			for (i ;i<num-1 ;i++)
			{
			
				arr[i]=arr[i+1] ;

			
			}
			arr[num]=NULL ;
			break;
		
		}
	
	}
	num-- ;

}
void faculty::passall()
{
	
	for (int i=0 ;i<num;i++)
	{
		if (dynamic_cast<ungratuated*>(arr[i]))
		{
		
			if (static_cast<ungratuated*>(arr[i])->pass())
			{
				this->dropstudent(arr[i]) ;
				graduated *g=new graduated(arr[i]->getname(),arr[i]->getid(),2017);
				this->addstudent(g) ;
				
			}
		}
	
	}

}
void faculty::printinfo()
{
	int count1=0 ,count2=0 ; 
	for (int i =0 ;i<num ;i++)
{
	
	if (dynamic_cast<graduated*>(arr[i]))
	{
	
	count1++;
	}
	else 
	{
	
		count2++ ;
	}
}
	std::cout<<"num of the gratuadetd=   "<<count1<<std::endl ;
	std::cout<<"num of the ungratuadetd=   "<<count2<<std::endl ;
	for (int i =0 ;i<num ;i++)
	{
	
		arr[i]->printinfo() ;
	}

}