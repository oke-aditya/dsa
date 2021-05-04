// Implementing graph using adjacency list
// This is the representation used in solving problems
// There are n nodes / vertices and m edges.
// Each index contains list of edges.
// The weights of edges can be represented as lists of pairs

// Graph to represent
//  1 --- 2 --- 4
//  | -   |   -
//  |   - |  -
//  5 --- 3

// Input for this graph
// 5 7  (5 vertices and 7 edges)
// 1 2  (edge between 1 and 2)
// 1 5
// 5 3
// 2 3
// 1 3
// 3 4
// 2 4

#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{

    // There are five vertices.
    int V, E; // Also denoted as n vertices and m edges.

    // There are 5 vertices and 7 edjges.
    // (5, 7) is input on first line.
    cin>>V>>E;

    // Declare the adjacency list;
    // For each vertex we store the connections.
    vector<int> adj[V+1];

    // Process every edge
    for(int i=0; i<E; i++)
    {
        // This denoted there is edge between vertex v1 and v2
        // (E.g. for above (1, 2))
        // (2, 3)
        int v1, v2;
        cin >> v1 >> v2;

        // For each vertex store who is adjacent.
        adj[v1].push_back(v2);

        // If the graph is directed this may not be true.
        adj[v2].push_back(v1);

        // If the graph has weights, we will have vector of pairs and push weight too.
    }

    // Print the adjacency list
    for(auto it: adj)
    {
        for(auto x: it)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}


