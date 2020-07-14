/*
Name : Aman Jain
Date: 25-06-2020
For Dijkstra’s algorithm, it is always recommended to use heap (or priority queue) as the required operations (extract minimum and decrease key) match with speciality of heap (or priority queue). However, the problem is, priority_queue doesn’t support decrease key. To resolve this problem, do not update a key, but insert one more copy of it. So we allow multiple instances of same vertex in priority queue. This approach doesn’t require decrease key operation and has below important properties.
Whenever distance of a vertex is reduced, we add one more instance of vertex in priority_queue. Even if there are multiple instances, we only consider the instance with minimum distance and ignore other instances.
The time complexity remains O(ELogV)) as there will be at most O(E) vertices in priority queue and O(Log E) is same as O(Log V
1) Initialize distances of all vertices as infinite.
2) Create an empty priority_queue pq.  Every item
   of pq is a pair (weight, vertex). Weight (or 
   distance) is used used as first item  of pair
   as first item is by default used to compare
   two pairs
3) Insert source vertex into pq and make its
   distance as 0.
4) While either pq doesn't become empty
    a) Extract minimum distance vertex from pq. 
       Let the extracted vertex be u.
    b) Loop through all adjacent of u and do 
       following for every vertex v.
           If there is a shorter path to v
           through u. 
           If dist[v] > dist[u] + weight(u, v)
               (i) Update distance of v, i.e., do
                     dist[v] = dist[u] + weight(u, v)
               (ii) Insert v into the pq (Even if v is
                    already there)
               
5) Print distance array dist[] to print all shortest
   paths. 
*/

#include<bits/stdc++.h>
using namespace std;

#define INF 99999

void dijkstra(vector<pair<int,int>> graph[], int verti,int src){
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  
  vector<int> dist(verti,INF);

  pq.push(make_pair(0,src));
  dist[src]=0;

  while(!pq.empty()){
      int u=pq.top().second;
      pq.pop();
      for(auto itr=graph[u].begin() ;itr!=graph[u].end() ;itr++){

          int v=(*itr).first;
          int weight=(*itr).second;

          if(dist[u]+weight<dist[v]){
             dist[v]=dist[u]+weight;
             pq.push(make_pair(dist[v],v));
          }
      }
  }
  for(int i=0; i<verti;i++){
      cout<<i<<"--->"<<dist[i]<<endl;
  }
}

int main(){
    int v,e;
    cin>>v>>e;

    vector<pair<int,int>> graph[v];
    for(int i=0; i <e ; i++){
        int x,y,w;
        cin>>x>>y>>w;
        graph[x].push_back({y,w});
        graph[y].push_back({x,w});
    }

    dijkstra(graph,v,0);

}