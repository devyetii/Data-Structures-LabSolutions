#pragma once
#include <iostream>
using namespace std;
template<class T>
class LazyList
{
	int NoDeleted,NoNonDeleted;
	int size;
	bool* deleted;
	T* elements;
	void IncreaseSize(T*& list);
	void IncreaseSize2(bool*& list);
	void HardDelete(T*& list);
	void HardDelete2(bool*& list);
public:
	LazyList(void);
	LazyList(const LazyList& Object);
	bool IsMember(const T& item) const;
	bool Delete(const T& item);
	bool Add(const T& item);
	T GetElement(int index) const;
	int Search(const T& item) const;
	void Display() const;
	void DisplayDeleted() const;
	~LazyList(void);
};

