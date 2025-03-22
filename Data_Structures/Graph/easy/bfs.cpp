// Implement bfs on Graph
// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

// Given a undirected graph represented by an adjacency list adj, w
// hich is a vector of vectors where each adj[i] represents the list of vertices
// connected to vertex i. Perform a Breadth First Traversal (BFS) starting from
// vertex 0, visiting vertices from left to right according to the adjacency
// list, and return a list containing the BFS traversal of the graph.

// Note: Do traverse in the same order as they are in the adjacency list.
// Input: adj = [[2,3,1], [0], [0,4], [0], [2]]
// Output: [0, 2, 3, 1, 4]

#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(vector<vector<int>> &adj) {
  // number of nodes is all we care about visited.
  int n = adj.size();
  vector<int> visited(n);
  vector<int> res;

  queue<int> q;

  // source node is 0;
  int s = 0;
  q.push(s);
  visited[s] = 1;

  // same bfs logic as tree
  // except left / right we need to go over adj list
  // push if not viisted
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    res.push_back(curr);

    for (int x : adj[curr]) {
      if (!visited[x]) {
        q.push(x);
        visited[x] = 1;
      }
    }
  }

  return res;
}
