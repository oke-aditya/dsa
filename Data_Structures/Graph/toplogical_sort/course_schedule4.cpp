// https://leetcode.com/problems/course-schedule-iv/description/?

// There are a total of numCourses courses you have to take, labeled from 0 to
// numCourses - 1. You are given an array prerequisites where prerequisites[i] =
// [ai, bi] indicates that you must take course ai first if you want to take
// course bi. For example, the pair [0, 1] indicates that you have to take
// course 0 before you can take course 1. Prerequisites can also be indirect. If
// course a is a prerequisite of course b, and course b is a prerequisite of
// course c, then course a is a prerequisite of course c. You are also given an
// array queries where queries[j] = [uj, vj]. For the jth query, you should
// answer whether course uj is a prerequisite of course vj or not. Return a
// boolean array answer, where answer[j] is the answer to the jth query.

// Input: numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
// Output: [false,true]

// Input: numCourses = 3, prerequisites = [[1,2],[1,0],[2,0]], queries =
// [[1,0],[1,2]] Output: [true,true]

// solution:
// Trick here is to maintain a map of node and it's dependencies
// Then we can answer the queries easily.
//

#include <bits/stdc++.h>
using namespace std;
vector<bool> checkIfPrerequisite(int numCourses,
                                 vector<vector<int>>& prerequisites,
                                 vector<vector<int>>& queries) {
  int n = numCourses;
  vector<vector<int>> adj(n);
  vector<bool> res;
  vector<int> indegree(n);

  // store topo sort in a map. Map contains the node and it's all possible
  // dependencies.
  unordered_map<int, unordered_set<int>> mp;

  // make graph
  for (int i = 0; i < prerequisites.size(); i++) {
    int source = prerequisites[i][0];
    int dest = prerequisites[i][1];
    adj[source].push_back(dest);
    indegree[dest] += 1;
  }

  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  // kahn's bfs
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (int neigh : adj[node]) {
      // for this neighboer
      mp[neigh].insert(node);
      // find all dependencies.
      for (auto neigh2 : mp[node]) {
        mp[neigh].insert(neigh2);
      }
      indegree[neigh] -= 1;
      if (indegree[neigh] == 0) {
        q.push(neigh);
      }
    }
  }

  // now answer the queries?
  for (int i = 0; i < queries.size(); i++) {
    int source = queries[i][0];
    int dest = queries[i][1];

    // int start_idx = mp[source];
    // int dest_idx = mp[dest];

    // count returns bool, if it does contain it will give true
    res.push_back(mp[dest].count(source));
  }

  return res;
}