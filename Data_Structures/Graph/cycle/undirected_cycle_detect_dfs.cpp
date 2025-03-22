// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// Given an undirected graph with V vertices labelled from 0 to V-1 and E edges,
// check whether the graph contains any cycle or not.
// The Graph is represented as an adjacency list, where adj[i] contains all
// the vertices that are directly connected to vertex i.

#include <bits/stdc++.h>
using namespace std;

// The trick is same. Do a DFS, but keep track of parent node.
// If the parent is used to reach dfs node then it's not a cycle
// Otherwise it is a cycle. if parent != neigh
//
// You need to do this for all vertices!! This is reason for disconnected graph!
// We may have independent vertices.
//

bool dfs(vector<vector<int>> &adj, vector<int> &visited, int source,
         int parent) {
  visited[source] = 1;

  for (int neigh : adj[source]) {
    if (!visited[neigh]) {
      if (dfs(adj, visited, neigh, source)) return true;
    }

    // we have visited it
    else {
      // parent node is not neigh
      // there is one more connection
      if (parent != neigh) {
        return true;
      }
    }
  }
  return false;
}

// Function to detect cycle in an undirected graph.

bool isCycle(vector<vector<int>> &adj) {
  int n = adj.size();
  vector<int> visited(n);
  int source = 0;

  for (int i = 0; i < n; i++) {
    if (!visited[i] && dfs(adj, visited, i, -1)) {
      return true;
    }
  }

  return false;
}