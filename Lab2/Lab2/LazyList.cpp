#include "LazyList.h"

template<class T>
LazyList<T>::LazyList(void)
{
	size = 0;
	NoDeleted = 0;
	NoNonDeleted = 0;
	deleted = NULL;
	elements = NULL;
}
template<class T>
LazyList<T>::LazyList(const LazyList& Object)
{
	this->size = Object.size;
	elements = new T[size];
	deleted = new bool[size];
	for (int i = 0; i < size; i++)
	{
		elements[i] = Object.elements[i];
		deleted[i] = Object.deleted[i]
	}
}
template<class T>
void LazyList<T>::IncreaseSize(T*& list)
{
	T* temp = new T[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = list[i];
	}
	delete[] list;
	list = temp;
	temp = NULL;
}
template<class T>
void LazyList<T>::IncreaseSize2(bool*& list)
{
	bool* temp = new bool[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = list[i];
	}
	delete[] list;
	list = temp;
	temp = NULL;
}
template<class T>
bool LazyList<T>::IsMember(const T& item) const
{
	for (int i = 0; i < size; i++)
	{
		if (!deleted[i] && elements[i] == item)
		{
			return true;
		}
	}
	return false;
}
template<class T>
void LazyList<T>::HardDelete(T*& list)
{
	T* temp = new T[size/2];
	int cnt = 0;
	for (int i = 0; i < size; i++)
	{
		if (!deleted[i])
		{
			temp[cnt] = list[i];
		}
	}
	delete[] list;
	list = temp;
	temp = NULL;
}
template<class T>
void LazyList<T>::HardDelete2(bool*& list)
{
	bool* temp = new bool[size/2];
	int cnt = 0;
	for (int i = 0; i < size; i++)
	{
		if (!deleted[i])
		{
			temp[cnt] = list[i];
		}
	}
	delete[] list;
	list = temp;
	temp = NULL;
}
template<class T>
bool LazyList<T>::Add(const T& item)
{
	if (elements)
	{
		IncreaseSize(elements);
		IncreaseSize2(deleted);
		elements[size] = item;
		deleted[size] = false;
	}
	else
	{
		elements = new T;
		deleted = new bool;
		elements[size] = item;
		deleted[size] = false;
	}
	NoNonDeleted++;
	size++;
	return true;
}
template<class T>
bool LazyList<T>::Delete(const T& item)
{
	int idx = Search(item);
	if (idx != -1)
	{
		if (NoDeleted >= NoNonDeleted)
		{
			HardDelete(elements);
			HardDelete2(deleted);
			size /= 2;
			NoDeleted = 0;
		}
		else
		{
			deleted[idx] = true;
			NoDeleted++;
			NoNonDeleted--;
		}
		return true;
	}
	else
	{
		return false;
	}
}
template<class T>	
T LazyList<T>::GetElement(int index) const
{
	if (index < size && index >= 0)
	{
		return elements[index];
	}
}
template<class T>
int LazyList<T>::Search(const T& item) const
{
	for (int i = 0; i < size; i++)
	{
		if (elements[i] == item && !deleted[i])
		{
			return i;
		}
	}
	return -1;
}
template<class T>
void LazyList<T>::Display() const
{
	for (int i = 0; i < size; i++)
	{
		if (!deleted[i])
		{
			cout << elements[i] << " \n"[i == size-1];
		}
	}
}
template<class T>
void LazyList<T>::DisplayDeleted() const
{
	for (int i = 0; i < size; i++)
	{
		if (deleted[i])
		{
			cout << elements[i] << " \n"[i == size-1];
		}
	}
}
template<class T>
LazyList<T>::~LazyList(void)
{
	if (elements)
	{
		delete[] elements;
		elements = NULL;
	}
	if (deleted)
	{
		delete[] deleted;
		deleted = NULL;
	}
}
