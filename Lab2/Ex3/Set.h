#pragma once
#include <string>
#include <iostream>
using namespace std;

#define MAX_SIZE 100		//Maximum size of a Set
template <typename T>
class Set
{
	T elements[MAX_SIZE];
	int count;		//The current number of actual items in the set
public:
	Set();	//constructor
	int getCount(); //gets current number of actual items in the set
	void Print();	//Prints all items in the Set
	bool isFull();	//checks if Set is full (no place to add more items)
	bool isPhi();	//checks if this is the empty set (Phi)
	bool isMember(T item);	//checks if item is a member in the Set
	bool AddItem(T item);	//Adds a new item to the Set (only if Set is not full and item is not already in the Set)
	T getItem(int index);	//returns an item at certain index
	Set<T> Intersect(Set<T> S);	//returns the intersection of S with current Set
	Set<T> Union(Set<T> S);	//returns the Union of S with current Set
	Set<T> Diff(Set<T> S);	//returns the Difference between current Set and S (Current_Set - S)
	bool isSubsetOf(Set<T> S);//checks if current set is Subset of S
};

template <typename T>
Set<T>::Set()
{
	count = 0;
}

template <typename T>
int Set<T>::getCount()
{
	return count;
}

template <typename T>
void Set<T>::Print()
{
	for(int i = 0; i<count; ++i)
		cout<<elements[i];
}

template <typename T>
bool Set<T>::isFull() 
{
	return count == MAX_SIZE;
}

template <typename T>
bool Set<T>::isPhi()
{
	return count == 0;
}

template <typename T>
bool Set<T>::isMember(T item)
{
	for (int i =0;i<count;++i)
		if(elements[i] == item)
			return 1;
	return 0;
	
}

template <typename T>
bool Set<T>::AddItem(T item)
{
	if (isFull() || isMember(item)) return false;
	elements[count++] = item;
	return true;
}

template <typename T>
T Set<T>::getItem(int idx)
{
	if(idx < 0 || idx > MAX_SIZE)  throw 0;
	return elements[idx];
}

template <typename T>
Set<T> Set<T>::Intersect(Set<T> S)
{
	Set<T> Xn;
	for (int i = 0; i < count; ++i)
		if (S.isMember(elements[i])) Xn.AddItem(elements[i]);
	return Xn;
}

template <typename T>
Set<T> Set<T>::Union(Set<T> S)
{
	Set<T> U;
	for (int i = 0; i < count; ++i)
		U.AddItem(elements[i]);
	for (int i = 0; i <S.getCount(); ++i)
		U.AddItem(S.getItem(i));
	return U;
}

template <typename T>
Set<T> Set<T>::Diff(Set<T> S)
{
	Set<T> D;
	for (int i = 0; i < count; ++i)
		if (!S.isMember(elements[i])) D.AddItem(elements[i]);
	return D;
}

template <typename T>
bool Set<T>::isSubsetOf(Set<T> S)
{
	if (count > S.getCount()) return false;
	for (int i = 0; i < count; ++i)
		if (!(S.isMember(elements[i]))) return false;
	return true;
}