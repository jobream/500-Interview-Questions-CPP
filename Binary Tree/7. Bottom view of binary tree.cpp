/*
Date: 20-06-2020
Author: Aman Jain

Problem : Bottom view of binary tree
Question Link :  https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

(Solution to Geeks for geeks)
*/


Prerequiste(Vertical order Traversal)


Method -1(O(nlogn)) Using level order traversal


vector <int> bottomView(Node *root)
{vector<int> v;
  queue<pair<Node*, int>> qu;
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
        if(itr->second.size()>0)
        v.push_back(itr->second[itr->second.size()-1]);
          
   }
   return v;
}