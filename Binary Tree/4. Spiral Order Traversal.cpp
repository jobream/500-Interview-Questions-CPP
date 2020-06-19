
/*
Date: 13-06-2020
Author: Aman Jain

Problem : Spiral  order traversal (Recursive)
Question Link :  https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1


(Solution to Geeks for geeks)
*/

Method 1: Using two stacks


void printSpiral(Node *root)
{
     stack<Node *> left;
     stack<Node *> right;
     
     if(!root)
     return ;
     
     cout<<root->data<<" ";
     if(root->right)
       left.push(root->right);
     
     if (root->left)
       left.push(root->left);
 
     
     while(!left.empty() || !right.empty()){
         
         if(!left.empty()){
             while(!left.empty()){
                 Node *curr=left.top();
                 left.pop();
                 cout<<curr->data<<" ";
                
                 if(curr->left)
                  right.push(curr->left);
                  
                       if(curr->right)
                   right.push(curr->right);
                  
           
             }
         }else{
             while(!right.empty()){
                Node *curr=right.top();
                 right.pop();
                 cout<<curr->data<<" ";
                 if(curr->right)
                   left.push(curr->right);
                
                 if(curr->left)
                  left.push(curr->left);
                  
                
             }
         }
        }
   }

