/*
Author : AMAN JAIN
DATE: 05-07-2020
Program : Dfs
Program link :https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/

Solution for geeksforgeeks

*/

Method-1 Using Recursive stack( O(V+E))


void dfs(int s, vector<int> g[], bool vis[])
{
   cout<<s<<" ";
   vis[s]=true;
   
   for(auto itr= g[s].begin() ;itr!=g[s].end() ;++itr){
       if(vis[*itr]==0)
       {
           dfs(*itr,g,vis);
       }
   }
    
}
 