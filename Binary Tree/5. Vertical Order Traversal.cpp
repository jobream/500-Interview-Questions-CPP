
/*
Date: 20-06-2020
Author: Aman Jain

Problem : Verical  order traversal (Recursive)
Question Link : https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1


(Solution to Geeks for geeks)
*/


Method - 1 (Using level order traversal) Time Complexity (nlogn)

vector<int> verticalOrder(Node *root)
{
   queue<pair<Node*, int>> qu;
   vector<int> v;
   if(!root)
   return v;
   map<int,vector<int>> mp;
   int level=0;
   qu.push(make_pair(root,level));
   
   while(!qu.empty()){
       pair<Node *, int> pr=qu.front();
       qu.pop();
       mp[pr.second].push_back(pr.first->data);
       
       if(pr.first->left)
       qu.push(make_pair(pr.first->left,pr.second+1));
       
       if(pr.first->right)
       qu.push(make_pair(pr.first->right,pr.second-1));
      
   }
   for(auto itr = mp.rbegin() ;itr!=mp.rend() ;itr++){
       for(int i=0 ; i<itr->second.size(); i++)
        v.push_back(itr->second[i]);
     
   }
}
