// Detect cycle in a directed graph
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

// Given a Directed Graph with V vertices (Numbered from 0 to V-1)
// and E edges, check whether it contains any cycle or not.

// Algorithm using DFS: -

// Keep two arrays, one for visited nodes and for dfs visited
// dfs visited checks if the current node was visited
// during the current run of dfs
// For every node check if it is not visited.
// Visit the node and check for cycle.
// If the node is visited in current dfs visit
// Or the node has cycle return true.
// Unmark the node as it was visited by dfs.
// 


// Time Complexity: O(V + E)

#include<bits/stdc++.h>
using namespace std;

bool check_cycle(int node, vector<int> adj[], int vis[], int dfs_vis[])
{
    vis[node] = 1;
    dfs_vis[node] = 1;

    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            if(check_cycle(it, adj, vis, dfs_vis))
            {
                return true;
            }
        }
        else if(dfs_vis[it])
        {
            return true;
        }
    
    }

    // Unmark which is visited.
    dfs_vis[node] = 0;
    return false;

}


bool cycle_detect_directed(int V, vector<int> adj[])
{
    int vis[V], dfs_vis[V];
    memset(vis, 0, sizeof(vis));
    memset(dfs_vis, 0, sizeof(dfs_vis));

    for(int i=0; i<V; i++)
    {
        if(!vis[i])
        {
            if(check_cycle(i, adj, vis, dfs_vis))
            {
                return true;
            }
        }
    }
    return false;
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
