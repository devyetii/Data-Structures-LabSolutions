#pragma once
#include "Bag.h"
class Shop
{
	Bag* BagList[50];
	int Quantity;
	float TotalProfit;
public:
	Shop(void);
	int isAvailable(float, int) const;
	void AddBag();
	Bag* GetBag(int) const;
	~Shop(void);
};

