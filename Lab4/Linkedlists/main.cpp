#include "LinkedList.h"
#include <iostream>
using namespace std;

//Function prototypes 

///////////////////////////////////////////////////////////////////////

int main()
{
	LinkedList L;	//create an object of class LinkedList
	int val;

	cout<<"\nPlease enter int values to add to the list (-1 to stop):\n";
	cin>>val;
	while(val != -1)
	{
		L.InsertBeg(val);
		cin>>val;
	}
	L.PrintList();

	cout<<" \n ..............  Lab Requirements .............\n";
	cout<<"\n Check File LinkedList.h and write the required member functions";
	cout<<"\n Then test these functions by calling them from the main()";
	L.InsertBefore(10, 50);
	L.PrintList();
	int n;
	cin >> n;
	L.DeleteLarger(n);
	L.PrintList();
	cout<<endl;

	system("pause");
	return 0;
}

