/*
Name : Aman Jain
Date : 25-06-2020

Given a graph and a source vertex src in graph, find shortest paths from src to all vertices in the given graph. The graph may contain negative weight edges.

Dijkstra’s algorithm is a Greedy algorithm and time complexity is O(VLogV) (with the use of Fibonacci heap). Dijkstra doesn’t work for Graphs with negative weight edges, Bellman-Ford works for such graphs. Bellman-Ford is also simpler than Dijkstra and suites well for distributed systems. But time complexity of Bellman-Ford is O(VE), which is more than Dijkstra.



Following are the detailed steps.

Input: Graph and a source vertex src
Output: Shortest distance to all vertices from src. If there is a negative weight cycle, then shortest distances are not calculated, negative weight cycle is reported.

1) This step initializes distances from the source to all vertices as infinite and distance to the source itself as 0. Create an array dist[] of size |V| with all values as infinite except dist[src] where src is source vertex.

2) This step calculates shortest distances. Do following |V|-1 times where |V| is the number of vertices in given graph.
…..a) Do following for each edge u-v
………………If dist[v] > dist[u] + weight of edge uv, then update dist[v]
………………….dist[v] = dist[u] + weight of edge uv

3) This step reports if there is a negative weight cycle in graph. Do following for each edge u-v
……If dist[v] > dist[u] + weight of edge uv, then “Graph contains negative weight cycle”
The idea of step 3 is, step 2 guarantees the shortest distances if the graph doesn’t contain a negative weight cycle. If we iterate through all edges one more time and get a shorter path for any vertex, then there is a negative weight cycle

*/


#include<bits/stdc++.h>
using namespace std;

void bellmanFord (vector<pair<int,pair<int,int>>> Graph,int ver,int e, int src){
  int V=ver;
  int E=e;
  int dist[V];

  for(int i = 0; i<V;i++)
      dist[i]=INT_MAX;
  dist[src]=0;    
  
  for(int j=0 ; j<V-1; j++){
      for(int i=0  ;i<E; i++){
          int u=Graph[i].first;
          int v= Graph[i].second.first;
          int weight=Graph[i].second.second;

          if(dist[u]+weight<dist[v] && dist[u]!=INT_MAX){
              dist[v]=dist[u]+weight;
          }
      }
  }
  

//   Check for negative weight cycle
 for(int i=0  ;i<E; i++){
          int u=Graph[i].first;
          int v= Graph[i].second.first;
          int weight=Graph[i].second.second;

          if(dist[u]+weight<dist[v] && dist[u]!=INT_MAX){
              cout<<"Graph contains negative weight cycle"<<endl;
              return;
          }
      }
         for(int i=0 ; i<V; i++){
      cout<<i<<" --->"<<dist[i]<<endl;
  }
 
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<pair<int,pair<int,int>>> Graph;
    for(int i=0 ; i<e; i++){
        int x,y,w;
        cin>>x>>y>>w;
        Graph.push_back({x,{y,w}});
    }
    bellmanFord(Graph,v,e,0);
}