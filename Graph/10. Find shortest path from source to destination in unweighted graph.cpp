 /*
Author : AMAN JAIN
DATE: 09-07-2020

Program : Find shortest path from source to destination in unweighted graph
Question linK: https://www.geeksforgeeks.org/shortest-path-unweighted-graph/

Algorithm : This problem

TIME COMPLEXITY - O(v+e)

*/

#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> graph[],int source, int destination,int parent[],int v,vector<int> &path){
  parent[source]=-1;
  int visited[v]={0};
  visited[source]=1;
  queue<int> q;
  int stop=0;
  q.push(source);
  while(!q.empty()){
      int temp=q.front();
      q.pop();
      for(auto itr=graph[temp].begin(); itr!=graph[temp].end() ;itr++){
          if(visited[*itr]==0){
              visited[*itr]=1;
              q.push(*itr);
              parent[*itr]=temp;
          }
          if(*itr==destination){
              stop=1;
              break;
          }
      }
      if(stop)
      break;
  }
       path.push_back(destination);
        while(parent[destination]!=-1){
       path.push_back(parent[destination]);
       destination=parent[destination];
   }


}


int main(){
   int v,e;
   cin>>v>>e;
   vector<int> graph[v];
   for(int i=0 ; i<e; i++){
       int x,y;
       cin>>x>>y;
       graph[x].push_back(y);
       graph[y].push_back(x);
   }
   int s,d;
   cin>>s>>d;
    int parent[v]={0};
    vector<int> path;
    bfs(graph,s,d,parent,v,path);

    for(int i=path.size()-1 ; i>=0; i--){
        cout<<path[i]<<" ";
    }

}