#include "Bag.h"
#include<iostream>

Bag::Bag(float price, float sz, int slots)
{
	this->price  =0;
	this->setSize(sz);
	this->setSlots(slots);
}

bool Bag::setSize(float sz)
{
	if (isalpha(sz)) return false;
	else {
		this->size = sz;
		return true;
	}
}

bool Bag::setPrice(float p)
{
	if (isalpha(p)) return false;
	else {
		this->price = p;
		return true;

	}
}

bool Bag::setSlots(int s)
{
	if (isalpha(s)) return false;
	else {
		this->slots = s;
		return true;
	}
}

float Bag::getSize() const
{
	return this->size;
}

float Bag::getPrice() const
{
	return this->price;
}

int Bag::getSlots() const
{
	return this->slots;
}

int Bag::Compare(const Bag& B) const
{
	if (B.getSize() == this->size)
		if (B.getSlots() > this->slots) return -1;
		else if (B.getSlots() < this->slots) return 1;
		else return 0;
	else if (B.getSize() > this->size) return -1;
	else return 1;
}

void Bag::PrintInfo() const
{
	std::cout << "Bag : Size = " 
			  << this->size
			  << " , Price = "
			  << this->price
			  << " , Slots = "
			  << this->slots
			  << '\n';
}

void Bag::ReadInfo()
{
	float sz, p; int s;
	std::cout << "Bag : Size = ";
	std::cin  >> sz;
	std::cout << " , Price = ";
	std::cin  >> p;
	std::cout << " , Slots = ";
	std::cin  >> s;
	std::cout << '\n';
	this->setSize(sz); this->setPrice(p); this->setSlots(s);
}	


Bag::~Bag(void)
{
}
