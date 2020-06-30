/*
 Name : Aman Jain
 Date: 27-06-2020

The expresion (n&(n-1)) will unset the rightmost set bit of a number. If the number is power of 2,it has only one bit set and (n & (n-1)) will unset
the only set bit. So we can say that (n&(n-1)) returns 0 if n is power of 2
else it is not a power of 2



for example: 


00010000   &   (n=16)
00001111       (n-1=15)
---------
00000000

 
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    n=n&(n-1);
    if(!n)
    cout<<"Power of 2"<<endl;
    else{
        cout<<"Not power of 2"<<endl;
    }
}