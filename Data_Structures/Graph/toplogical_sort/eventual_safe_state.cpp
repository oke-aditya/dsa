// https://leetcode.com/problems/find-eventual-safe-states/description/
// finding eventual safe state for the graph

// There is a directed graph of n nodes with each node labeled from 0 to n - 1.
// The graph is represented by a 0-indexed 2D integer array graph where graph[i]
// is an integer array of nodes adjacent to node i, meaning there is an edge
// from node i to each node in graph[i]. A node is a terminal node if there are
// no outgoing edges. A node is a safe node if every possible path starting from
// that node leads to a terminal node (or another safe node). Return an array
// containing all the safe nodes of the graph. The answer should be sorted in
// ascending order.

// Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
// Output: [2,4,5,6]
// Explanation: The given graph is shown above.
// Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either
// of them. Every path starting at nodes 2, 4, 5, and 6 all lead to either node
// 5 or 6.

// Solution:

// basically reverse the graph
// reverse the given edges.
// since we want out degree == 0.
// It's better to reverse the edges and apply topological sort with 0 indegrees
// doing bfs on outdegree would be tricky.
// anything on outdegree, reverse and convert to indegree

#include <bits/stdc++.h>
using namespace std;

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
  int n = graph.size();
  vector<int> in_degree(n), res;
  vector<vector<int>> adj(n);
  int i, j;

  for (i = 0; i < n; i++) {
    for (j = 0; j < graph[i].size(); j++) {
      // adj[i].push_back(graph[i][j]);
      adj[graph[i][j]].push_back(i);
      in_degree[i] += 1;
    }
  }

  // print_v(in_degree);
  queue<int> q;

  for (int i = 0; i < n; i++) {
    if (in_degree[i] == 0) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    // 0 in degree
    res.push_back(node);

    for (int neigh : adj[node]) {
      in_degree[neigh] -= 1;
      if (in_degree[neigh] == 0) {
        q.push(neigh);
      }
    }
  }

  sort(begin(res), end(res));
  return res;
}