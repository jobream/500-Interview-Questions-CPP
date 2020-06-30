/*
Name : Aman Jain
Date : 30-6-2020

The idea is to take XOR of two given integers. After calculating
the XOR, we just need to count the number of bits in the resulting 
output

*/



#include<bits/stdc++.h>
using namespace std;


int main(){
  int x,y;
  cin>>x>>y;

  int ans=x^y;
  cout<<__builtin_popcount(ans);
    
}





