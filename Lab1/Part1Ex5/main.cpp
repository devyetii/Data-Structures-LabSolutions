#include<iostream>
#include<algorithm>
using namespace std;
void A_mins_B(int * arr1, int size1, int * arr2, int size2, int *&diffarr, int & size3);
void main() 
{	
	
	int * arr1, *arr2,*diffarr,size3=0;
	int size1, size2;
	cin >> size1 >> size2;
	arr1 = new int[size1];
	arr2 = new int[size2];
	for (int i = 0; i < size1; i++) 
	{
		cin>>arr1[i] ;
	}
	for (int i = 0; i < size2; i++) 
	{
		cin>>arr2[i]  ;
	}
	sort(arr1, arr1 + size1);// if the user enter unsorted array 
	sort(arr2, arr2 + size2);
	A_mins_B(arr1, size1, arr2, size2, diffarr, size3);
	for (int i=0; i < size1; i++)
	{
	
		cout << arr1[i] << "  ";
	
	}
	for (int i = 0; i < 5; i++) 
	{
		cout << "*" << endl;
	
	}
	for (int i=0; i < size2; i++)
	{

		cout << arr2[i] << "  ";

	}
	for (int i = 0; i < 5; i++)
	{
		cout << "*" << endl;

	}
	for (int i = 0; i < size3; i++) 
	{
		cout << diffarr[i]<<endl;
	
	}
	delete[]arr1;
	delete[]arr2;
	delete[]diffarr;
}

void A_mins_B(int * arr1, int size1, int * arr2, int size2, int *& diffarr, int & size3)
{// using vector will be more efficint bc you can insert while counting 
	int count=0;//for counting the num of the elemnts that is not exist in B  
	for (int i = 0; i < size1; i++) 
	{
		int fir = abs(arr1[i] - arr2[0]),sec=abs(arr1[i]-arr2[size2-1]);
		if (fir < sec) 
		{
			bool exit = false;
			for (int j = 0; (j < size2&&arr2[j] <= arr1[i]&&!exit); j++) 
			{
			
				if (arr1[i] == arr2[j])
					exit = true;
			}
			if (!exit) 
			{
				count++;
			}
		}
		else if (sec<fir) 
		{
			bool exit=false ;
			for (int j = size2 - 1; (j >= 0 && arr2[j] >= arr1[i]&&!exit); j--) 
			{
				if (arr1[i] == arr2[j])
					exit = true;
			}
			if (!exit) 
			{
				count++;
			}
		}
		else 
		{
			if (arr2[0] == arr2[size2 - 1]) 
			{
				for (i; i < size1; i++) 
				{
					if (arr1[i] != arr2[0]) 
					{
						count++;
					}
				}
				break;
			}
			else 
			{
				bool exit = false;
				for (int j = 0; (j < size2&&arr2[j] <=arr1[i] && !exit); j++)
				{

					if (arr1[i] == arr2[j])
						exit = true;
				}
				if (!exit)
				{
					count++;
				}
			}
		}
	}
	diffarr = new int[count];
	for (int q = 0; q< count;) 
	{
		
		for (int i = 0; i < size1; i++)
		{

			int fir = abs(arr1[i] - arr2[0]), sec = abs(arr1[i] - arr2[size2 - 1]);
			if (fir < sec)
			{
				bool exit = false;
				for (int j = 0; (j < size2&&arr2[j] <= arr1[i] && !exit); j++)
				{

					if (arr1[i] == arr2[j])
						exit = true;
				}
				if (!exit)
				{
					diffarr[q++]=arr1[i];
				}

			}
			else if (sec<fir)
			{
				bool exit = false;
				for (int j = size2 - 1; (j >= 0 && arr2[j] >= arr1[i] && !exit); j--)
				{

					if (arr1[i] == arr2[j])
						exit = true;
				}
				if (!exit)
				{
					diffarr[q++]=arr1[i];
				}
			}
			else
			{
				if (arr2[0] == arr2[size2 - 1])
				{
					for (i; i < size1; i++)
					{
						if (arr1[i] != arr2[0])
						{
							diffarr[q++]=arr1[i];
						}
					}
					break;
				}
				else
				{
					bool exit = false;
					for (int j = 0; (j < size2&&arr2[j] <=arr1[i] && !exit); j++)
					{

						if (arr1[i] == arr2[j])
							exit = true;
					}
					if (!exit)
					{
						diffarr[q++]=arr1[i];
					}
				}
			}
		}
	}
	size3 = count;
}
