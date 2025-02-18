// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, 
// check whether the graph contains any cycle or not. 
// The Graph is represented as an adjacency list, where adj[i] contains all 
// the vertices that are directly connected to vertex i.

#include<bits/stdc++.h>
using namespace std;

// The trick is same as DFS. We need to keep track of parent node
// Same condition, if parent is not neighbor, then we have a cycle
// The only difficulty is storing the parent nodes.
// We maintain a parent array, that can capture parent of nodes.
// trick here is node is the parent of neigh
// Use that to track
// 

    
bool bfs(vector<vector<int>> &adj, vector<int> &visited, int source, vector<int> &parent)
{
    queue<int> q;
    q.push(source);
    visited[source] = 1;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        
        for(int neigh: adj[node])
        {
            if(!visited[neigh])
            {
                visited[neigh] = 1;
                parent[neigh] = node;
                q.push(neigh);
            }
            
            else
            {
                if(neigh != parent[node])
                {
                    return true;
                }
            }
        }
    }
    return false;

}

bool isCycle(vector<vector<int>>& adj) 
{
    // Code here

    int n = adj.size();
    vector<int> visited(n), parent(n);

    for(int i=0; i<n; i++)
    {
        if(!visited[i] && bfs(adj, visited, i, parent))
        {
            return true;
        }
    }
    return false;
}