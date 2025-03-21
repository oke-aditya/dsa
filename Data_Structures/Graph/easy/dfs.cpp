// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

// Given a connected undirected graph represented by an adjacency list adj, which is a vector of vectors where 
// each adj[i] represents the list of vertices connected to vertex i. Perform a Depth First Traversal (DFS) starting from vertex 0, 
// visiting vertices from left to right as per the adjacency list, and return a list containing the DFS traversal of the graph.

// Note: Do traverse in the same order as they are in the adjacency list.

#include<bits/stdc++.h>
using namespace std;

// note we are passing visited and res by reference param
// else they would not work
// pass adjacency list also as reference to make this bit efficient
void dfs(vector<vector<int>> &adj, vector<int> &visited, vector<int> &res, int source)
{
    visited[source] = 1;
    res.push_back(source);

    for(int neigh: adj[source])
    {
        if(!visited[neigh])
        {
            dfs(adj, visited, res, neigh);
        }
    }
}

vector<int> dfsOfGraph(vector<vector<int>>& adj) 
{
    int n = adj.size();
    vector<int> visited(n);   
    vector<int> res;
    dfs(adj, visited, res, /*source= */ 0);
    
    return res;
}
