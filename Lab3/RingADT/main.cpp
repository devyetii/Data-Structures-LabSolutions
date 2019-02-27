#include<iostream>
#include"RingADT.h"
#include"Ball.h"
using namespace std;

ostream& operator<<(ostream& out, const Ball& B)
{
	B.Print();
	return out;
}

int main()
{
	RingADT<Ball, 100> myRing;
	for (int i = 0; i < 5 ; ++i) {
		myRing.addItem(Ball(i+1));
	}
	myRing.PrintAll(); cout << '\n';
	myRing.removeItem(Ball(5));
	myRing.PrintAll(); cout << '\n';

	int guess;
	while (!myRing.isEmpty()) {
		cout << "Guess a Ball to remove: ";
		cin >> guess;
		if ( myRing.contains(Ball(guess)) ) {
			myRing.removeItem(Ball(guess));
		} else {
			cout << "Try Again\n";
		}
	}
	cout  << "The List is now Empty!\n";

	system("pause");
}