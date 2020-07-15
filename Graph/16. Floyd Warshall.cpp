/*
Name : Aman Jain
Date : 26-06-2020
The Floyd Warshall Algorithm is for solving the All Pairs Shortest Path problem. The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph.
We initialize the solution matrix same as the input graph matrix as a first step. Then we update the solution matrix by considering all vertices as an intermediate vertex. The idea is to one by one pick all vertices and updates all shortest paths which include the picked vertex as an intermediate vertex in the shortest path. When we pick vertex number k as an intermediate vertex, we already have considered vertices {0, 1, 2, .. k-1} as intermediate vertices. For every pair (i, j) of the source and destination vertices respectively, there are two possible cases.
1) k is not an intermediate vertex in shortest path from i to j. We keep the value of dist[i][j] as it is.
2) k is an intermediate vertex in shortest path from i to j. We update the value of dist[i][j] as dist[i][k] + dist[k][j] if dist[i][j] > dist[i][k] + dist[k][j]
Time Complexity: O(V^3)
The above program only prints the shortest distances. We can modify the solution to print the shortest paths also by storing the predecessor information in a separate 2D matrix.
Also, the value of INF can be taken as INT_MAX from limits.h to make sure that we handle maximum possible value. When we take INF as INT_MAX, we need to change the if condition in the above program to avoid arithmetic overflow.
#include 
#define INF INT_MAX
..........................
if ( dist[i][k] != INF && 
     dist[k][j] != INF && 
     dist[i][k] + dist[k][j] < dist[i][j]
    )
 dist[i][j] = dist[i][k] + dist[k][j];
...........................
*/

#include<bits/stdc++.h>
using namespace std;

#define V 100
#define INF 99999

void floydwarshall(int dist[][V], int n){

  for(int k = 0 ; k< n ; k++){
      for(int i=0 ; i<n ; i++){
          for(int j=0; j<n ; j++){
              if(dist[i][k] +dist[k][j]<dist[i][j])
                dist[i][j]=dist[i][k]+dist[k][j];
          } } }

  for(int i=0 ; i<n ; i++){
      for(int j=0  ;j<n  ;j++){
          if(dist[i][j]==INF)
              cout<<"INF"<<" ";
          else
              cout<<dist[i][j]<<" ";

      }
             cout<<endl;
  }
}

int main(){
    int n;
    cin>>n;
    int graph[V][V];
    for(int i=0 ; i<n ; i ++){
        for(int j=0 ; j<n ; j ++){
            // USE 99999 FOR INFINITE
            cin>>graph[i][j];
        } }
        
    floydwarshall(graph,n);
}