/*
Name : Aman jain
Date: 16-06-20

Question :  Implement queue using stacks
Problem Link : https://leetcode.com/problems/implement-stack-using-queues/

Solution to leetcode :

*/
Method-1 


class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> st;
     stack<int> st1;
     int top1;
    
    MyQueue() {
      top1=-1;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(st.empty())
            top1=x;
               st.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(st.size()==1){
            int temp=st.top();
            st.pop();
            return temp;
        }
        
        while(st.size()!=1){
            st1.push(st.top());
            st.pop();
        }
        int temp=st.top();
        top1=st1.top();
        st.pop();
        while(!st1.empty()){
            st.push(st1.top());
            st1.pop();
        }
        return temp;
        
    }
    
    /** Get the front element. */
    int peek() {
        return top1;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(st.empty())
            return true;
        else
            return false;
    }
};
