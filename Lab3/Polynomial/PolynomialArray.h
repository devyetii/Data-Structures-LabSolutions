#pragma once
#include "adt.h"
template<class T,int MAX_SIZE = 20>
class PolynomialArray :
	public ADT<T>
{
	int deg;
	T Equation[MAX_SIZE];
public:
	PolynomialArray(void)
	{
		deg = 0;
	}
	virtual int degree() const // returns the degree of the eqn
	{
		return deg;
	}
	virtual T coefficient(int power) const // returns the coeff of a specific degree
	{
		return Equation[power];
	}
	virtual bool changeCoefficient(T newCoefficient, int power) // change the coeff of the xpower
	{
		if (deg < power)
		{
			Equation[power] = newCoefficient;
			return true;
		}
		return false;
	}
	bool AddItem(int power, T coeff)
	{
		if (power < MAX_SIZE)
		{
			Equation[power] = coeff;
			deg = deg >= power ? deg : power;
		}
		return false;
	}
	void PrintAll() const
	{

		for (int i = deg; i >= 0; i--)
		{
			if (Equation[i] && i != 0)
			{
				cout << Equation[i]<<"X ^ "<<i<<" + ";
			}
			else if (Equation[i] && i == 0)
			{
				cout << Equation[i];
			}
		}
		cout << '\n';
	}
	~PolynomialArray(void){}
};

