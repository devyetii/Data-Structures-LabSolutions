#include<iostream>
using namespace std;

bool EvenHalves(int in, int* evenHalvesCnt, int& firstOddHalf);

int main()
{
	while (true) {
		int input; 
		cout << "Enter an int > 0\n";
		cin >> input;
		if (input <= 0) continue;
		int evenHalvesCount, firstOdd;
		bool isEven = EvenHalves(input, &evenHalvesCount, firstOdd);
		cout << input << " >>>\t" << evenHalvesCount << '\t' << firstOdd << '\t' << (isEven ? "true" : "false") << '\n';
	}
}

bool EvenHalves(int in, int* evenHalvesCnt, int& firstOddHalf)
{
	///NOTE:: (t&1) - where t can be any non-float no., and & is the logic AND operator, should be in parens() - is a popular even/odd bitwise test,
	//	it depends on that the binary represntation of the odd no. always starts with 1 as the least significant digit e.g. 7 is 111
	//	also the the binary represntation of the even no. always starts with 0 as the least significant digit e.g. 8 is 1000
	// so >> odd & 1 = 1, e.g. 7 & 1 = 111 & 001 = 001 = 1
	// and >> even & 1 = 0, e.g. 8 & 1 = 1000 & 0001 = 0000 = 0

	int t = in;
	int cnt = 0;
	bool isEven;
	if ( (t&1) == 0 ) {
		isEven = true;
		t /= 2;

		while ( (t & 1) == 0 ) { 
			cnt++;
			t /= 2;
		}
	} else isEven = false;
	*evenHalvesCnt = cnt; 
	firstOddHalf = t;
	return isEven;
	
	return true;
}