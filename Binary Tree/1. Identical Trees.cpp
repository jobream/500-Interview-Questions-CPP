/*
Date: 13-06-2020
Author: Aman Jain

Problem : Reverse A linked list (Recursive)
Question Link :   https://leetcode.com/problems/same-tree/


(Solution to Leetcode)

*/ 
 
   bool isSameTree(TreeNode* p, TreeNode* q) {     
        if(!p && !q)
            return true;
        
         if(!p || !q)
            return false;
    
        return (p->val==q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
   }