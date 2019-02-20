#include "Set.h"

int main()
{
	try{
	
		//Declare 3 sets of int
		Set<int> S1, S2, S3;
		int x;

		//Filling S1
		int n;
		cout<<"\nEnter no. of items in S1:";
		cin>>n;
		cout<<"Enter "<<n<<" items (separated by space):";
		for(int i=0; i<n; i++)
		{
			cin>>x;
			S1.AddItem(x);
		}

		//Filling S2
		cout<<"\nEnter no. of items in S2:";
		cin>>n;
		cout<<"Enter "<<n<<" items (separated by space):";
		for(int i=0; i<n; i++)
		{
			cin>>x;
			S2.AddItem(x);
		}


		cout<<"\n\nSets Contents....";
		cout<<"\nS1 = "; 	S1.Print();
		cout<<"\nS2 = "; 	S2.Print();

		S3 = S1.Intersect(S2);
		cout<<"\n\nSets Intersection.... \nS1 x S2 = ";
		if(S3.isPhi())	cout<<"Phi";
		else	S3.Print();

		S3 = S1.Union(S2);
		cout<<"\n\nSets Union.... \nS1 U S2 = ";
		S3.Print();

		S3 = S1.Diff(S2);
		cout<<"\n\nSets Diffrerence.... \nS1 - S2 = ";
		if(S3.isPhi())	cout<<"Phi";
		else	S3.Print();

		S3 = S2.Diff(S1);
		cout<<"\n\nSets Diffrerence.... \nS2 - S1 = ";
		if(S3.isPhi())	cout<<"Phi";
		else	S3.Print();


		cout<<"\n\nIs S1 subset of S2? ";
		cout<<boolalpha<<S1.isSubsetOf(S2);

	
		cout<<"\n\nIs S2 subset of S1? ";
		cout<<S2.isSubsetOf(S1);

	} catch (int errcode) {
	cout << (errcode == 0) ? "OutOfRange Exception!!!\n" : "Unknown Exception!!!";
	}
	int a ;cin>>a;
	return 0;
}
