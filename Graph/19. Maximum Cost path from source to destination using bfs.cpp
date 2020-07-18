/*
Name : Aman Jain
Date : 18-07-2020

Given a weighted graph, find the maximum cost path from given source to destination that is greater than a given integer x. The path should not contain any cycles.

The idea is to use BFS traversal. Bfs is generally used to find shorted paths in graphs but we can modify normal bfs to meet our requirements. By modiying BFS, we dont mean using priority queue that picks up the maximum weighted edge at every step as that approach will definitely fail. A low eight edge can be involved in maximum cost path as there might be higher weight edges connected through it.


Usually Bfs don't explore already discovered vertex again, but here we do the opposite. In order to cover all possible paths from given source, we remoe this check from a BFS. But if the graph contains a cycle, removing this check  will cause program to go into an infinite loop. We can easily handle that if maintain a list of nodes visied so far in current path for a node a queue. Basically we maintain three things in BFS queue node.

  1. current vertex number
  2. Cost of current path chosen
  3. Set of nodes visited so far in current path

*/

#include<bits/stdc++.h>
using namespace std;




int modifiedBfs(vector<pair<int,int>> Graph[],int src,int cost, int v){
    queue<pair<pair<int, int>,set<int>>> q;
    set<int> vertices;
    vertices.insert(0);
    q.push({{0,0},vertices});

    int maxCost=INT_MIN;

    while(!q.empty()){
        pair<pair<int, int>,set<int>> pr=q.front();
        q.pop();
        int v= pr.first.first;
        int wt= pr.first.second;
        vertices=pr.second;
 
        if(wt>cost){
            maxCost=max(wt,maxCost);
        }
        for(auto itr=Graph[v].begin() ;itr!=Graph[v].end() ;itr++){
            if(vertices.find(itr->first)== vertices.end()){
                set<int> s=vertices;
                s.insert(itr->first);
                q.push({{itr->first,wt+itr->second},s});
            }
        }



    }
  return maxCost;
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<pair<int,int>> Graph[v];
    for(int i=0 ; i<e; i++){
        int u,v,w;
        cin>>u>>v>>w;
        Graph[u].push_back({v,w});
        Graph[v].push_back({u,w});
    }
    int src=0;
    int cost=50; 
     //We are looking for path that is greater than 50
    int max_cost=modifiedBfs(Graph,src,cost,v);
    if(max_cost!=INT_MIN){
        cout<<max_cost<<endl;
    }else{
        cout<<"All paths are less than "<<cost<<endl;
    }

}


