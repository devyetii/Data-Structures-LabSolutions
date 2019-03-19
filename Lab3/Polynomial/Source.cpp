#include <iostream>
using namespace std;
#include "PolynomialArray.h"
int main()
{
	PolynomialArray<int,10> eqn;
	int power,coeff;
	for (int i = 5; i >= 0; i--)
	{
		power = i;
		cin >> coeff;
		eqn.AddItem(power,coeff);
	}
	eqn.PrintAll();

}