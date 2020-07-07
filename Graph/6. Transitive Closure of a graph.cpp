/*
Author : AMAN JAIN
DATE: 06-07-2020

Program : Transitive Closure of a graph
Program link : https://practice.geeksforgeeks.org/problems/transitive-closure-of-a-graph/0

Solution for geeksforgeeks

Given a directed graph, find out if a vertex j is reachable from another vertex i for all vertex pairs (i, j) in the given graph. Here reachable mean that there is a path from vertex i to j. The reach-ability matrix is called transitive closure of a graph.



*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 100




void dfs ( int n , int start,int visited[],int graph [] [MAX])
{

    visited[start]=1;
    
    for(int i=0 ; i< n ; i++)
    {
        if(visited[i]==0 && graph[start][i]==1)
        {
            dfs(n,i,visited,graph);
        }
    }

}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    int graph[MAX][MAX];
	    
	    for(int i=0 ;i< n ;i++)
	    {
	        for(int j=0 ;j<n ;j++)
	        {
	            cin>>graph[i][j];
	        }
	    }
	    
	    int transClo[n][n];
	   
	     for(int i=0 ;i< n ;i++)
	    {
	        for(int j=0 ;j<n ;j++)
	        {
	            transClo[i][j]=0;
	        }
	    }
	    
	        int visited[n]={0};   
	    for(int i=0 ; i<n ;i++)
	    {
	        
	        dfs(n,i,visited,graph);
	        for(int j=0 ; j< n ;j++)
	        {
	            transClo[i][j]=visited[j];
	            visited[j]=0;
	            
	        }
	        
	    }	    
	     for(int i=0 ;i< n ;i++)
	    {
	        for(int j=0 ;j<n ;j++)
	        {
	            cout<<transClo[i][j]<<" ";
	        }
	    }	    
	    cout<<endl;	    	    
	}
	return 0;
}
