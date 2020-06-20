/*
Date: 20-06-2020
NAME: Aman Jain


Question : Find duplicate element in a limited range array

Given a limited range array of size n where array contains elements between 1 to n-1 with one element repeating,find  the duplicate number in it

for example,

Input :{1,2,3,4,4}
Output: The duplicate element is 4


Input :{1,2,3,4,2}
Output : The duplicate element is 2

*/

Method 1: Use Hashing (Count the occurence of each element)
We can use a visited boolean array to mark if an element is seen before or not. If the element is already encountered before, the visited array will return true


Method 2: Using Xor operator 
Properties of xor:
1. a^0=a
2. a^b=a^b
3. a^a=0

xor all the elements of array with numbers 1  to n-1 and the result will be the answer



int duplicates ( int arr[], int n){
    int res=0;
    int num=1;
    for(int i=0; i< n ;i++){
        if(num<n)
        res^=num^arr[i];
        else
        res^=arr[i];
    }
    return res;
}

Method 3:  Since all elements of the array are in range 1 to n-1, we can use array elements as index and mark all the elements as negative. 
We need to traverse again and check if an element is positive or not, if it is then it will be the duplicate number


int duplicates (int arr[], int n){
    // 1 index based array
    for(int i=1; i<n ; i++){
        arr[arr[i]]*=-1;
    }
    for(int i=1 ; i<n ;i++){
        if(arr[i]>0)
        return arr[i];
    }
}
This approach takes two traversal, we can achieve this in one  traversal also. for each element arr[i],we invert the sign of element present at index(arr[i]) if it is already negative then that will be our answer 



