// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
// The graph is represented as an adjacency list, where adj[i] contains a list of vertices that are directly reachable from vertex i. 
// Specifically, adj[i][j] represents an edge from vertex i to vertex j.

// Solution:

// The trick here is unlike undirected graph we cannot rely on checking parent and neighbor
// We need to actually keep track of the path and see if we have reached a loop
// Keep track of current path.
// If we revisit the current path, then we are in a cycle.
// Else we are not
// Keep track of current path via a vector.

// Don't forget to remove from current path once that path is explored
// We need to reset the current path.

#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &adj, int source, vector<int> &visited, vector<int> &current_path)
{
    visited[source] = 1;
    // Add to the current path
    current_path[source] = 1;

    for(int neigh: adj[source])
    {
        if(!visited[neigh])
        {
            if(dfs(adj, neigh, visited, current_path))
            {
                return true;
            }
        }
        else
        {
            // if neighbour is in the current path.
            // it is already visited
            if(current_path[neigh] == 1)
            {
                return true;
            }
        }
    }

    // don't forget this is the backtrack step.
    // we need to reset the current path.
    current_path[source] = 0;
    return false;
}


// Function to detect cycle in a directed graph.
bool isCyclic(vector<vector<int>> &adj) 
{
    int n = adj.size();

    // Note that current path can have max n vertices, as we can visit max all the nodes.
    vector<int> visited(n), current_path(n);

    // do for every vertex, remember the case of disconnected graphs
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            if(dfs(adj, i, visited, current_path))
            {
                return true;    
            }
        }
    }
    return false;
}

