#pragma once
class Bag
{
	float size, price;
	int slots;
public:
	Bag(float price = 0, float sz = 15.6, int slots = 5);
	bool setSize(float);
	bool setPrice(float);
	bool setSlots(int);
	float getSize() const;
	float getPrice() const;
	int getSlots() const;
	int Compare(const Bag&) const;
	void ReadInfo();
	void PrintInfo() const;
	~Bag(void);
};

