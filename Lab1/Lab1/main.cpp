#include<iostream>
using namespace std;

void EvensAndOdds(int**& InputArr, int in_sz, int**& ev, int& ev_sz, int**& od, int& od_sz);

int main(int argc, char const *argv[])
{
	cout << "Please Enter no. of el.s > 0 \n"; 
	int n; cin >> n;

	if ( n <= 0 ) return 0;
	else { 
		int** arr = new int*[n];
		cout << "Please Enter an Array of integers\n";
		int t;
		for (int i = 0; i < n; ++i) {
			arr[i] = new int;
			cout << "[" << i << "] : "; cin >> t;
			*arr[i] = t;
			cout << '\n';
		}
		int **evens, **odds, ev_sz, od_sz;
		EvensAndOdds(arr, n, evens, ev_sz, odds, od_sz);

		//Printing the evens array
		cout << '[';
		for (int i = 0; i < ev_sz; i++)
		{
			cout << *(evens[i]);
			if (i != ev_sz-1 ) cout << ", ";
		}
		cout << "]\n";

		//Printing the odds array
		cout << '[';
		for (int i = 0; i < od_sz; ++i)
		{
			cout << *(odds[i]);
			if (i != od_sz-1 ) cout << ", ";
		}
		cout << "]\n";

		//Printing the Updated array
		cout << '[';
		for (int i = 0; i < n; ++i)
		{
			if ( arr[i] == NULL ) cout << "NULL";
			else cout << *(arr[i]);

			if (i != n-1 ) cout << ", ";
		}
		cout << "]\n";
		delete[] arr, evens, odds;
	}
	
	return 0;
}


void EvensAndOdds(int**& InputArr, int in_sz, int**& ev, int& ev_sz, int**& od, int& od_sz) {
	//Counting Odds and Evens and Deleting the under-zeros
	ev_sz = 0; od_sz = 0;
	for(int i = 0; i < in_sz; ++i) {
		if (*(InputArr[i]) > 0) {
			if (*(InputArr[i]) % 2 == 1) od_sz++;
			else ev_sz++;
		} else {
			delete InputArr[i];
			InputArr[i] = NULL;
		}
	}

	//Declaring new arrays of ptrs to ints
	ev = new int*[ev_sz]; od = new int*[od_sz];

	//Filling the Arrays with data
	int e_cnt = 0, o_cnt = 0;
	for(int i = 0; i < in_sz; ++i) {
		if (InputArr[i] != NULL) {
			if (*(InputArr[i]) % 2 == 1) od[o_cnt++] = InputArr[i];
			else ev[e_cnt++] = InputArr[i];
		}
	}
}