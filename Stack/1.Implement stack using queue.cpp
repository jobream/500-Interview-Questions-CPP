
/*
Name : Aman jain
Date: 16-06-20

Question :  Implement Stack using queues
Problem Link : https://leetcode.com/problems/implement-stack-using-queues/

Solution to leetcode :

*/


Method 1: Making pop operation expensive

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int > q1;
    queue<int> q2;
    int top1;
    
    MyStack() {
      top1=0;
    }
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
        top1=x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while(q1.size()!=1){
            int num=q1.front();
            q2.push(num);
            q1.pop();
        }
        
        int pop_elem=q1.front();
        q1.pop();
        while(!q2.empty()){
            if(q2.size()==1)
                top1=q2.front();
            q1.push(q2.front());
            q2.pop();
            
        }
        
        return pop_elem;
        
    }
    
    /** Get the top element. */
    int top() {
        return top1;
    }  
    /** Returns whether the stack is empty. */
    bool empty() {
        if(q1.empty())
            return true;
        else
            return false;
    }
};

Method 2: Making push operation expensive

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int > q1;
    queue<int> q2;
    int top1;
    
    MyStack() {
      top1=0;
    }
    /** Push element x onto stack. */
    void push(int x) {
       if(q1.empty()){
           q1.push(x);
           top1=x;
           while(!q2.empty()){
               q1.push(q2.front());
               q2.pop();
           }
       }else{
           q2.push(x);
           top1=x;
           while(!q1.empty()){
               q2.push(q1.front());
               q1.pop();
           }
       } } 
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
       if(q1.empty())
       {
           int temp=q2.front();
           q2.pop();
           top1=q2.front();
           return temp;
       }
        else{
           int temp=q1.front();
           q1.pop();
           top1=q1.front();
           return temp; 
            
        }
    }
    
    /** Get the top element. */
    int top() {
        return top1;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(q1.empty() && q2.empty())
            return true;
        else
            return false;
    }
};