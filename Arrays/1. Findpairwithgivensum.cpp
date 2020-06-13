/*
Date: - 12-06-2020
Author: - AMAN JAIN

Problem : - Find pair with given Sum
Question- Link: - https://leetcode.com/problems/two-sum/

Example : 
Input: arr =[8,7,2,5,3,1]
      sum: 10

 Output: Pair found at index 0 and 2 (8+2)
        or
        Pair found at index 1 and 4 (7+3)

Methods:    
    1. Brute Force O(n*n)  - (Generate all pair using two for loops and check for each pair)
    2. Sorting O(nlogn) -  (Sort the array and use two pointer algorithm)
    3. Hashing O(n) - (Create a hashmap which stores value of target-arr[i] and perform find operation)
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
   int size;
   cin>>size;
   int arr[size];
  
   for(int i=0; i<size ; i++){
       cin>>arr[i]; }
  
   int target ;cin>>target;
   unordered_map<int,int> Mp;

   for(int i=0 ; i<size ;i++)
   {
       if(Mp.find(target-arr[i])!=Mp.end()){
           cout<<"Pair found at "<<i<<" and "<<Mp[target-arr[i]]; 
           return ;
       }
       Mp[arr[i]]=i;
   }  
cout<<"Not found"<<endl;
   
}


