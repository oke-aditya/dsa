// Implementing graph using adjacency matrix
// There are n nodes / vertices and m edges.
// Each index contains list of edges.
// It is represented as matrix.

// Graph to represent
//  1 --- 2 --- 4
//  | -   |   -
//  |   - |  -
//  5 --- 3

#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{

    // There are five vertices.
    int V, E; // Also denoted as n vertices and m edges.

    // Declare the adjacency matrix;
    // For each vertex we store the connections.
    // Both are adjacent to each other

    // There are 5 vertices and 7 edjges.
    // (5, 7) is input on first line.
    cin>>V>>E;

    // The adjacency matrix for all vertex.
    int adj[V+1][V+1];

    // Take edges as input.
    for(int i=0; i<E; i++)
    {
        // This denoted there is edge between vertex v1 and v2
        // (E.g. for above (1, 2))
        // (2, 3)
        int v1, v2;
        cin >> v1 >> v2;

        // Since both are adjacent to each other.
        adj[v1][v2] = 1;
        adj[v2][v1] = 1;

    }

    
    return 0;
}

