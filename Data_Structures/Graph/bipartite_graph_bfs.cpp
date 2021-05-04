// A bipartite graph is a graph that can be colored with 2 colors
// 
// Write a Program to check if a graph is bipartite. 
// 
// A simple definition to bipartitie graph.
// Bipartite graph is a graph that does not have a even length cycle.
// If it has a even length cycle then the graph is not bipartite.
// 
// E.g.
// 
// (0)   (1)-- 3 -- 4 (1)
// 1 ---- 2         | 
//          -- 8 -- 5 -- 6 -- 7
//            (0)  (1)  (0)  (1)
// 
// This is not a bipartite graph

// Algorithm: -
// Starts from one node, and do bfs.
// The first node as color 1 (or 0)
// For each node mark the color as opposite to parent.
// if we find a node that has same color as parent.
// Then adjacent nodes have same color so it is not bipartite.

// Time Complexity: -
// O(V + E)

// Space Complexity: -
// O(V + E) + O(V) + O(E)

#include<bits/stdc++.h>
using namespace std;

// If we are given an adjacency matrix we can do the following

bool bipartite_adj(vector<vector<int>> graph)
{
    int n = graph.size();
    
    // set initial color to 0
    vector<int> colors(n, 0);

    queue <int> q;

    for(int i=0; i<n; i++)
    {
        if(colors[i])
        {
            continue;
        }

        // Initial color
        colors[i] = 1;
        q.push(i);

        while(!q.empty())
        {
            int node = q.front();
            for(auto neighbor : graph[node])
            {
                if(!colors[neighbor])
                {
                    colors[neighbor] = -colors[node];
                    q.push(neighbor);
                }

                // if the neighbor has same color
                else if(colors[neighbor] == colors[node])
                {
                    return false;
                }
            }
        }

    }
    return true;
}

bool bipartite_bfs(int src, vector<int> adj[], int color[])
{
    queue <int> q;
    q.push(src);

    // The first node is colored as by color1;
    color[src] = 1;

    while (!q.empty())
    {
        // get the node for bfs
        int node = q.front();
        q.pop();

        for(auto it: adj[node])
        {
            // If uncolored.
            if(color[it] == -1)
            {
                // Flip the color from previous node.
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if(color[it] == color[node])
            {
                // colors are same, so it's not bipartite
                return false;
            }
        }
    }
    return true;
}


bool is_bipartite(int V, vector<int> adj[])
{
    int color[V];
    // All of them are not colored.
    memset(color, -1, sizeof(color));

    for(int i=0; i<V; i++)
    {
        // Not colored
        if(color[i] == -1)
        {
            if(!bipartite_bfs(i, adj, color))
            {
                // Not a bipartite graph.
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