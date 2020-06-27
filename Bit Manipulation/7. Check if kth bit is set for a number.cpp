/*
Name : Aman Jain
Date : 27-6-2020

*/

#include<bits/stdc++.h>
using namespace std;


int main(){
    int num,k;
    cin>>num>>k;

  int temp=1<<(k-1);
  temp=temp& num;
  if(temp)
  cout<<"bit is set";
  else cout<<"Bit is not set"

}