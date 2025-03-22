// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

// Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]],
// src = 0, destination = 3, k = 1 Output: 700

// Solution:
// Trick here is to do a BFS on number of stops
// We would then not need priority queue and optimization
// simple bfs on number of stops will help
// on each bfs traversal, stop increases by 1.

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src,
                        int destination, int k) {
    // we need to make an adjacency list with weights
    // adj takes a pair ({adj, weight})
    vector<pair<int, int>> adj[n];

    for (int i = 0; i < flights.size(); i++) {
      adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
    }

    // {stops, {node, dist}}
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});

    vector<int> distance(n, INT_MAX);
    distance[src] = 0;

    // do a simple bfs on stops
    while (!q.empty()) {
      pair<int, pair<int, int>> pp = q.front();
      int stops = pp.first;
      int node = pp.second.first;
      int dist = pp.second.second;
      q.pop();

      if (stops > k) {
        continue;
      }

      for (auto neigh : adj[node]) {
        int adj_node = neigh.first;
        int edge = neigh.second;

        if (dist + edge < distance[adj_node] && stops < k) {
          distance[adj_node] = dist + edge;
          q.push({stops + 1, {adj_node, dist + edge}});
        }
      }
    }
    if (distance[destination] == INT_MAX) {
      return -1;
    }
    return distance[destination];
  }
};
