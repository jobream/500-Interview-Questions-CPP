/*
Date: 21-06-2020
Author: Aman Jain

Problem : Right view of  binary tree (Recursive)
Question Link :  https://leetcode.com/problems/binary-tree-right-side-view/


(Solution to leetcode)
*/ 


Method - 1 Using Level order traversal (Print last Node of every level) (O(nlogn))

 vector<int> rightSideView(TreeNode* root) {

  vector<int> v;      
  map<int, vector<int>> mp;
  queue<pair<TreeNode*, int>> qu;
  if(!root)
  return v ;
  qu.push(make_pair(root,0));
  while(!qu.empty()){
      pair<TreeNode *,int> pr=qu.front();
      qu.pop();
      mp[pr.second].push_back(pr.first->val);
      
      if(pr.first->left)
      qu.push(make_pair(pr.first->left,pr.second+1));
      
     if(pr.first->right)
      qu.push(make_pair(pr.first->right,pr.second+1));
  }
  
  for(auto itr= mp.begin() ;itr!=mp.end() ;itr++){
      if(itr->second.size()>0)
         v.push_back(itr->second[itr->second.size()-1]);
  }
        return v;
    }


    Method -2 (Using recursion & pre order traversal) O(n)

    void rightViewUtil(struct Node *root,  
                   int level, int *max_level) 
{ 
    // Base Case 
    if (root == NULL) return; 
  
    // If this is the last Node of its level 
    if (*max_level < level) 
    { 
        cout << root->data << "\t"; 
        *max_level = level; 
    } 
  
    // Recur for right subtree first,  
    // then left subtree 
    rightViewUtil(root->right, level + 1, max_level); 
    rightViewUtil(root->left, level + 1, max_level); 
} 
  
// A wrapper over rightViewUtil() 
void rightView(struct Node *root) 
{ 
    int max_level = 0; 
    rightViewUtil(root, 1, &max_level); 
} 
  