/*
 Name : Aman Jain
 Date: 27-06-2020

The idea is to unset the rightmost bit of number n and XOR the result with n.
Then the position of the rightmost set bit in n will be the position of the only set bit in the result. Note that if n is ood, we can directly return 1 as first bit is always set for odd numbers.



00010100 & (n=20)
00010011 &(n-1=19)
~~~~~~~~
00010000 XOR 00010100 = 00000100
 
*/

#include <iostream>
#include <bitset>
using namespace std;

// returns position of the rightmost set bit of n
int rightmostSetBitPos(int n)
{
	// if number is odd, return 1
	if (n & 1)
		return 1;

	// unset rightmost bit and xor with number itself
	n = n ^ (n & (n - 1));

	// cout << bitset<8>(n) << endl;

	// find the position of the only set bit in the result
	// we can directly return log2(n) + 1 from the function
	int pos = 0;
	while (n)
	{
		n = n >> 1;
		pos++;
	}
	return pos;
}

int main()
{
	int n = 20;

	cout << n << " in binary is " << bitset<8>(n) << endl;
	cout << "Position of the rightmost set bit is "
			<< rightmostSetBitPos(n);

	return 0;
}