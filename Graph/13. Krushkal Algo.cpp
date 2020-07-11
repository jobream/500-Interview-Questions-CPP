 /*
Author : AMAN JAIN
DATE: 11-07-2020

Program : Krushkal
Question linK: https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1


 STL provides priority_queue, but the provided priority queue doesn’t support decrease key operation. And in Prim’s algorithm, we need a priority queue and below operations on priority queue :

ExtractMin : from all those vertices which have not yet been included in MST, we need to get vertex with minimum key value.

DecreaseKey : After extracting vertex we need to update keys of its adjacent vertices, and if new key is smaller, then update that in data structure.

The algorithm discussed here can be modified so that decrease key is never required. The idea is, not to insert all vertices in priority queue, but only those which are not MST and have been visited through a vertex that has included in MST. We keep track of vertices included in MST in a separate boolean array inMST[].

Time complexity : O(ElogV)

*/

#include<bits/stdc++.h>
using namespace std;

struct DisjoinSets
{
    int *parent,*rank;
    int n;
    DisjoinSets(int n)
    {
        this->n=n;
        parent=new int[n+1];
        rank= new int[n+1];
        for(int i=0 ; i<=n ; i++){
            parent[i]=i;
            rank[i]=0;
        }
    }
    int find(int u){
        if(parent[u]==u)
         return u;
         parent[u]=find(parent[u]);
         return parent[u];
    }
    void unite(int u, int v){
        int u_rep= find(u);
        int v_rep=find(v);
    
        if(u_rep==v_rep)
        return;
            
        if(rank[u_rep]>rank[v_rep])
            parent[v_rep]=u_rep;

        else if(rank[u_rep]<rank[v_rep])
            parent[u_rep]=v_rep;
         else{
             rank[v_rep]++;
             parent[u_rep]=v_rep;
         }    
    }
    
};

int main(){
    int v,e;
    cin>>v>>e;
    vector<pair<int,pair<int,int>>> Graph;

    for(int i =0 ;  i<e ;i++){
        int x,y,w;    
        cin>>x>>y>>w;
        Graph.push_back({w,{x,y}});
    }

    long long mst_wt=0;

    sort(Graph.begin(),Graph.end());

    DisjoinSets ds(v);

    for(auto itr= Graph.begin() ;itr!=Graph.end() ;++itr){
        int u= itr->second.first;
        int v= itr->second.second;

        int u_rep=ds.find(u);
        int v_rep=ds.find(v);
        if(u_rep!=v_rep){
            cout<<u<<" "<<v<<endl;
            mst_wt+=itr->first;
            ds.unite(u_rep,v_rep);
        }
    }
    

    cout<<"Minimium Weight "<<mst_wt<<endl;
  

}
