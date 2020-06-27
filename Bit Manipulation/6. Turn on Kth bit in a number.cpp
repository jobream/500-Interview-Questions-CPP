/*
Name : Aman Jain
Date : 27-6-2020

The idea is to use bitwise << and | operators. By using expression (1<<(k-1)),
we get a number which has all bits 0, except the kth bit. If we do bitwise
OR of this expression with n ie. (n| (1<<(k-1))), we get a number which has all bits same as n except the kth bit which will be set to 1

*/

#include<bits/stdc++.h>
using namespace std;


int main(){
    int num,k;
    cin>>num>>k;

  int temp=1<<(k-1);
  num=num| temp;
  cout<<num<<endl;

}