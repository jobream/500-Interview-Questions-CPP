/*
Name : Aman jain
Date: 16-06-20

Question : Sort a binary Array in linear time 
Problem Link : https://www.geeksforgeeks.org/sort-binary-array-using-one-traversal/

Solution to geeks for geeks :

*/
Method-1 (Two traversals)  :  Count the occurence of 0's and 1's and fill the array according to the occurence;
 

 void sortBinary(int arr[], int n){
    int count0=0,count1=0;
     for(int i=0; i<n ; i++){
        count0++;
     }
     count1=n-count0-1;
     for(int i=0 ; i<n ;i++){
         if(count0){
             arr[i]=0;
             count0--;
         }
         else{
             arr[i]=1;
             count1--;
         }

     }
 }


 Method-2 (One Traversal) : Use two pointer algorithm

   void sortBinary(int arr[], int n){
       int left=0,right=n-1;
       while(left<right){
           if(arr[left]==1 && arr[right]==0){
               swap(arr[left],arr[right]);
               left++;
               right--;
           }
           else if(arr[left]==0 && arr[right]==0 ){
               left++;   
           }
           else if(arr[left]==1 && arr[right]==1){
               right--;
           }
           else{
               left++;
               right--;
           }

       }

   }


   Method- 3 (Best Approach) : Use quick sort partition function taking 1 as pivot
   

   void sortBinaryArray(int a[], int n) 
    { 
    int j = -1; 
    int pivot=1;
    for (int i = 0; i < n; i++) { 
  
        if (a[i] < pivot) { 
            j++; 
            swap(a[i], a[j]); 
        } 
    } 
} 
