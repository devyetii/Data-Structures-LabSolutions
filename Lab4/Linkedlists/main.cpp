#include "LinkedList.h"
#include <iostream>
using namespace std;

//Function prototypes

///////////////////////////////////////////////////////////////////////

int main()
{
	LinkedList<int> L_int;	//create an object of class LinkedList
	LinkedList<double> L_doub;
	LinkedList<char*> L_str;
	int val;

	cout<<"\nPlease enter int values to add to the list (-1 to stop):\n";
	cin>>val;
	while(val != -1)
	{
		L_int.InsertBeg(val);
		L_doub.InsertBeg(val*6.399);
		cin>>val;
	}
	L_int.PrintList();
	L_doub.PrintList();
	cout<<" \n ..............  Lab Requirements .............\n";
	cout<<"\n Check File LinkedList.h and write the required member functions";
	cout<<"\n Then test these functions by calling them from the main()";
	
	L_int.Reverse();
	L_int.PrintList();

	cout << '\n';
	system("pause");
	return 0;
}