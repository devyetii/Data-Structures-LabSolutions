#include "pch.h"
#include <iostream>
#include"../1-Stacks/ArrayStack.h"
#include"Car.h"

int main()
{
    ArrayStack<Car*> car_stk;
	Car* c1 = new Car(100, 100); car_stk.push(c1);
	Car* c2 = new Car(200, 200); car_stk.push(c2);
	Car* c3 = new Car(300, 300); car_stk.push(c3);

	Car* tmp;
	while (!car_stk.isEmpty()) {
		car_stk.pop(tmp);
		tmp->Print();
	}

	
}