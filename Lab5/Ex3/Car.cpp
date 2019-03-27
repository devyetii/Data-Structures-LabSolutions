#include "pch.h"
#include<iostream>
#include "Car.h"


Car::Car()
{
}

Car::Car(int cnum, int ennum)
{
	this->car_num = cnum;
	this->eng_num = ennum;
}

void Car::setCarNum(int cnum)
{
	this->car_num = cnum;
}

int Car::getCarNum() const
{
	return this->car_num;
}

void Car::setEngNum(int ennum)
{
	this->eng_num = ennum;
}

int Car::getEngNum() const
{
	return this->eng_num;
}

void Car::Print() const
{
	std::cout << "Car: Car Number = " << this->car_num << ", Engine Number = " << this->eng_num << '\n';
}


Car::~Car()
{
}
