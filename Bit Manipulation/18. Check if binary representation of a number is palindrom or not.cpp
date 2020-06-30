/*
Name : Aman Jain
Date : 30-6-2020

The idea is to construct reverse of binary representation  of n and return true if it is same

*/



#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(unsigned n)
{
    unsigned rev=0;

    unsigned k=n;
    while(k){
        rev=(rev<<1) | (k&1);
        k=k>>1;
    }

    return n==rev;
}





int main(){
  int x;
  cin>>x;

   if(isPalindrome(x))
   cout<<"Yes"<<endl;
   else{
       cout<<"No"<<endl;
   } 

}





