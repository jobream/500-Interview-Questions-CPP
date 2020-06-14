/*
Date: - 14-06-2020
Author: - AMAN JAIN

Problem : - Check for zero sum subarray

Example :
Input: 5
      4 2 -3 1 6

 Output:  2, -3, 1 is the subarray with sum 0.


Methods:
    1. Prefix Sum :O(n)-> Create the prefix sum and if duplicates exist on that prefix sum array then 0 sum subarray exist

  Solution to geeks for geeks question: -    https://practice.geeksforgeeks.org/problems/subarray-with-0-sum/0
*/


#include<bits/stdc++.h>
#include<set>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0 ; i<n; i++){
            cin>>arr[i];
        }
        int prefix_sum[n], curr_sum=0;

        for(int i=0 ; i<n ;i++){
            curr_sum+=arr[i];
            prefix_sum[i]=curr_sum;
        }

         unordered_set<int> st;
         bool ispresent=false;
        for(int i=0; i <n; i++){
            if(st.find(prefix_sum[i])!=st.end() || prefix_sum==0){
                ispresent=true;
                break;
            }
            st.insert(prefix_sum[i]);

     }

     if(ispresent)
     cout<<"Yes"<<endl;
     else cout<<"No"<<endl;
    }
}
