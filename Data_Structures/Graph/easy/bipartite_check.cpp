// https://leetcode.com/problems/is-graph-bipartite/

// There is an undirected graph with n nodes, where each node is numbered 
// between 0 and n - 1. You are given a 2D array graph, 
// where graph[u] is an array of nodes that node u is adjacent to. 
// More formally, for each v in graph[u], there is an undirected edge 
// between node u and node v. The graph has the following properties:

// There are no self-edges (graph[u] does not contain u).
// There are no parallel edges (graph[u] does not contain duplicate values).
// If v is in graph[u], then u is in graph[v] (the graph is undirected).
// The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.

// A graph is bipartite if the nodes can be partitioned into two 
// independent sets A and B such that every edge in the graph connects 
// a node in set A and a node in set B.

// Return true if and only if it is bipartite.

// Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
// Output: false
// Explanation: There is no way to partition the nodes into two 
// independent sets such that every edge connects a node in one and a 
// node in the other.


// Solution:
// Do A BFS traversal and start coloring the graph
// Use 3 colors, 0 for uncolored, 1 for Color A, -1 for color B
// push nodes to q
// check if neigh is uncolored, add to q and color to opposite of node
// if it is colored, then check if color is opposite


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        // 0: unocolored
        // 1: Color A
        // -1: Color B

        vector<int> color(n, 0);
        queue<int> q;

        for(int i=0; i<n; i++) {

            if(!color[i]) {
                color[i] = 1;
                q.push(i);
                while(!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for(int neigh: graph[node]) {
                        if(!color[neigh]) {
                            color[neigh] = -color[node];
                            q.push(neigh);
                        }
                        else if(color[neigh] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

