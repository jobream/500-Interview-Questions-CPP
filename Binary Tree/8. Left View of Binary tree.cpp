/*
Date: 21-06-2020
Author: Aman Jain

Problem : Left view of  binary tree (Recursive)
Question Link :  https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1


(Solution to Geeks for geeks)
*/ 


Method - 1 Using Level order traversal (Print first Node of every level) (O(nlogn))

void leftView(Node *root)
{
  map<int, vector<int>> mp;
  queue<pair<Node*, int>> qu;
  if(!root)
  return ;
  qu.push(make_pair(root,0));
  while(!qu.empty()){
      pair<Node *,int> pr=qu.front();
      qu.pop();
      mp[pr.second].push_back(pr.first->data);
      
      if(pr.first->left)
      qu.push(make_pair(pr.first->left,pr.second+1));
      
     if(pr.first->right)
      qu.push(make_pair(pr.first->right,pr.second+1));
  }
  
  for(auto itr= mp.begin() ;itr!=mp.end() ;itr++){
      if(itr->second.size()>0)
        cout<<itr->second[0]<<" ";
  }
  
}



Method -2 (Using recursion & pre order traversal) O(n)

// Recursive function to print left view of a binary tree. 
void leftViewUtil(node* root, int level, int* max_level) 
{ 
    // Base Case 
    if (root == NULL) 
        return; 
  
    // If this is the first node of its level 
    if (*max_level < level) { 
        cout << root->data << "\t"; 
        *max_level = level; 
    } 
  
    // Recur for left and right subtrees 
    leftViewUtil(root->left, level + 1, max_level); 
    leftViewUtil(root->right, level + 1, max_level); 
} 
  
// A wrapper over leftViewUtil() 
void leftView(node* root) 
{ 
    int max_level = 0; 
    leftViewUtil(root, 1, &max_level); 
} 