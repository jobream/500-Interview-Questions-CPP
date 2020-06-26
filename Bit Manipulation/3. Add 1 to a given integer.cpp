/*
Name : Aman Jain
Date : 26-6-2020



The expression -~x will add 1 to a given integer. We know that to get negative of a number, we invert its bits and add 1 to it (Remember negative numbers are stores in 2's compliment form) i.e.

-x = ~x+1
-~x= x+1
*/



#include<bits/stdc++.h>
using namespace std;


int main(){
  int num;
  cin>>num;
  num=-num;
  num=~num;
  cout<<num<<endl;
}