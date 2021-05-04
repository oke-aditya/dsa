// Depth first search traversal
// 
// DFS is more suitable when there are solutions away from source.



// Consider a graph

//  1 --- 2 --- 4
//        |     |
//        |     |
//        7 --- 6

// Input for the graph

// 5 7 (5 vertices 5 edges)
// 1 2
// 2 4
// 2 7
// 4 6
// 6 7


// DFS will first traverse
// 1 2 4 6 7

// Algorithm: -
// We need to return a vector cotaining how the graph was traversed.
// We keep a vector that denotes if each of the node was visited.
// DFS is recursively written, as we can simply call dfs again to explore.
// Mark nodes which are visited in a visited array.
// Call dfs for every not visited node.
// In dfs visit all the edges.

// Time Complexity: -
/// O(V + E) for adjacency list and O(V*V) for adjacency matrix.

// Space complexity
// O(V+E) + O(E) + O(V)


#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &is_visited, vector<int>adj[], vector<int> &res)
{
    // Push back the node visited.
    res.push_back(node);
    is_visited[node] = 1;

    for(auto it: adj[node])
    {
        // If the node is not visited, visit it
        if(!is_visited[it])
        {
            dfs(it, is_visited, adj, res);
        }
    }
}

vector <int> dfsofg(int V, vector <int> adj[])
{
    // Result of dfs
    vector <int> res;

    // Visited array.
    vector <int> is_visited(V+1, 0);

    // We start from node1
    for(int i=0; i<V; i++)
    {
        if(!is_visited[i])
        {
            // Perform dfs
            dfs(i, is_visited, adj, res);
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
    vector <int> res = dfsofg(V, adj);
    return 0;

}

