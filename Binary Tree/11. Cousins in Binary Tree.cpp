/*
Date: 21-06-2020
Author: Aman Jain

Problem :  Cousins in Binary Tree
Question Link :  https://leetcode.com/problems/cousins-in-binary-tree/


(Solution to leetcode)
*/ 

Method 1 - Using level order traversal O(n)

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int x_level,x_parent,y_level,y_parent;
        queue<pair<TreeNode*,int>> qu;
            if(root->val==x  || root->val ==y)
                return false;
        
        qu.push({root,0});
        
        while(!qu.empty()){
            pair<TreeNode*,int> pr= qu.front();
            qu.pop();
            
            if(pr.first->val==x)
                x_level=pr.second;
            
            if(pr.first->val==y)
               y_level=pr.second;
            
            if(pr.first->left){
                if(pr.first->left->val==x)
                    x_parent=pr.first->val;
                
                if(pr.first->left->val==y)
                    y_parent=pr.first->val;
                
                qu.push({pr.first->left,pr.second+1});
            }
             if(pr.first->right){
                if(pr.first->right->val==x)
                    x_parent=pr.first->val;
                
                if(pr.first->right->val==y)
                    y_parent=pr.first->val;
                
                qu.push({pr.first->right,pr.second+1});
            }
            
       }
        
        
        if(x_level==y_level){
            if(x_parent!=y_parent)
                return true;
        }
            
        return false;
               
    }
};


Method- 2 Using recursion

class Solution {
public:
    
    int level(TreeNode *root, int x, int lev)
    {
        if(!root)
            return 0;
        
        if(root->val==x)
            return lev;
        
        int l = level(root->left,x,lev+1);
        if(l!=0)
            return l;
        
        return level(root->right,x,lev+1);
    }
    
    int issibling(TreeNode * root, int x)
    {
        if(!root)
            return -1;
        if(root->left)
        if(root->left->val==x)
            return root->val;   
        if(root->right)
        if(root->right->val==x)
            return root->val;
   
        int parent = issibling(root->left,x);
        
        if(parent!=-1)
            return parent;
        
        return issibling(root->right,x);
        
    }
     
    bool isCousins(TreeNode* root, int x, int y) {
        
        if(level(root,x,0)==level(root,y,0) && issibling(root,x)!=issibling(root,y))
            return true;
        else
            return false;
        
    }
};


Method -3 Best Approach

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int recDepth = -1;  //recording the depth of 1st found element
    bool isCousin = false;  //flag that is set if we have nodes as cousins
    
    bool dfs(TreeNode* root, int depth, int x, int y)
    {
        if(!root) return false; //return when you encounter a child node that is not present.
        //like in example tree below. when running for child nodes(left and right) of 4, 5 and left child of 3
        //those nodes will not be there hence return false, because value to be found was not available.
        
        /*
        now restrict the depth for searching.
        If current depth is more than recorded Depth(recDepth) of 1st found element,
        then don't do processing here,
        because the nodes to be checked will not be cousins if not on same depth.
        */
        if((this->recDepth != -1) && (depth > this->recDepth))
            return false;
        
        if(root->val == x || root->val == y)
        {
            if(this->recDepth == -1)
                this->recDepth = depth;
            
            return (this->recDepth == depth);
            /*
            checking whether the 2nd element is found at the same depth or not.
            equivalent to saying:
            if(this.recDepth == depth)   return true;
            else    return false;
            */
        }
        
        bool left = dfs(root->left, depth+1, x, y); //if not found in the current node, check left subtree
        bool right = dfs(root->right, depth+1, x, y);//and check right subtree also
        
        //if found in left subtree and in right subtree, check if they both are not siblings
        if(left && right && (this->recDepth != depth+1))
            this->isCousin = true;
        /*
        this.->recDepth != depth+1
        this checks that nodes are not siblings. Do it on pen and paper,
                              1
                            /   \
                          2       3
                        /   \       \
                      4      5       6
        x=4, y=6.
        
        the only time this will statement will hold true is if both the nodes are siblings.
        i.e. x=4, y=5, then you will see that recDepth == depth+1;
        the other remaining times, depth will be less than recDepth : depth < recDepth
        */
        
        
        //return if the child subtrees(nodes) of this node hold the values to be found or not.
        return (left || right);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, 0, x, y); //dfs (root, current node depth, value 1, value 2);
        return this->isCousin;  //return the status indicated by the flag
    }
};