
/*
Date: 13-06-2020
Author: Aman Jain

Problem : Level order traversal (Recursive)
Question Link :  https://practice.geeksforgeeks.org/problems/level-order-traversal/1


(Solution to Geeks for geeks)

*/



void levelOrder(Node* node){
    queue<Node *> qu;
    if(!node)
    return;
    qu.push(node);
    
    while(!qu.empty()){
        Node * temp= qu.front();
        qu.pop();
        
        cout<<temp->data<<" ";
        if(temp->left)
        qu.push(temp->left);
        
        if(temp->right)
        qu.push(temp->right);
        
    }
    return ;
     
}