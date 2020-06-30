/*
 Name : Aman Jain
 Date: 27-06-2020


The position of the only set bit can be found by processing every bit of n one by one or e can directly use log2(n)+1

00010000 & (n=16)
00001111 & (n-1=15)
~~~~~~~~
00000000

log2(16)+1=5;

 
*/

#include <iostream>
#include <bitset>
#include <math.h>
using namespace std;

// returns position of the only set bit of n
int setBitPos(int n)
{
	// unset rightmost bit and check if the number is non-zero
	if (n & (n - 1))
	{
		cout << "Wrong input";
		return 1;
	}

	return log2(n) + 1;
}

int main()
{
	int n = 16;

	cout << n << " in binary is " << bitset<8>(n) << endl;
	cout << "Position of the only set bit is " << setBitPos(n);

	return 0;
}