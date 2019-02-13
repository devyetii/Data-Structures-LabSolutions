#include "Shop.h"

Shop::Shop(void)
{
	for (int i = 0; i < 50; ++i) {
		this->BagList[i] = new Bag;
	}
}

int Shop::isAvailable(float sz, int slots) const
{
	for (int i = 0; i < Quantity; ++i)
		if (BagList[i]->getSize() == sz && BagList[i]->getSlots() == slots) return i;
	return -1;
}

void Shop::AddBag() 
{
	if (Quantity == 50) return;
	BagList[Quantity++]->ReadInfo();
}

Bag* Shop::GetBag(int idx) const
{
	if (idx > Quantity)
}

Shop::~Shop(void)
{
}
