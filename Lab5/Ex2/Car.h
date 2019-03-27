#pragma once
class Car
{
	int car_num;
	int eng_num;
public:
	Car();
	Car(int cnum, int ennum);
	void setCarNum(int cnum);
	int getCarNum() const;
	void setEngNum(int ennum);
	int getEngNum() const;
	void Print() const;
	~Car();
};

