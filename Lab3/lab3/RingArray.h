#pragma once
#include <iostream>
using namespace std;
#include "ring.h"
template<class T,int MAX_SIZE = 100>
class RingArray :
	public Ring<T>
{
	int Reference;
	T arr[MAX_SIZE];
	int count;
	void Shift(int idx)
	{
		if (idx > -1)
		{
			for (int i = idx; i < count - 1; i++)
			{
				arr[i] = arr[i + 1];
			}
			count--;
		}
	}
public:
	virtual void advance()
	{
		Reference = (Reference + 1) % count;
	}
	virtual T getItem() const
	{
		if(Reference != -1)
		{
			return arr[Reference];
		}
	}
	virtual bool addItem(const T& item)
	{
		if (Reference < MAX_SIZE - 1)
		{
			arr[Reference + 1] = item;
			count++;
			advance();
			return true;
		}
		return false;
	}
	virtual bool removeItem(T item)
	{
		for (int i = 0; i < count; i++)
		{
			if (arr[i] == item)
			{
				Shift(i);
				Reference = i;
				return true;
			}
		}
		return false;
	}
	virtual bool contains(T item) const
	{
		for (int i = 0; i < count; i++)
		{
			if (arr[i] == item)
			{
				return true;
			}
		}
		return false;
	}
	virtual bool isEmpty() const
	{
		return !count;
	}
	virtual void PrintAll() const
	{
		int i = Reference;
		do
		{
			cout << arr[i] << "- "[i == Reference - 1];
			i = (i + 1) % count;
		}while(i != Reference);
		cout << '\n';
	}
	RingArray()
	{
		Reference = -1;
		count = 0;
	}
	~RingArray()
	{

	}
};