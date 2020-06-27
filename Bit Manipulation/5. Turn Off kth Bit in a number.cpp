/*
Name : Aman Jain
Date : 27-6-2020


The idea is to use bitwise << , & and ~ operators. By using expression ~(1<<k-1))
we get a number which has all its bits set,except the kth bit. 


*/

#include<bits/stdc++.h>
using namespace std;



int main(){
    int n,k;
    cin>>n>>k;
  
    int temp=1<<k;
    n=n&(~temp);
    cout<<n<<endl;

}