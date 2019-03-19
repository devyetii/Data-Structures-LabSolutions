#include <iostream>
using namespace std;
#include "LazyList.cpp"
template<class type>
type min(type *arr,int size)
{
	type m = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] > m)
		{
			m = arr[i];
		}
	}
	return m;
}

int main()
{
	LazyList<int> list;
	int n;
	cin >> n;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		list.Add(x);
	}
	list.Display();
	list.Delete(1);
	list.Display();
	list.Delete(2);
	list.Display();
	list.DisplayDeleted();
	LazyList<int> copy(list);
	copy.Display();
	copy.DisplayDeleted();
}