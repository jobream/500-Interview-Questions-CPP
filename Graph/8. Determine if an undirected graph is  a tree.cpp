/*
Author : AMAN JAIN
DATE: 08-07-2020

Program : Determine if an undirected graph is a tree

Tree- It is a undirected connected graph with no cycle

An undirected graph is tree if it has following properties.
1) There is no cycle.
2) The graph is connected.


So basically we need to check if the graph is connected and has no cycle.

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
        CycleDetection(Graph,visited,0,-1); //check for cycle

        bool isConnected=true;

        for(int i=0 ; i<V; i++){ //check for nodes which were not reacheable in the last dfs call
            if(visited[i]==0){
                isConnected=false;
                break;
            }
        }
        
        if(isConnected && (!hasCycle))
        cout<<"Yes it is a tree"<<endl;
        else{
            cout<<"No it is not a tree"<<endl;
        }
        hasCycle=0;
    }
}