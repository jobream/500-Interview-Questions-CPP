/*
Author : AMAN JAIN
DATE: 06=8-07-2020

Program : Cycle detection in Undirected Graph using dfs
Program link : https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

Solution for geeksforgeeks

 Run a DFS from every unvisited node. Depth First Traversal can be used to detect a cycle in a Graph. DFS for a connected graph produces a tree. There is a cycle in a graph only if there is a back edge present in the graph. A back edge is an edge that is joining a node to itself (self-loop) or one of its ancestor in the tree produced by DFS.
To find the back edge to any of its ancestor keep a visited array and if there is a back edge to any visited node then there is a loop and return true.

TIME COMPLEXITY - O(v+e)
*/


#include<bits/stdc++.h>
using namespace std;



int  hasCycle=0;


void CycleDetection(vector<int> Graph[],int visited[], int start, int parent){
    visited[start]=1;

    vector<int> :: iterator itr;
   for( itr= Graph[start].begin() ; itr!=Graph[start].end() ; itr++){
       if(visited[*itr]==1 && *itr!=parent)
        hasCycle=1;

       else if(visited[*itr]==0){
           CycleDetection(Graph,visited,*itr,start);
       }
   }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int V,E;
        cin>>V>>E;
        vector<int> Graph[2*V];
        for(int i=0 ; i<E; i++){
            int x,y;
            cin>>x>>y;
            Graph[x].push_back(y);
            Graph[y].push_back(x);
        }
        int visited[V]={0};
        for(int i=0  ;i<V ;i++)
        if(visited[i]==0)
        CycleDetection(Graph,visited,i,-1);

        cout<<hasCycle<<endl;
        hasCycle=0;
    }
}