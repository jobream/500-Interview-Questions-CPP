/*
Author : AMAN JAIN
DATE: 05-07-2020
Program : Arrival and departure time of a vertices using dfs
Program link : https://www.geeksforgeeks.org/printing-pre-and-post-visited-times-in-dfs-of-a-graph/

Solution for geeksforgeeks

*/


#include<bits/stdc++.h>
using namespace std;

void dfstime(vector<int> Graph[],int v, int visited[],vector<int> Timings[],int &time,int start){
     visited[start]=1;
     Timings[start].push_back(time);
     time++;
     for(auto itr=Graph[start].begin() ; itr!=Graph[start].end() ;itr++){
         if(!visited[*itr])
          dfstime(Graph,v,visited,Timings,time,*itr);
     }
     Timings[start].push_back(time);
     time++;
}

int main(){
   int v,e;
   cin>>v>>e;
    vector<int> Graph[v];  //    Assuming directed graph
    for(int i=0; i<e; i++){
        int x,y;
        cin>>x>>y;
        Graph[x].push_back(y);
    }
    vector<int> Timings[v];
    int visited[v]={0};
    int time=0;
    for(int i=0; i<v; i++){
        if(!visited[i])
           dfstime(Graph,v,visited,Timings,time,i);
    }
    
    for(int i=0 ; i<v; i++){
        cout<<i<<"---> ";
        for(auto itr=Timings[i].begin() ;itr!=Timings[i].end() ;itr++){
            cout<<*itr<<" ";
        }
        cout<<endl;
    }

}