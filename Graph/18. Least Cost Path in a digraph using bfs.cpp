/*
Name : Aman Jain
Date : 26-06-2020

Consider a directed graph where weight of its edges can be one of x,2x or 3x(x is a given integer),
Compute the least cost path from source to destination efficiently.


The idea is to modify the input graph in such a way
that all its edges have same weight. For edges
having weight 3x, we split them into three edges of
weight x each. Similarly, edges having weight 2x
gets split into two edges of weight x each. Nothing
needs to be done for edges already having weight
x. Special care has to be taken while introducing
new edges in the graph such that we should not
introduce new routes into the graph. So in order to
split an edge of weight 3x, we need to create two
new vertices in the graph instead of using existing
vertices. Similarly, in order to split edge having
weight 2x, we need to create one new vertex. Lets
illustrate this with the help of a diagram.
Split edge (v, u) having weight 3x into three edges
(v, v+N), (v+N, v+2N) and (v+2N, u) each
having weight x.




*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// data structure to store graph edges
struct Edge {
	int source, dest, weight;
};

// class to represent a graph object
class Graph
{
public:
	// construct a vector of vectors to represent an adjacency list
	vector<vector<int>> adjList;

	// Graph Constructor
	Graph(vector<Edge> const &edges, int x, int N)
	{
		// resize the vector to 3*N elements of type vector<int>
		adjList.resize(3*N);

		// add edges to the undirected graph
		for (auto &edge: edges)
		{
			int v = edge.source;
			int u = edge.dest;
			int weight = edge.weight;

			// create two new vertices v+N and v+2*N if the weight
			// of edge is 3x. Also, split the edge (v, u) into (v, v+N),
			// (v+N, v+2N) and (v+2N, u) each having weight x
			if (weight == 3*x)
			{
				adjList[v].push_back(v + N);
				adjList[v + N].push_back(v + 2 * N);
				adjList[v + 2 * N].push_back(u);
			}

			// create one new vertex v+N if the weight of the edge
			// is 2x. Also split the edge (v, u) into (v, v+N),
			// (v+N, u) each having weight x
			else if (weight == 2*x)
			{
				adjList[v].push_back(v + N);
				adjList[v + N].push_back(u);
			}

			// no splitting is needed if edge weight is 1x
			else
				adjList[v].push_back(u);
		}
	}
};

// Recursive function to print path of given vertex v from
// the source vertex
void printPath(vector<int> const &predecessor, int v, int& cost, int N)
{
	if (v < 0)
		return;

	printPath(predecessor, predecessor[v], cost, N);
	cost++;

	// consider only original nodes present in the graph
	if (v < N)
		cout << v << " ";
}

// Perform BFS on graph starting from vertex source
void BFS(Graph const& graph, int source, int dest, int N)
{
	// stores vertex is discovered in BFS traversal or not
	vector<bool> discovered(3*N, false);

	// mark source vertex as discovered
	discovered[source] = true;

	// predecessor[] stores predecessor information. It is used
	// to trace least cost path from destination back to source.
	vector<int> predecessor(3*N, -1);

	// create a queue used to do BFS and push source vertex
	// into the queue
	queue<int> q;
	q.push(source);

	// run till queue is not empty
	while (!q.empty())
	{
		// pop front node from queue and print it
		int curr = q.front();
		q.pop();

		// if destination vertex is reached
		if (curr == dest)
		{
			int cost = -1;
			cout << "Least cost path between " << source << " and " <<
				dest << " is "; printPath(predecessor, dest, cost, N);
			cout << "having cost " << cost;
		}

		// do for every adjacent edge of current vertex
		for (int v : graph.adjList[curr])
		{
			if (!discovered[v])
			{
				// mark it discovered and push it into queue
				discovered[v] = true;
				q.push(v);

				// set curr as predecessor of vertex v
				predecessor[v] = curr;
			}
		}
	}
}

// Least cost path in weighted digraph using BFS
int main()
{
	int x = 1;

	// vector of graph edges as per above diagram
	vector<Edge> edges =
	{
		{0, 1, 3*x}, {0, 4, 1*x}, {1, 2, 1*x}, {1, 3, 3*x},
		{1, 4, 1*x}, {4, 2, 2*x}, {4, 3, 1*x}
	};

	// Number of nodes in the graph
	int N = 5;

	// create a graph from edges
	Graph graph(edges, x, N);

	// given source and destination vertex
	int source = 0, dest = 2;

	// Do BFS traversal from given source
	BFS(graph, source, dest, 5);

	return 0;
}