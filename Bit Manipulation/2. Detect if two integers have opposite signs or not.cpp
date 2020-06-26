/*
Name : Aman Jain
Date : 26-6-2020

The expression output (x^y) is negative if x and y have opposite signs. We know that for a positive number, leftmost bit is 0 and for a negative number, it is 1. Node for similar sign integers, the xor operator will set
leftmost bit of output as 0 and for opposite sign intergers, it will set leftmost bit as 1
*/

#include<bits/stdc++.h>
using namespace std;


int main(){
    int num1,num2;
    cin>>num1>>num2;
    int temp=num1^num2;
    if(temp<0)
    cout<<"Opposite signs";
    else
    cout<<"Same signs";
}

