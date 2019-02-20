#include<iostream>
using namespace std;
template <typename T>
T Mini(T* arr, int sz);

int main() {
	int intArr[] = {1, 2, 3, 4, 5};
	long longArr[] = {1000, 20000, 30000, 44450, 545};
	double doubleArr[] = {13.256, 245.3600, 3.5897, 4.25565, 0.5221453};
	char charArr[] = {'a'};

	cout << Mini(intArr, 5) << '\n';
	cout << Mini(longArr, 5) << '\n';
	cout << Mini(doubleArr, 5) << '\n';
	cout << Mini(charArr, 1) << '\n';
}

template <typename T>
T Mini(T* arr, int sz)
{
	if (sz == 0) throw "Zero-element Array!\n";
	T mini = arr[0];
	for (int i = 1; i < sz; ++i)
	{
		mini = min(mini, arr[i]);
	}
	return mini;
}