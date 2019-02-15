#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>

class profile
{
protected:
	char * name;
	int N_follwers,N_follwing;
	profile * follwers[50],* follwing[50] ;// linked list will be better it will be  modified after studying linked list(bc num of followes&following should be incrementable) 
	//they should be array of pointers to avoid entering infinte loop 
public:
	profile(const char *);
	~profile();
	void setname(const char *);
	void setN_follwers(int);
	void setN_folwing(int);
	void add_follwers(profile*);
	void add_follwing(profile*);
	char * getname();
	int getfollwers();
	int getfollwing();
	profile* getpfollwer(int );
	profile* getpfollwing(int ); 
	bool isfollow(profile*);
	bool isfollwed(profile*);
	void virtual  follow(profile *) = 0;
	void unfollow(profile*);
	void remove_follower(profile* );
	void remove_following(profile*);
	virtual void printinfo() = 0;

};

