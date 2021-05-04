// Detect Cycle in Graph using BFS
// Use breadth first search to detect cycle in graph

// 3 -- 5 -- 6 -- 7
//      |         |
//      10 - 9 -- 8  -- 11

// Algorithm: -
// We keep track of parent node which started the BFS
// The place where cycle occurs (here 8) will have it's parent node
// already traversed. And hence it is a cycle.
// When 8 will try to traverse to adjacent nodes, it will find that
// the parent 7 is already traversed, this will help to detect cycle.

// Implementation
// Keep a queue with pair of integers. Queue will hold node and it's parent.
// Keep an array for viisted nodes.
// Traverse each node like bfs and find parents.
// push back parent and node in the queue.
//
//
//
//

// Time Complexity: -
// O(V + E)

// Space complexity: -
// O(V + E) + O(V) + O(E)

#include <bits/stdc++.h>
using namespace std;

bool check_for_cycle(int s, int V, vector<int> adj[], vector<int> &visited)
{
    vector<int> parent(V, -1);

    // Create a queue for BFS
    queue<pair<int, int>> q;

    visited[s] = 1;
    q.push({s, -1});

    while (!q.empty())
    {

        int node = q.front().first;
        int par = q.front().second;
        q.pop();

        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                q.push({it, node});
            }
            else if (par != it)
            {
                return true;
            }
        }
    }
    return false;
}

bool is_cycle(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (check_for_cycle(i, V, adj, vis))
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
