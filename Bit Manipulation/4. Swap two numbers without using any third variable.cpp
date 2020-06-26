/*
Name : Aman Jain
Date : 26-6-2020

This one is simple and most commonly used bit hack. The idea is to use
XOR operators for swapping two numbers by their property that (x^x=0).

*/


#include<bits/stdc++.h>
using namespace std;


int main(){
    int num1,num2;
    cin>>num1>>num2;

    num1=num1^num2;
    num2=num2^num1;
    num1=num1^num2;
}