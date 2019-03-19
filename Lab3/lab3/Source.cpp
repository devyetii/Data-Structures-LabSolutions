#include <iostream>
#include "RingArray.h"
#include "Ball.h"
using namespace std;
int main()
{
	RingArray<Ball> ring;
	Ball x;
	int n;
	cout << "Enter a Number : \n";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		ring.addItem(x);
	}
	ring.PrintAll();
	cin >> x;
	while (ring.contains(x) == true);
	{
		//ring.removeItem(x);
		cin >> x;
		ring.PrintAll();
	} 
}