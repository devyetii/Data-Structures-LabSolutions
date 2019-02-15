#pragma once
#include"profile.h"
class twitter_profile: public  profile
{
	int tweets;
	bool isprotected; 
public:
	twitter_profile(const char *);
	~twitter_profile();
	void setprotected(bool);
	int gettweets();
	void settweets(int);
	virtual void follow(profile*);
	virtual void printinfo();
	
};


