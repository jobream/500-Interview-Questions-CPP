/*
Date: - 29-07-2021
Author: - Sri Subathra Devi B
Problem : - Consider an m litre jug and an n litre jug where 0 < m < n. Both the jugs are initially empty and there are no markings to measure smaller quantities. 
            Determine the minimum no of operations to be performed to obtain v litres of water (v<n) in one of jug.
Example : 
Input: arr =[8,7,2,5,3,1]
      sum: 10
 Output: Pair found at index 0 and 2 (8+2)
        or
        Pair found at index 1 and 4 (7+3)
Methods:    
    1. Always pour from m liter jug into n liter jug
        * Fill the m litre jug and empty it into n liter jug.
        * Whenever the m liter jug becomes empty fill it.
        * Whenever the n liter jug becomes full empty it.
        * Repeat steps 1,2,3 till either n liter jug or the m liter jug contains d litres of water.
    2. Always pour from n liter jug into m liter jug
        * Fill the n liter jug and empty it into m liter jug.
        * Whenever the n liter jug becomes empty fill it.
        * Whenever the m liter jug becomes full empty it.
        * Repeat steps 1, 2 and 3 till either n liter jug or the m liter jug contains d liters of water.

*/
#include <bits/stdc++.h>
using namespace std;

int min(int a,int b){
    if(a<b){
        return a;
    }else{
        return b;
    }
}
int gcd(int x, int  y){
    if(y==0){
        return x;
    }
    return gcd(y,x%y);
}
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
int pour(int n,int m,int v){
    //Initially fill jug n 
    int n_fill=n;
    int m_fill=0;
    int count=1;
    while(n_fill!=v && m_fill!=v){
        int temp=min(n_fill,m-m_fill);//amount of water that can be poured
        n_fill=n_fill-temp;
        m_fill=m_fill+temp;
        //When jug m is full, empty it
	    if(m_fill==m){
            m_fill=0;
            count++;
        }
        //when jug n is empty, fill it
        if(n_fill==0){
            n_fill=n;
            count++;
        }
        if((n_fill==v)||(m_fill==v)){
            break;
        }
        count++;
    }
    return count;
}
int waterJug(int m,int n,int v){
    if(m>n){
        swap(&m,&n);
    }
    if(v>n){
        return -1;
    }
    if((v%gcd(m,n))!=0){
        return -1;
    }
    return min(pour(n,m,v),pour(m,n,v));
}

int main(){
    int m=3,n=5;
    int v;
    cout<<"Enter the litres of water to be measured:";
    cin>>v;
    int l=waterJug(m,n,v);
    if(l==-1){
        cout<<"Cannot be measured";
    }else{
        cout<<"Minimum number of steps required"<<l;
    }
    return 0;
}
