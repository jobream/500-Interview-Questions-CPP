/*
Name : Aman jain
Date: 16-06-20

Question : Sort a stack using recursion 
Problem Link : https://practice.geeksforgeeks.org/problems/sort-a-stack/1

Solution for Geeks for geeks:

*/


void sortedinsert(stack<int> &s, int x){
    if(s.empty() || x>s.top() ){
        s.push(x);
        return;
    }
    
    int temp= s.top();
    s.pop();
    
    sortedinsert(s,x);
    s.push(temp);
    
    
}

void SortedStack :: sort()
{
   if(!s.empty()){
       int temp= s.top();
       s.pop();
       
       sort();
       sortedinsert(s,temp);
   }
}