/*
Name : Aman Jain
Date : 26-6-2020

This is probably one of the simplest and most commonly used bit
hack. The expression (n &1) will return 1 if the number is off or 
else it would return 0.

*/

#include<bits/stdc++.h>
using namespace std;


int main(){
    int number;
    cin>>number;

    if(number&1)
    cout<<"It is an odd number"<<endl;
    else
    cout<<"It is an even number"<<endl;
}

