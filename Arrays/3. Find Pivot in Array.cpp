/*
Name : Aman jain
Date: 15-06-20

Question : Find pivot(Equilibrium) in  Array
Problem Link : https://leetcode.com/problems/find-pivot-index/

Solution to leetcode :


*/

Method 1:(Naive Solution) (O(n^2))
 Naive approach is to calculate sum of elements to the left and sum of element to the right for each element  of the array. If left sum-array sum is equal to the right sum-array the we print the index.



Method 2: (Linear Time solution) (O(n)Time O(n) space)
Create two array left[] and right [] stores sum of prefix sum and suffix sum respectively. After that traverse both the array from left to right and if any element is same between the two array then we print the index



class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int length=nums.size();
      int left[100005],right[100005];
         int sum=0;
        for(int i=0 ; i<length ;i++){
            sum+=nums[i];
            left[i]=sum;
        } sum=0;
         for(int i=length-1 ; i>=0 ;i--){
            sum+=nums[i];
            right[i]=sum;
        }        
        for(int i=0; i<length ;i++){
            if(left[i]==right[i])
                return i;
        }
     return -1;      
    }
};


Method 3 : (Best Approach) (O(1) Space O(n) Time)

We can avoid using extra space. The idea is to calcuate the sum of all elements of the array. Then we start from the first element of the array and maintain left sub-array sum. We can calculate right suub-array sum in constant time by substracting left sub-array sum and current element from total sum:



class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int sum=0;
        
        for(int x: nums){
            sum+=x;
        }
        
        int left_sum=0,right_sum=sum;
        for(int i=0 ; i<nums.size()  ;i++){
            left_sum+=nums[i];    
            if(left_sum==right_sum)
                return i;
            right_sum-=nums[i];
            
        }
                
        return -1;        
    }
};