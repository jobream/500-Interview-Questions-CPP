 /*
Author : AMAN JAIN
DATE: 10-07-2020

Program : KosaRaju's Algorithm for finding SCC
Question linK: https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

Algorithm : 
 directed graph is strongly connected if there is a path between all pairs of vertices. A strongly connected component (SCC) of a directed graph is a maximal strongly connected subgraph. For example, there are 3 SCCs in the following graph.


We can find all strongly connected components in O(V+E) time using Kosaraju’s algorithm. Following is detailed Kosaraju’s algorithm.
1) Create an empty stack ‘S’ and do DFS traversal of a graph. In DFS traversal, after calling recursive DFS for adjacent vertices of a vertex, push the vertex to stack. In the above graph, if we start DFS from vertex 0, we get vertices in stack as 1, 2, 4, 3, 0.
2) Reverse directions of all arcs to obtain the transpose graph.
3) One by one pop a vertex from S while S is not empty. Let the popped vertex be ‘v’. Take v as source and do DFS (call DFSUtil(v)). The DFS starting from v prints strongly connected component of v. In the above example, we process vertices in order 0, 3, 4, 2, 1 (One by one popped from stack).

TIME COMPLEXITY - O(v+e)
Space Complexity - O(v)

*/
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> Graph[],int visited[],int start, stack<int> &st){
    visited[start]=1;
    for(auto itr=Graph[start].begin() ; itr!=Graph[start].end() ;itr++){
        if(!visited[*itr])
        dfs(Graph,visited,*itr,st);
    }
    st.push(start);
}

void transDfs(vector<int> TransGraph[],int visited[], int start, vector<int> components[],int &CompNum){
  visited[start]=1;
  components[CompNum].push_back(start);
  for(auto itr=TransGraph[start].begin() ;itr!=TransGraph[start].end()  ;itr++){
      if(!visited[*itr]){
          transDfs(TransGraph,visited,*itr,components,CompNum);
      }
  }
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<int> Graph[v];
    vector<int> TransGraph[v];
    for(int i=0 ; i<e ;i++){
        int x,y;
        cin>>x>>y;
        Graph[x].push_back(y);
        TransGraph[y].push_back(x);
    }

    stack<int> st; //Used for storing the nodes whose all adjacents vertices were visited
    int visited[v]={0};
    for(int i=0 ; i<v; i++){
        if(!visited[i])
        dfs(Graph,visited,i,st);
    }

    for(int i=0 ; i<v; i++){
        visited[i]=0;
    }
    vector<int> Components[v];  //At max v components can be formed
    int CompNum=1; //No of components;

    cout<<endl;

    while(!st.empty()){
        int start=st.top();
        st.pop();
        if(visited[start]==0){
            transDfs(TransGraph,visited,start,Components,CompNum);
            CompNum++;
        }
    }
    

    // Printing all the components
    for(int i=1; i <CompNum ;i++){
        cout<< i <<" Component -> ";
        for(auto itr=Components[i].begin() ;itr!=Components[i].end() ;itr++){
            cout<<*itr<<" ";
        }
        cout<<endl;
    }
}