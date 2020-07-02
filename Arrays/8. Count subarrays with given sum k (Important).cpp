/*
Name : Aman jain
Date: 03-07-20

Question : Count Subarrays with given sum k
Problem Link :  https://www.geeksforgeeks.org/number-subarrays-sum-exactly-equal-k/

A simple solution is to traverse all the subarrays and calculate their sum. If sum is equal to the required sum then increment the count of subarrays. Print final count of subarrays.

An efficient solution is while traversing the array, store sum so far in currsum. Also maintain count of different values of currsum in a map. If value of currsum is equal to desired sum at any instance increment count of subarrays by one. The value of currsum exceeds desired sum by currsum – sum. If this value is removed from currsum then desired sum can be obtained. From the map find number of subarrays previously found having sum equal to currsum-sum. Excluding all those subarrays from current subarray, gives new subarrays having desired sum. So increase count by the number of such subarrays. Note that when currsum is equal to desired sum then also check number of subarrays previously having sum equal to 0. Excluding those subarrays from current subarray gives new subarrays having desired sum. Increase count by the number of subarrays having sum 0 in that case.



Solution to geeks for geeks :

*/

// C++ program to find number of subarrays 
// with sum exactly equal to k. 
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to find number of subarrays  
// with sum exactly equal to k. 
int findSubarraySum(int arr[], int n, int sum) 
{ 
    // STL map to store number of subarrays 
    // starting from index zero having  
    // particular value of sum. 
    unordered_map<int, int> prevSum; 
  
    int res = 0; 
  
    // Sum of elements so far. 
    int currsum = 0; 
  
    for (int i = 0; i < n; i++) { 
  
        // Add current element to sum so far. 
        currsum += arr[i]; 
  
        // If currsum is equal to desired sum, 
        // then a new subarray is found. So 
        // increase count of subarrays. 
        if (currsum == sum)  
            res++;         
  
        // currsum exceeds given sum by currsum  
        //  - sum. Find number of subarrays having  
        // this sum and exclude those subarrays 
        // from currsum by increasing count by  
        // same amount. 
        if (prevSum.find(currsum - sum) !=  
                                  prevSum.end())  
            res += (prevSum[currsum - sum]); 
          
  
        // Add currsum value to count of  
        // different values of sum. 
        prevSum[currsum]++; 
    } 
  
    return res; 
} 
  
int main() 
{ 
    int arr[] = { 10, 2, -2, -20, 10 }; 
    int sum = -10; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << findSubarraySum(arr, n, sum); 
    return 0; 
} 
