/*
Name : Aman jain
Date: 23-06-20

Question : Maximum Product of two elements in an array
Problem Link : https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/

Solution to leetcode :

*/

Method 1 - > Find maximum element twice O(n) (Only for positive numbers)
   int max_elements(vector<int> &v){
        int max=-9999;
        int index=-1;
        for(int i=0; i<v.size() ;i++){
            if(v[i]>max){
                max=v[i];
                index=i;   
            }
        }
        v[index]=-9999;
        return max;
    }
        
    int maxProduct(vector<int>& nums) {
       int max1= max_elements(nums)-1;
        int max2=max_elements(nums)-1;
        return (max1*max2);
    }


Method -2
An Efficient Solution can solve the above problem in single traversal of input array. The idea is to traverse the input array and keep track of following four values.
a) Maximum positive value
b) Second maximum positive value
c) Maximum negative value i.e., a negative value with maximum absolute value
d) Second maximum negative value.
At the end of the loop, compare the products of first two and last two and print the maximum of two products. Below is the implementation of this idea.

// A O(n) C++ program to find maximum product pair in an array 
#include<bits/stdc++.h> 
using namespace std; 
  
// Function to find maximum product pair in arr[0..n-1] 
void maxProduct(int arr[], int n) 
{ 
    if (n < 2) 
    { 
        cout << "No pairs exists\n"; 
        return; 
    } 
  
    if (n == 2) 
    { 
        cout << arr[0] << " " << arr[1] << endl; 
        return; 
    } 
  
    // Iniitialize maximum and second maximum 
    int posa = INT_MIN, posb = INT_MIN; 
  
    // Iniitialize minimum and second minimum 
    int nega = INT_MIN, negb = INT_MIN; 
  
    // Traverse given array 
    for (int i = 0; i < n; i++) 
    { 
        // Update maximum and second maximum if needed 
        if (arr[i] > posa) 
        { 
            posb = posa; 
            posa = arr[i]; 
        } 
        else if (arr[i] > posb) 
            posb = arr[i]; 
  
        // Update minimum and second minimum if needed 
        if (arr[i] < 0 && abs(arr[i]) > abs(nega)) 
        { 
            negb = nega; 
            nega = arr[i]; 
        } 
        else if(arr[i] < 0 && abs(arr[i]) > abs(negb)) 
            negb = arr[i]; 
    } 
  
    if (nega*negb > posa*posb) 
        cout << "Max product pair is {" << nega << ", "
             << negb << "}"; 
    else
        cout << "Max product pair is {" << posa << ", "
             << posb << "}"; 
} 
  
// Driver program to test above function 
int main() 
{ 
    int arr[] = {1, 4, 3, 6, 7, 0}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    maxProduct(arr, n); 
    return 0; 
} 