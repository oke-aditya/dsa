// Detect Cycle in Graph using DFS
// Use breadth first search to detect cycle in graph

// 2 -- 5 -- 6 
//      |    |
//      8 -- 7

// Algorithm: -
// Start traversing from dfs, we will visit
// 2 - 5 - 6 - 7 - 8 
// Now 8 will try to visit back to 5.
// This will result in loop.
// 

// Implementation
// Perform dfs while keeping track of parent.
// Also keep track of visited nodes.
// If dfs reaches a node which is alredy visited, then there is cycle.
// 

// Time Complexity: -
// O(V + E)

// Space complexity: -
// O(V + E) + O(V) + O(E)

#include<bits/stdc++.h>

using namespace std;

bool check_for_cycle_dfs(int node, int parent, vector <int> &vis, vector<int> adj[])
{
    // Visit this node.
    vis[node] = 1;

    // For every node
    for(auto it: adj[node])
    {
        // If it is not visited.
        // Visit it.
        if(!vis[it])
        {
            // This means internally there is a cycle.
            // As a loop is completed.
            if(check_for_cycle_dfs(it, node, vis, adj))
            {
                return true;
            }
        }

        // Othwerwise the parent is cycle.
        else if(it != parent)
        {
            return true;
        }
    }
    return false;
}

bool is_cycle(int V, vector<int> adj[])
{
    // Array to store visited elements.
    vector <int> vis(V+1, 0);
    for(int i=0; i<V; i++)
    {
        // If it is not visited, check for cycle.
        if(!vis[i])
        {
            // The first node has no parent.
            if(check_for_cycle_dfs(i, -1, vis, adj))
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
    vector<int> adj[V + 1];
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
    bool ans = is_cycle(V, adj);
    if (ans)
    {
        cout << "1" << endl;
    }
    else
    {
        cout << "0" << endl;
    }

    return 0;
}

