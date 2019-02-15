#include "twitter_profile.h"



twitter_profile::twitter_profile(const char * name1): profile(name1)
{
	isprotected = false;
	tweets = 0;
}


twitter_profile::~twitter_profile()
{
}

void twitter_profile::setprotected(bool pro)
{
	isprotected = pro;
}

int twitter_profile::gettweets()
{
	
	return tweets;
}

void twitter_profile::settweets( int tweets )
{
	this->tweets = tweets; 
}

void twitter_profile::follow(profile *p1)
{
	if (dynamic_cast<twitter_profile*>(p1)) 
	{
		if (static_cast<twitter_profile*>(p1)->isprotected) 
		{
			std::cout << "you have a new follow request form profile \n "; 
			this->printinfo();
			std::cout << "do you accecpt  please enter one or zero \n ";
			bool exit;
			std::cin >> exit; 
			if (exit&&!this->isfollow(p1)) 
			{
				p1->add_follwers(this);
				this->add_follwing(p1);
			}
			else 
			{
				return;
			}
		}
		else 
		{
			if (!this->isfollow(p1)) 
			{
				p1->add_follwers(this);
				this->add_follwing(p1);
			}
		}
	}
	else 
	{
		std::cout << "error only twitter profile can follow twitter profile \n ";
		return;
	}
}

void twitter_profile::printinfo()
{
	std::cout << "the name of the user is " << name
		<< "\n and the num of the followers is " << N_follwers
		<< "\n and the num of the following is " << N_follwing
		<< "\n and the num of the tweets is " << tweets << std::endl;

}
