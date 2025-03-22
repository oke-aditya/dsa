// https://leetcode.com/problems/course-schedule-ii/description/

// There are a total of numCourses courses you have to take, labeled from 0 to
// numCourses - 1. You are given an array prerequisites where prerequisites[i] =
// [ai, bi] indicates that you must take course bi first if you want to take
// course ai. For example, the pair [0, 1], indicates that to take course 0 you
// have to first take course 1. Return the ordering of courses you should take
// to finish all courses. If there are many valid answers, return any of them.
// If it is impossible to finish all courses, return an empty array.

// solution
// This is straightforward topological sort question
// We need to create the adjacency list and follow topo sort.

#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
  int n = numCourses;

  // construct an adjacency list
  vector<vector<int>> adj(n);

  // also maintain the indegrees
  vector<int> indegree(n, 0);

  int m = prerequisites.size();

  for (int i = 0; i < m; i++) {
    vector<int> node_pair = prerequisites[i];
    int source = node_pair[1];
    int dest = node_pair[0];
    adj[source].push_back(dest);
    indegree[dest] += 1;
  }

  // try to do topological traversal
  // if we end up doing graph traversal and not visit all the nodes
  // then there is a loop

  queue<int> q;
  vector<int> topo;

  for (int i = 0; i < n; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  // // topo iter
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    topo.push_back(node);
    for (int neigh : adj[node]) {
      // cout<<"neig"<<neigh<<endl;
      indegree[neigh] -= 1;
      if (indegree[neigh] == 0) {
        q.push(neigh);
      }
    }
  }

  // for(auto x: indegree)
  // {
  //     cout<<"indegree"<<x<<" ";
  // }

  // cout<<endl;

  // for(auto x: topo)
  // {
  //     cout<<"topo "<<x<<" ";
  // }

  // cout<<endl;

  // return the order
  if (topo.size() == n)
    return topo;
  else
    return vector<int>{};
}
