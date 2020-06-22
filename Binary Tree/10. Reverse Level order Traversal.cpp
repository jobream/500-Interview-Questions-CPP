/*
Date: 22-06-2020
Author: Aman Jain

Problem : Reversal level order traversal (Recursive)
Question Link :  https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1


(Solution to geeks for geeks)
*/ 

Method 1-  Using level order traversal O(n)

void reversePrint(Node *root){
  vector<int> v;
  queue<Node *> qu;
  qu.push(root);
  while(!qu.empty()){
      Node *t = qu.front();
      v.push_back(t->data);
      qu.pop();
      if(t->right)
      qu.push(t->right);
      
      if(t->left)
      qu.push(t->left);
  }
  for(auto itr = v.rbegin() ;itr!=v.rend() ;++itr){
      cout<<*itr<<" ";
  }
}
