/*
Date: 13-06-2020
Author: Aman Jain

Problem : Depth of binary tree (Recursive)
Question Link :  https://leetcode.com/problems/maximum-depth-of-binary-tree/


(Solution to Leetcode)

*/ 


 int maxDepth(TreeNode* root) {
        if(root){
            int x= maxDepth(root->left);
            int y= maxDepth(root->right);
            
            
            return (x>y)?x+1:y+1;
        }
        return 0;
    }