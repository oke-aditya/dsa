// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
// https://www.geeksforgeeks.org/problem
// s/implementing-dijkstra-set-1-adjacency-matrix/1

// Given a weighted, undirected and connected graph where you have given
// adjacency list adj. You have to find the shortest distance of all the
// vertices from the source vertex src, and return a list of integers denoting
// the shortest distance between each node and source vertex src. first is the
// node second is the weight

// most classic Algorithm to find out shortest distance from single source
// it outputs shortest paths required for all destination points
// basic idea is to compute a vector of minimum distance
// initialize it to inf.
// now use a priority queue to keep track of the edge distances
// if edge distance is less then the computed one (inf initially)
// update the distance
// Dijisktra is used when we have weighted graph, it could be directed /
// undirected. adjacency list contains each node with pair, denoting weight and
// adjacent neighbor

#include <bits/stdc++.h>
using namespace std;

// Input: adj = [[[1, 1], [2, 6]], [[2, 3], [0, 1]], [[1, 3], [0, 6]]], src = 2
// Output: [4, 3, 0]

// For nodes 2 to 0, we can follow the path 2-1-0.
// This has a distance of 1+3 = 4, whereas the path 2-0 has a distance of 6. So,
// the Shortest path from 2 to 0 is 4. The shortest distance from 0 to 1 is 1 .

class Solution {
 public:
  // Function to find the shortest distance of all the vertices
  // from the source vertex src.
  vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
    int n = adj.size();
    vector<int> visited(n, 0);
    vector<int> distance(n, INT_MAX);

    // simple min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        q;

    // we should push source to pq
    // mark distance as 0
    // remember min heap has {distance, source} combo, wheras adj has reverse
    q.push({0, src});
    distance[src] = 0;

    while (!q.empty()) {
      int ln = q.size();

      while (ln--) {
        pair<int, int> p = q.top();
        // distance is first
        // node is the second
        int d = p.first;
        int node = p.second;
        q.pop();

        // If this node has been visited, skip processing
        if (visited[node]) continue;

        // Mark this node as visited
        visited[node] = 1;

        // Explore the neighbors
        for (auto neigh : adj[node]) {
          // remember adj list has reverse notation of q
          int neigh_node = neigh.first;
          int edge_weight = neigh.second;

          // Relax the edge
          if (distance[neigh_node] > distance[node] + edge_weight) {
            distance[neigh_node] = distance[node] + edge_weight;
            q.push({distance[neigh_node], neigh_node});
          }
        }
      }
    }

    return distance;
  }
};
