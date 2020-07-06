/*
Author : Aman Jain 
Date: 06-07-2020

problem - Check if a graph is bipartite or not
question link - https://practice.geeksforgeeks.org/problems/bipartite-graph/1

*/

/*
Method -1 (O(V+E))-> Using dfs- check if the graph has odd cycle or not, if it does then it is not a bipartite graph because we won't be able to color different colors to its adjacent nodes
*/

#include<bits/stdc++.h>
using namespace std;

int odd_cycle=0;



void dfs(vector<int>Graph [], int start, int parent, int color, int visited[]){
    visited[start]=color;
      //    Color : //  0: Not visited //  1: Visited and color 1 //  2: Visited and color 2
      for(auto  itr=Graph[start].begin() ; itr!=Graph[start].end() ;++itr){
          if(visited[*itr]==0){
              dfs(Graph,*itr,start,3-color,visited);
          }else if(visited[*itr]==color && parent!=*itr){
              odd_cycle=1;
          }
      }
}

int main(){
    int v,e;
    cin>>v>>e;

    vector<int> Graph[v];
    for(int i=0 ; i<e ;i++){
        int x,y;
        cin>>x>>y;
        Graph[x].push_back(y);
        Graph[y].push_back(x);
    }

    int visited[v]={0};
    

    if(odd_cycle)
      cout<<"No Graph is not bipartite"<<endl;

     else{
         cout<<"Yes Graph is bipartitie"<<endl;
     } 




}