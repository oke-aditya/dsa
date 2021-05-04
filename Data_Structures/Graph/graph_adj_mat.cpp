// Implementing graph using adjacency matrix
// There are n nodes / vertices and m edges.
// Each index contains list of edges.
// It is represented as matrix.

// Graph to represent
//  1 --- 2 --- 4
//  | -   |   -
//  |   - |  -
//  7 --- 6

// Input for this graph
// 5 7  (5 vertices and 7 edges)
// 1 2  (edge between 1 and 2)
// 1 5
// 5 3
// 2 3
// 1 3
// 3 4
// 2 4


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
    int adj[V+1][V+1] = {0};

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

    // Print the adjacency matrix of graph
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    return 0;
}

