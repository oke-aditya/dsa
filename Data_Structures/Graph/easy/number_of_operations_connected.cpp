// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
// 

// Input: n = 4, connections = [[0,1],[0,2],[1,2]]
// Output: 1
// Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.

// Example 2:

// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
// Output: 2

// Example 3:

// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
// Output: -1
// Explanation: There are not enough cables.

// Solution:

// We need to construct adjacency list of this first
// Use DFS to count number of connected components
// If we have excess wires, then we need connected components - 1.

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    
        void dfs(vector<vector<int>> &adj, vector<int> &visited, int node)
        {
            visited[node] = 1;
            for(int neigh: adj[node])
            {
                if(!visited[neigh])
                {
                    dfs(adj, visited, neigh);
                }
            }
        }
    
        int makeConnected(int n, vector<vector<int>>& connections) 
        {
            // find number of edges
            // that's basically size of connections
            // find number of connected components
    
    
            // we need to have excess wires. 
            // for n edges we need just n-1 wires
    
            int wires = connections.size();
            if(wires < (n-1))       
            {
                // shortfall of wires
                return -1;
            } 
    
            int n_connected = 0;
    
            // create adjacency list from connections
            vector<vector<int>> adj(n);
    
            for(int i=0; i<connections.size(); i++)
            {
                int start = connections[i][0];
                int end = connections[i][1];
    
                adj[start].push_back(end);
                adj[end].push_back(start);
            }
    
    
            vector<int> visited(n);
    
    
            for(int i=0; i<n; i++)
            {
                if(!visited[i])
                {
                    // we just add n_connected, similar to islands
                    dfs(adj, visited, i);
                    n_connected += 1;
                }
            }
    
            // If we have more than one connected component, calculate how many edges are needed
            // To connect `n_connected` components, we need at least `n_connected - 1` edges.
            // So the excess wires will be the total number of wires minus the edges 
            // needed to connect all components.
            return n_connected - 1;
    
        }
};