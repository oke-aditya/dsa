// Topological Sorting.

// Topological sorting for Directed Acyclic Graph (DAG) is a
// linear ordering of vertices such that for every directed edge u v, vertex
// u comes before v in the ordering. Topological Sorting
// for a graph is not possible if the graph is not a DAG.

// There can be more than one topological sorting for a graph.

// The first vertex in topological sorting is
// always a vertex with in-degree as 0 (a vertex with no incoming edges).


// https://www.geeksforgeeks.org/topological-sorting/

// Time Complexity: O(V+E). 

// Auxiliary space: O(V). 


// Given a Directed Graph with V vertices and E edges, Find any Topological Sorting of that Graph.

// Algorithm (Kahn's Algorithm) : -
// Calculate in degree of all the nodes.
// First element of toposort always has in degree of 0.
// Add element whose in degree is 0 to the queue.
// Visit all neighbors of this node using BFS.
// Decrease the in degree of them by 1.
// If indegree is 0 add them to queue.
// Store result as nodes appear.


#include<bits/stdc++.h>
using namespace std;

vector <int> topo_sort(int V, vector<int> adj[])
{
    // Queue for bfs
    queue<int> q;
    
    // Store in degrees of all the nodes.
    vector<int> in_degree(V, 0);
    
    for(int i=0; i<V; i++)
    {
        for(auto it: adj[i])
        {
            in_degree[it] += 1;
        }
    }

    // Find the one with 0 in degree
    for(int i=0; i<V; i++)
    {
        if(in_degree[i] == 0)
        {
            q.push(i);
        }

    }

    // Perform bfs
    vector<int> res;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        res.push_back(node);

        for(auto it: adj[node])
        {
            in_degree[it] -= 1;

            if(in_degree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    return res;

}

int main(int argc, char const *argv[])
{
    // Number of vertices and Edges.
    int V, E;
    cin >> V >> E;
    vector<int> adj[V+1];
    // Adjacenct list for all the vertices.

    // Process each edge to build the graph.
    for (int i = 0; i < E; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);

        // If directed graph this is not true.
        adj[v2].push_back(v1);
    }

    // Peform bfs for the given graph with adjacenc list and number of vertices.
    vector <int> res = topo_sort(V, adj);
    return 0;

}
