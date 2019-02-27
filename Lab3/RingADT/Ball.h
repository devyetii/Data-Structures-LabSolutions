#pragma once
#include<iostream>
class Ball
{
	int number;
public:

	Ball(int num = 0)
	{
		this->number = num;
	};
	int getNumber() const
	{
		return this->number;
	};
	bool operator==(const Ball& b2)
	{
		return (this->number == b2.getNumber());
	};
	void Print() const 
	{
		std::cout << "Ball #" << this->number << ' '; 
	}
	~Ball(void)
	{
	};
};

