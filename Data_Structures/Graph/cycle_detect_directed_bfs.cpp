// Detect cycle in a directed graph
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

// Given a Directed Graph with V vertices (Numbered from 0 to V-1)
// and E edges, check whether it contains any cycle or not.

// Algorithm using BFS: -
// Using same kahn's algorithm.
// If there is no topological sorting, 
// then there is no cycle.

// Calculate in degree of all the nodes.
// First element of toposort always has in degree of 0.
// Add element whose in degree is 0 to the queue.
// Visit all neighbors of this node using BFS.
// Decrease the in degree of them by 1.
// If indegree is 0 add them to queue.
// Store result as nodes appear.


#include<bits/stdc++.h>
using namespace std;

bool cycle_detect_directed(int V, vector<int> adj[])
{
    queue <int> q;
    vector<int> in_degree(V, 0);

    // Calcualte in degrees of graph.

    for(int i=0; i<V; i++)
    {
        for(auto it: adj[i])
        {
            in_degree[it] += 1;
        }
    }

    // Add node with 0 in degree.
    // This is start of topological sort.

    for(int i=0; i<V; i++)
    {
        if(in_degree[i] == 0)
        {
            q.push(i);
        }
    }

    // Keep a count to count length of topo sort.
    int count = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        count += 1;

        for(auto it: adj[node])
        {
            in_degree[it] -= 1;
            if(in_degree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    // Topo sort exists.
    if(count == V)
    {
        return false;
    }
    
    return true;

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
        // adj[v2].push_back(v1);
    }

    // Peform bfs for the given graph with adjacenc list and number of vertices.
    auto res = cycle_detect_directed(V, adj);

    if(res)
    {
        cout<<"yes";
    }
    else
    {
        cout<<"no";
    }
    return 0;
}


