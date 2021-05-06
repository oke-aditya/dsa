// Minimum Spanning Tree
// 
// 
// Tree constructed from graph G, which has minimum weights
// Also it spans the entire Graph G. It has n nodes and n -1 
// edges.

// Given a weighted, undirected and connected graph of V
// vertices and E edges. The task is to find the sum
// of weights of the edges of the Minimum Spanning Tree.


// Prim's Algorithm
// Greedy algorithm
// Pick's minimum edges one after the other.
// 
// Implementation: -
// 
// Keep three arrays
// key array: srote weight of graph
// mst array: boolean array denoting which element
//            is included as MST
// parent array: track the parent node.
// 
// 

#include<bits/stdc++.h>
using namespace std;

vector<int> find_mst(int V, vector<pair<int, int>> adj[])
{
    // Declare three arrays parent, mst and key
    vector<int> parent(V), key(V, INT_MAX);
    vector<bool> mst_set(V, false);

    // Min heap styled priority queue. Stores key and vertex.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Key stores weights of graphs.
    key[0] = 0;
    // Starting node has no parent.
    parent[0] = 0;
    
    // Priority queue contains parent and key.
    pq.push({0, 0});

    // MST contains V - 1 edges, so.
    for(int count = 0; count < V - 1; count++)
    {
        // get the node.
        int u = pq.top().second;
        pq.pop();

        // this is part of mst now.
        mst_set[u] = true;

        // Explore it neighbors
        for(auto it: adj[u])
        {
            // adjacent vertex.
            int v = it.first;
            
            // weight of that vertex.
            int wt = it.second;

            // if it is not part of MST and weight is lower
            if(mst_set[v] = false && wt < key[v])
            {
                // It's parent and key are assigned.
                parent[v] = u;
                key[v] = wt;
                // Add this to min heap with wt and vertex.
                pq.push({key[v], v});
            }
        }
    }
    return parent;

}


int main(int argc, char const *argv[])
{
    int V, E;
    vector<pair<int, int>> adj[V];

    for(int i=0; i<E; i++)
    {
        int v1, v2, wt;
        cin>>v1>>v2>>wt;
        adj[v1].push_back({v1, wt});
        adj[v2].push_back({v2, wt});
    }

    auto res = find_mst(V, adj);
    
    return 0;
}


