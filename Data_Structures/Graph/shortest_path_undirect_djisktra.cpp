// Shortest Path in Undirected Graphs

// Given a graph and a source vertex in graph,
// find shortest paths from source to all vertices in the given graph.

// Algorithm (Djisktra Algorithm): -
// 
// 
// 
// 


#include<bits/stdc++.h>
using namespace std;

vector <int> shortest_path(int V, int src, vector<pair<int, int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> distances(V+1, INT_MAX);

    // Source has 0 distance.
    distances[src] = 0;

    // source has 0 distance.
    pq.push({0, src});

    while(!pq.empty())
    {
        int dist = pq.top().first;
        int prev = pq.top().second;

        pq.pop();

        // vector<pair<int, int>> :: iterator it;

        for(auto it = adj[prev].begin(); it != adj[prev].end(); it++)
        {
            int next = it->first;
            int next_dist = it->second;

            if(distances[next] > distances[prev] + next_dist)
            {
                distances[next] = distances[prev] + next_dist;
                pq.push({distances[next], next});
            }
        }
    }
    return distances;
}

int main(int argc, char const *argv[])
{
    // Number of vertices and Edges.
    int V, E;
    cin >> V >> E;
    vector<pair<int, int>> adj[V+1];
    // Adjacenct list for all the vertices.

    // Process each edge to build the graph.
    for (int i = 0; i < E; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        adj[v1].push_back({v2, wt});

        // If directed graph this is not true.
        adj[v2].push_back({v2, wt});
    }

    int src;

    cin >> src;

    auto res = shortest_path(V, src, adj);

    return 0;
}


