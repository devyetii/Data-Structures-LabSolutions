#include"graduated.h"
#include"faculty.h"
#include"ungratuated.h"
void main ()
{
	graduated	*g1 = new	graduated("Abdalla ",12345678,2013);
	ungratuated *g2 = new ungratuated("ahmed",65464565,3);
	ungratuated *g3 = new ungratuated("mohamed ",6546456645655,4);
	faculty eng;
	eng.addstudent(g1) ;
	eng.addstudent(g2) ;
	eng.addstudent(g3);
	eng.printinfo() ;
	for (int i =0  ;i<3 ;i++)
	{
		eng.passall() ;
		std::cout<<std::endl;
		eng.printinfo() ;
	
	}
}