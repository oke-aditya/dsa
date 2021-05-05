// Shortest Path in Undirected Graph with Unit Weights

// https://www.geeksforgeeks.org/shortest-path-unweighted-graph/


// Given an unweighted graph, a source,
// and a destination, we need to find the shortest path
// from source to destination in the graph in the most optimal way.

// Since the graph is unweighted, we can solve this problem in O(V + E) time.
// The idea is to use a modified version of Breadth-first search 

// Algorithm: -
// This can be solved with modified bfs.
// We assume all distances to be infinity.
// Then in bfs traversal, we update each distance by smaller one.
// 

// Time Complexity: -
// O(V + E)

// Space Complexity: -
// O(V) + O(E)

#include<bits/stdc++.h>
using namespace std;

vector<int> shortest_path(int V, vector<int> adj[], int src)
{
    /// All distances from this node to other vertices.
    vector <int> dist(V, INT_MAX);

    // A queue to store vertices.
    queue <int> q;

    // Visit the first one.
    q.push(0);

    // Source node is at 0.
    dist[src] = 0;
    q.push(src);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto it: adj[node])
        {
            if(dist[node] + 1 < dist[it])
            {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }

    return dist;

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

    // Given source node compute the distance
    int src = 3;
    vector <int> res = shortest_path(V, adj, src);

    // Print out bfs
    for(auto r: res)
    {
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}



