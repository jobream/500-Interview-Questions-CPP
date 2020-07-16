/*
Name : Aman Jain
Date : 26-06-2020


https://www.geeksforgeeks.org/detect-negative-cycle-graph-bellman-ford/

*/



#include<bits/stdc++.h>
using namespace std;

#define INF 99999

void bellmanford(vector<pair<int,pair<int,int>> >graph,int v, int e){
   int dist[v];
   for(int i=0 ; i<v; i++){
       dist[i]=INF;
   }
   dist[0]=0;
   for(int j=0 ;j<v-1; j++){
       for(int i=0;i<e ; i++){
           int u=graph[i].first;
           int v= graph[i].second.first;
           int wt=graph[i].second.second;
           if(dist[u]+wt<dist[v])
             dist[v]=dist[u]+wt;
       }
   }

  bool negative_cycle=false;
       for(int i=0;i<e ; i++){
           int u=graph[i].first;
           int v= graph[i].second.first;
           int wt=graph[i].second.second;
           if(dist[u]+wt<dist[v]){
               negative_cycle=true;
               break;
           }
             
       }

       cout<<(negative_cycle==true?"1":"0")<<endl; 

}

int main(){
    int t;
    cin>>t;
    while(t--){
    int v,e;
    cin>>v>>e;
    vector<pair<int,pair<int,int>> > graph;
    for(int i=0; i <e ; i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph.push_back({u,{v,w}});
    }
    bellmanford(graph,v,e);
    }
}