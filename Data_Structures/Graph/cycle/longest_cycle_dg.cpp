// https://leetcode.com/problems/longest-cycle-in-a-graph/description/

// You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.
// The graph is represented with a given 0-indexed array edges of size n, 
// indicating that there is a directed edge from node i to node edges[i].
// If there is no outgoing edge from node i, then edges[i] == -1.
// Return the length of the longest cycle in the graph. If no cycle exists, return -1.
// A cycle is a path that starts and ends at the same node.

// Input: edges = [3,3,4,2,3]
// Output: 3
// Explanation: The longest cycle in the graph is the cycle: 2 -> 4 -> 3 -> 2.
// The length of this cycle is 3, so 3 is returned.

// Input: edges = [2,-1,3,1]
// Output: -1
// Explanation: There are no cycles in this graph.

// Solution
// 
// See the diagram, we do cycle detection, but we add number to the nieghbours
// Numbers will help us track length of cycle.
// Length of cycle = end - start + 1
// We will do dfs itself to detect the cycle.
// just a trick in how we maintain the current visited nodes
// 




#include<bits/stdc++.h>
using namespace std;

class Solution
{
    int max_len = -1;

    public:

        void dfs(int source, int cycle_len, vector<int>& edges, vector<int> &visited, vector<int> &current_path)
        {
            cycle_len += 1;
            current_path[source] = cycle_len;
            visited[source] = 1;

            int neigh = edges[source];
            if(neigh != -1)
            {
                if(!visited[neigh])
                {
                    dfs(neigh, cycle_len, edges, visited, current_path);
                }

                // we have a cycle
                else if(current_path[neigh] > 0)
                {
                    int path_len = current_path[source] - current_path[neigh] + 1;
                    max_len = max(max_len, path_len);
                }
            }
            
            // reset step in backtrack
            current_path[source] = 0;
        }
        int longestCycle(vector<int>& edges) 
        {
            int n = edges.size();
            vector<int> visited(n, 0), current_path(n, 0);

            for(int i=0; i<n-1; i++)
            {
                if(!visited[i])
                {
                    dfs(i, 0, edges, visited, current_path);
                }

            }
            return max_len;       
        }
};

