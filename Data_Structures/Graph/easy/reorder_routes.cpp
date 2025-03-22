// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

// There are n cities numbered from 0 to n - 1 and n - 1 roads such that there
// is only one way to travel between two different cities (this network form a
// tree). Last year, The ministry of transport decided to orient the roads in
// one direction because they are too narrow. Roads are represented by
// connections where connections[i] = [ai, bi] represents a road from city ai to
// city bi. This year, there will be a big event in the capital (city 0), and
// many people want to travel to this city. Your task consists of reorienting
// some roads such that each city can visit the city 0. Return the minimum
// number of edges changed. It's guaranteed that each city can reach city 0
// after reorder.

// Solution:
// We need to keep track of direction of edges a bit.
// Treat the graph as undirected.
// Start a dfs from the root, if you come across an edge in the forward
// direction, you need to reverse the edge. How do we track this out? Take -ve
// sign for directions that are pointing towards. Count of direction pointing
// outside is niegh > 0 Trace this on notebook
//
//

#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &adj, vector<vector<int>> &connections,
        vector<int> &visited, int source) {
  int count = 0;
  visited[source] = 1;

  for (int neigh : adj[source]) {
    if (!visited[abs(neigh)]) {
      cout << neigh << " " << endl;
      count += dfs(adj, connections, visited, abs(neigh)) + (neigh > 0);
    }
  }
  return count;
}

int minReorder(int n, vector<vector<int>> &connections) {
  // create an undirected graph from these connections
  vector<vector<int>> adj(n);

  for (auto con : connections) {
    int s = con[0];
    int d = con[1];

    adj[s].push_back(d);
    adj[d].push_back(-s);
  }

  // do a dfs and figure out which connections need to be reversed
  vector<int> visited(n);
  // print_vv(adj);
  int source = 0;
  return dfs(adj, connections, visited, source);
}
