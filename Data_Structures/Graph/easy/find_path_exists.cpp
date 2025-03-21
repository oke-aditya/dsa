// https://leetcode.com/problems/find-if-path-exists-in-graph/description/

// There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). 
// The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a 
// bi-directional edge between vertex ui and vertex vi. 
// Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

// Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
// Output: true
// Explanation: There are two paths from vertex 0 to vertex 2:
// - 0 → 1 → 2
// - 0 → 2


// Solution:

// Note that in this question we need to build the adjacency list.
// without building it we cannot find if path exists.
// To check if path exists we can do either dfs or bfs.
// we just need to check if the destination was visited.


#include<bits/stdc++.h>
using namespace std;


void print_vv(vector<vector<int>> vv)
{
    for(auto v: vv)
    {
        cout<<"[";
        for(auto e: v)
        {
            cout<<e<<",";
        }
        cout<<"], ";
    }
}

void dfs(vector<vector<int>> &adj, vector<int> &visited, int source)
{
    visited[source] = 1;

    for(int neigh: adj[source])
    {
        if(!visited[neigh])
        {
            visited[neigh] = 1;
            dfs(adj, visited, neigh);
        }
    }
}


bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
{
    // we need to construct the adj matrix here
    // we don't have one

    vector<vector<int>> adj(n);

    for(auto v: edges)
    {
        int s = v[0];
        int d = v[1];

        adj[s].push_back(d);
        adj[d].push_back(s);
    }

    // print_vv(adj);

    // Now we can do any traversal and find out if it is visited
    vector<int> visited(n);
    dfs(adj, visited, source);

    return visited[destination];
    
}
