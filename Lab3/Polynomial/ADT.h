#pragma once
template<class T>
class ADT
{
public:
	virtual int degree() const = 0; // returns the degree of the eqn
	virtual T coefficient(int power) const = 0; // returns the coeff of a specific degree
	virtual bool changeCoefficient(T newCoefficient, int power) = 0; // change the coeff of the xpower
};

