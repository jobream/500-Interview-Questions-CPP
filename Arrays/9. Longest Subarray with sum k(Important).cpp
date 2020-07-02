/*
Name : Aman jain
Date: 03-07-20

Question :   Longest Subarray with sum k
Problem Link : https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k/0



Initialize sum = 0 and maxLen = 0.

Create a hash table having (sum, index) tuples.

For i = 0 to n-1, perform the following steps:
Accumulate arr[i] to sum.

If sum == k, update maxLen = i+1.

Check whether sum is present in the hash table or not. If not present, then add it to the hash table as (sum, i) pair.

Check if (sum-k) is present in the hash table or not. If present, then obtain index of (sum-k) from the hash table as index. Now check if maxLen < (i-index), then update maxLen = (i-index).
Return maxLen.



Solution to geeks for geeks :

*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    int k;
	    cin>>k;
	    
	    int arr[n];
	    for(int i=0 ; i<n ; i++){
	        cin>>arr[i];
	    }
	    
	    unordered_map<int,int> mp;
	    int currsum=0,maxsum=0;
	    for(int i=0 ; i<n ; i++){
	        currsum+=arr[i];
	        
	        if(currsum==k)
	          maxsum=i+1;
	        
	        if(mp.find(currsum)==mp.end()){
	            mp[currsum]=i;
	       }
	       
	       if(mp.find(currsum-k)!=mp.end()){
	           maxsum=max(maxsum,i-mp[currsum-k]);
	       }
	    }
	    cout<<maxsum<<endl;
	    
	}
	return 0;
}