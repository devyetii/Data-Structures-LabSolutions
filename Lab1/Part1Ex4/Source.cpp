#include <iostream>
using namespace std;

char* ExpandArray(char* UniqueArr, int* NoOfOccurrence, int size, int& NewSize)
{
	NewSize = 0;
	for (int i = 0; i < size; i++)
	{
		NewSize += NoOfOccurrence[i];
	}
	char* Array = new char[NewSize];
	int CurrentIndex = 0;
	for (int j = 0; j < size; j++)
	{
		for (int i = 0; i < NoOfOccurrence[j]; i++)
		{
			Array[CurrentIndex++] = UniqueArr[j];
		}
	}
	return Array;
}

int main()
{
	int size;
	cin >> size;
	if (size <= 0)
	{
		return 0; // close the program
	}
	char* UniqueArr = new char[size];
	int* NoOfOccurrence = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> UniqueArr[i];
	}
	for (int i = 0; i < size; i++)
	{
		cin >> NoOfOccurrence[i];
	}
	int NewSize;
	char* Array = ExpandArray(UniqueArr, NoOfOccurrence, size, NewSize);
	for (int i = 0; i < NewSize; i++)
	{
		cout << Array[i] << " ";
	}
	cout << '\n';
}