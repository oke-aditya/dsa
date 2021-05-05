// Shortest Path in Directed Acyclic Graph

// Given a Weighted Directed Acyclic Graph and a source vertex in the graph,
// find the shortest paths from given source to all other vertices.

// Algorithm

// First find out the topological sorting of the graph.
// Assign all the distances as infinity.
// Use the topological sorting to find distance.
// Update the distance if the weight of node + distance is greater.

#include<bits/stdc++.h>
using namespace std;

void find_topo_sort(int node, int vis[], stack<int> &stk, vector<pair<int, int>> adj[])
{
    // This is dfs way of finding topo sort.
    // Mark node as visited.
    vis[node] = 1;

    for(auto it: adj[node])
    {
        if(!vis[it.first])
        {
            find_topo_sort(it.first, vis, stk, adj);
        }
    }
    stk.push(node);
}


vector<int> shortest_path(int src, int V, vector<pair<int, int>> adj[])
{
    // adj[i].first = vertex.
    // adj[i].second = weight.

    // Mark all the nodes as unvisited.

    int vis[V] = {0};
    // To store toposort (in reverse)
    stack <int> stk;

    for(int i=0; i<V; i++)
    {
        if(!vis[i])
        {
            find_topo_sort(i, vis, stk, adj);
        }
    }

    vector<int> dist(V, INT_MAX);

    // Source is at 0 distance
    dist[src] = 0;


    // While stack is not empty.
    while(!stk.empty())
    {
        // Get the node.
        int node = stk.top();
        stk.pop();

        // Compute the distance for not visited nodes.
        if(dist[node] != INT_MAX)
        {
            for(auto it: adj[node])
            {
                // If distance + weight is less, update it
                if(dist[node] + it.second < dist[it.first])
                {
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }

    return dist;

}


int main(int argc, char const *argv[])
{
    int V, E;
    cin>>V>>E;

    // For weighted graph we need pair.
    vector<pair<int, int>> adj[V];

    for(int i=0; i<E; i++)
    {
        int v1, v2, wt;
        cin>>v1>>v2>>wt;

        // Push only one since it's Directed.
        adj[v1].push_back({v2, wt});
    }

    // Res contains shortest paths to all vertices.
    vector<int> res = shortest_path(0, V, adj);

    return 0;
}


