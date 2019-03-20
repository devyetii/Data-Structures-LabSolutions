#pragma once
#include <iostream>
using namespace std;
class Ball
{
	int number;
public:
	Ball(int num = -1)
	{
		number = num;
	}
	friend ostream& operator<<(ostream& out, Ball b)
	{
		out << b.number;
		return out;
	}
	friend istream& operator>>(istream& in, Ball &b)
	{
		in >> b.number;
		return in;
	}
	bool operator==(const Ball& b) const 
	{
		return this->number == b.number;
	}
	void SetNumber(int num)
	{
		number = num;
	}
};

