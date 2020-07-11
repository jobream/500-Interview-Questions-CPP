 /*
Author : AMAN JAIN
DATE: 11-07-2020

Program : Prims Algorithm 
Question linK: https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1


 STL provides priority_queue, but the provided priority queue doesn’t support decrease key operation. And in Prim’s algorithm, we need a priority queue and below operations on priority queue :

ExtractMin : from all those vertices which have not yet been included in MST, we need to get vertex with minimum key value.

DecreaseKey : After extracting vertex we need to update keys of its adjacent vertices, and if new key is smaller, then update that in data structure.

The algorithm discussed here can be modified so that decrease key is never required. The idea is, not to insert all vertices in priority queue, but only those which are not MST and have been visited through a vertex that has included in MST. We keep track of vertices included in MST in a separate boolean array inMST[].

Time complexity : O(ElogV)

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int verti,edges;
    cin>>verti>>edges;
   
    int visited[verti]={0};

    vector<pair<int,int>> graph[verti];
    for(int i=0 ; i<edges; i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }


    // min heap
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;

    long long int mst=0;    
    Q.push({0,0}); //weight,node;

    while(!Q.empty()){
        pair<int,int> node=Q.top();
        Q.pop();
        int vertices=node.second;
        int weight=node.first;
        if(visited[vertices])
        continue;

        visited[vertices]=1;
        mst+=weight;

        for(auto x: graph[vertices])
           if(visited[x.first]==0)
             Q.push({x.second,x.first});
        
    }
    cout<<mst<<endl;
}