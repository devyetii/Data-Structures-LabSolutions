#pragma once
#include<iostream>
#define MAX 1000
template <typename T, int MAX_SIZE = MAX>
class RingADT
{
	T* els;
	int current;
	int count;
	void _deleteAndShift(int idx);
public:
	RingADT(void);
	void advance();
	bool addItem(T item);
	T getItem() const;
	bool removeItem(T val);
	bool contains(T val) const;
	bool isEmpty() const;
	void PrintAll();
	~RingADT(void);
};

template <typename T, int MAX_SIZE>
RingADT<T, MAX_SIZE>::RingADT() 
{
	els = new T[MAX];
	count = 0; current = 0;
}

template <typename T, int MAX_SIZE>
void RingADT<T, MAX_SIZE>::_deleteAndShift(int idx)
{
	for (int i = idx; i < count - 1; ++i) els[i] = els[i+1];
	count--;
}

template <typename T, int MAX_SIZE>
void RingADT<T, MAX_SIZE>::advance()
{
	current++;
	if (current == count) current = 0;
}

template <typename T, int MAX_SIZE>
bool RingADT<T, MAX_SIZE>::addItem(T item)
{
	if (count == MAX) return false;
	count++;
	this->advance();
	for (int i = current; i < count - 1; ++i) els[i+1] = els[i];
	//Inserting
	els[current] = item; // if not, overload assignment operator for T
}

template <typename T, int MAX_SIZE>
T RingADT<T, MAX_SIZE>::getItem() const
{
	return els[current];
}

template <typename T, int MAX_SIZE>
bool RingADT<T, MAX_SIZE>::removeItem(T val)
{
	int start = current;
	do {
		if (els[current] == val) {
			_deleteAndShift(current);
			if (current == count) current--;
			return true;
		}
		advance();
	} while (current != start);
	return false;
}

template <typename T, int MAX_SIZE>
bool RingADT<T, MAX_SIZE>::contains(T val) const
{
	for (int i = 0; i < count; ++i)
		if ( els[i] == val) return true; // == operator should be overloaded for any type using this ADT
	return false;
}

template <typename T, int MAX_SIZE>
bool RingADT<T, MAX_SIZE>::isEmpty() const
{
	return  (count == 0);
}

template <typename T, int MAX_SIZE>
void RingADT<T, MAX_SIZE>::PrintAll()
{
	if (isEmpty()) return;
	int start = current;
	do {
		std::cout << els[current] << ' ';
		advance();
		if (current == start) break;
	} while (true);
}

template <typename T, int MAX_SIZE>
RingADT<T, MAX_SIZE>::~RingADT()
{
	delete[] els;
}