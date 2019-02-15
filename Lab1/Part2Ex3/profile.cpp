#include "profile.h"



profile::profile(const char * name )
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	N_follwers = N_follwing = 0;
	for (int i = 0; i < 50; i++) 
	{
		follwers[i] = NULL;
		follwing[i] = NULL;
	
	}
	

}


profile::~profile()
{
}

void profile::setname(const char * name )
{
	this->name = new char[strlen(name)+1];
	strcpy(this->name,name);


}

void profile::setN_follwers(int num)
{
	N_follwers = num;
}

void profile::setN_folwing(int num )
{
	N_follwing = num;
}

void profile::add_follwers(profile* p1)
{
	if (N_follwers > 50) 
	{
	
		std::cout << "you can't add a follower \n ";
		return;
	
	}
	follwers[N_follwers] = p1;
	this->N_follwers++;

}

void profile::add_follwing(profile* p1)
{
	if (N_follwing> 50)
	{

		std::cout << "you can't add a following \n ";
		return;

	}
	follwers[N_follwing] = p1;
	this->N_follwing++;
}



char * profile::getname()
{
	return this->name;
}

int profile::getfollwers()
{
	return N_follwers;
}

int profile::getfollwing()
{
	return N_follwing; 
}

profile * profile::getpfollwer(int index )
{
	return follwers[index];
}

profile * profile::getpfollwing(int index )
{
	return follwing[index];
}

bool profile::isfollow(profile* p1)
{
	for (int i = 0; i < N_follwers; i++) 
	{
		if (follwers[i] == p1) //pointer can't be compared by each others execept ==
		{
			return true; 
		}
	}
	return false;
}

bool profile::isfollwed(profile* p1 )
{
	for (int i = 0; i < N_follwing; i++)
	{
		if (follwing[i] == p1) //pointer can't be compared by each others execept ==
		{
			return true;
		}
	}
	return false;
}

void profile::unfollow(profile * p1)
{
	p1->remove_follower(this);
	this->remove_following(p1);
}

void profile::remove_follower(profile *p1)
{
	for (int i = 0; i < N_follwers; i++) 
	{
		if (follwers[i] == p1) 
		{
			
			std::swap(follwers[i], follwers[N_follwers]);
			follwers[N_follwers] = NULL;
			N_follwers--;
			return;
		}
	}
}

void profile::remove_following(profile * p1)
{
	for (int i = 0; i < N_follwing; i++) 
	{
	
		if (follwing[i] == p1) 
		{
			std::swap(follwing[i], follwing[N_follwing]);
			follwing[N_follwing] = NULL;
			N_follwing--;
			return;
		}
	
	}
}

