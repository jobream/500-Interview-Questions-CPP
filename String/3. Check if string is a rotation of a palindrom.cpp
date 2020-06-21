/*
Name : Aman jain
Date: 21-06-20

Question : Check if string is a rotation of a palindrome
Problem Link : https://practice.geeksforgeeks.org/problems/check-if-a-given-string-is-a-rotation-of-a-palindrome/0

Solution to geeksforgeeks :

*/

Method 1- Brute Force (Perform rotation and check for palindrom for n times)  O(n^2)

#include<bits/stdc++.h>
using namespace std;

bool ispalindrome(string s){
    string t=s;
    reverse(t.begin(),t.end());
    return t==s;
}

int main()
 {
	int t;
	cin>>t;  
     while(t--){
         string str;
         cin>>str;
         int n=str.length();
         int flag=0;
         while(n--){
             int c=str[str.length()-1];
             for(int i=str.length()-1; i>0 ; i--){
                 str[i]=str[i-1];
             }
             str[0]=c; 
     
             if(ispalindrome(str)){
                 flag=1;
                 break;
             }
             
         }
         
         if(flag)
         cout<<"1"<<endl;
         else
         cout<<"0"<<endl;       
     }

	return 0;
}







Method 2 - The problem is similar to finding longest palindromic substring problem. Let the given string be S of length m. The idea is to concatenate the given string with itself i.e (s=s+s) and find palindromic substring of length m in the modified string (s+s). if palindromic substring of length m exist in the modified string, we return true else we return false;








#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// expand in both directions of low and high to find
// palindrome of length k
bool expand(string str, int low, int high, int k)
{
	// run till str[low.high] is a palindrome
	while (low >= 0 && high < str.length() && (str[low] == str[high]))
	{
		// return true palindrome of length k is found
		if (high - low + 1 == k)
			return true;

		// expand in both directions
		low--, high++;
	}

	// return false if palindrome of length k is not found
	return false;
}

// Function to check if palindromic substring of length k exists or not
bool longestPalindromicSubstring(string str, int k)
{
	for (int i = 0; i < str.length() - 1; i++)
		// check if odd length or even length palindrome of length k
		// exists which have str[i] as its mid point
		if (expand(str, i, i, k) || expand(str, i, i + 1, k))
			return true;

	return false;
}

// Function to check if given string is a rotated palindrome or not
bool isRotatedPalindrome(string str)
{
	// length of given string
	int m = str.length();

	// return true if longest palindromic substring of length m
	// exists in the string (str + str)
	return longestPalindromicSubstring(str + str, m);
}

// Check if given string is a rotated palindrome or not
int main()
{
	// palindromic string
	string str = "ABCCBA";

	// rotate it by 2 units
	rotate(str.begin(), str.begin() + 2, str.end());

	if (isRotatedPalindrome(str))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}