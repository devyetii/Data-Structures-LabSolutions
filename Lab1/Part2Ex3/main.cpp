#include"profile.h"
#include"linkedin.h"
#include"twitter_profile.h"
void main() 
{
	profile* p1[6];
	p1[0] = new linkedin("Ahmed", "cairo uni", "IBM");
	p1[1] = new linkedin("mai", "cairo uni");
	p1[2] = new linkedin("omar", "Alex uni", "Microsoft");
	p1[3] = new twitter_profile("Adam");
	p1[4] = new twitter_profile("Kareem");
	p1[5] = new twitter_profile("Dina");
	p1[0]->follow(p1[1]);
	p1[0]->follow(p1[2]);
	p1[0]->printinfo();
	std::cout << "*********************************************************************************************************"
		<< "***************";
	p1[1]->printinfo();
	std::cout << "*********************************************************************************************************"
		<< "***************";
	p1[2]->printinfo();
	std::cout << "*********************************************************************************************************"
		<< "***************";
	static_cast<twitter_profile*>(p1[4])->setprotected(true);
	p1[4]->follow(p1[3]);
	p1[4]->follow(p1[5]); 
	p1[3]->follow(p1[4]);
	for (int i =3;i<6;i++)
	{
	
		p1[i]->printinfo();
		std::cout << "*********************************************************************************************************"
			<< "***************";
	}
	static_cast<twitter_profile*>(p1[4])->setprotected(false);
	p1[5]->follow(p1[4]);
	for (int i = 3; i<6; i++)
	{

		p1[i]->printinfo();
		std::cout << "*********************************************************************************************************"
			<< "***************";
	}
	p1[3]->unfollow(p1[4]);
	if (p1[3]->isfollow(p1[4])) 
	{
	
		std::cout << "yes he follow \n ";
	
	}
	else 
	{
		std::cout << "NO he doesn't \n ";
	
	}
	if (p1[3]->isfollow(p1[5]))
	{

		std::cout << "yes he follow \n ";

	}
	else
	{
		std::cout << "NO he doesn't \n ";

	}
	p1[3]->follow(p1[2]);
	for (int i = 0; i < 6; i++) 
	{
	
		p1[i]->printinfo();
		std::cout << "*********************************************************************************************************"
			<< "***************";
	
	}
	while (true)
	{

	}






}