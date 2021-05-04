// A bipartite graph is a graph that can be colored with 2 colors
// 
// Write a Program to check if a graph is bipartite. 
// 
// A simple definition to bipartitie graph.
// Bipartite graph is a graph that does not have a even length cycle.
// If it has a even length cycle then the graph is not bipartite.
// 
// E.g.
// // (0)   (1)-- 3 -- 4 (1)
// 1 ---- 2         | 
//          -- 8 -- 5 -- 6 -- 7
//            (0)  (1)  (0)  (1)
// 
// This is not a bipartite graph

// Using DFS to solve this
// Algorithm: -
// Start DFS from first node
// Keep track of parent.
// Mark each visited node with color opposite to parent.
// In dfs if we find a parent having a node with opposite color
// Then the graph is not bipartite.


// Time Complexity: -
// O(V + E)

// Space Complexity: -
// O(V + E) + O(V) + O(E)

#include<bits/stdc++.h>
using namespace std;

bool bipartite_dfs(int node, vector<int> adj[], int color[])
{
    // If not colored, color it as 1
    if(color[node] == -1)
    {
        color[node] = 1;
    }

    for(auto it: adj[node])
    {
        if(color[it] == -1)
        {
            color[it] = 1 - color[node];
            if(!bipartite_dfs(it, adj, color))
            {
                return false;
            }
        }
        else if(color[it] == color[node])
        {
            return true;
        }
    }
    return true;
}


bool is_bipartite(int V, vector<int> adj[])
{
    int color[V];
    memset(color, -1, sizeof(color));

    for(int i=0; i<V; i++)
    {
        if(color[i] == -1)
        {
            if(!bipartite_dfs(i, adj, color))
            {
                return false;
            }
        }
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
        adj[v2].push_back(v1);
    }

    // Peform bfs for the given graph with adjacenc list and number of vertices.
    auto res = is_bipartite(V, adj);

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

