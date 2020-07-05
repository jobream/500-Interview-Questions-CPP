/*
Author : AMAN JAIN
DATE: 05-07-2020


Program : Bfs 
Program link : https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

Solution for geeksforgeeks


*/

Method-1 Using queue( O(V+E))


vector <int> bfs(vector<int> g[], int N) {
     vector<int> v;
     queue<int> qu;
     qu.push(0);
     int visited[N]={0};
     visited[0]=1;

     while(!qu.empty()){
         int cur = qu.front();
         qu.pop();
         v.push_back(cur);
         for(auto itr = g[cur].begin() ; itr!=g[cur].end();++itr){
             if(visited[*itr]==0){
                 qu.push(*itr);
                 visited[*itr]=1;
             }
    }}
    return v;
     
}