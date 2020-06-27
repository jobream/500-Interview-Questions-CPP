/*
 Name : Aman Jain
 Date: 27-06-2020


The idea is to use bitwise ^ and << operator. By using expression (1<<k-1),
we get a number which has all bits 0, except the kth bit. If we do bitwise XOR of this expression with n i.e (n^(1<<k)), we can easily toggle its kth
bit a (0^1=1) and (1^1=0)

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    int temp=1<<(k-1);
    n=n^temp;
    cout<<n<<endl;
}