// https://leetcode.com/problems/course-schedule/description/

// There are a total of numCourses courses you have to take, labeled from 0 to
// numCourses - 1. You are given an array prerequisites where prerequisites[i] =
// [ai, bi] indicates that you must take course bi first if you want to take
// course ai. For example, the pair [0, 1], indicates that to take course 0 you
// have to first take course 1. Return true if you can finish all courses.
// Otherwise, return false.

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take.
// To take course 1 you should have finished course 0. So it is possible.

// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take.
// To take course 1 you should have finished course 0, and to take course 0 you
// should also have finished course 1. So it is impossible.

// Solution

// We need to make a DAG
// Based on the dag, we can check if we have a cycle or not
// Checking cyle in dag can be done either via BFS (kahn's) or dfs
// We can use the idea of topological sort here, it will benefit in further
// questions
//
//

#include <bits/stdc++.h>
using namespace std;
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
  // n = 2
  int n = numCourses;

  // construct an adjacency list
  vector<vector<int>> adj(n);

  // also maintain the indegrees
  vector<int> indegree(n, 0);

  int m = prerequisites.size();

  for (int i = 0; i < m; i++) {
    vector<int> node_pair = prerequisites[i];
    int source = node_pair[0];
    int dest = node_pair[1];
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

  // the trick, if we have traversed fully, then topological sort is indeed size
  // of number of nodes
  return topo.size() == n;
  // return true;
}
