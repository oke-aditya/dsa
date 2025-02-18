// Topological sort

// https://www.geeksforgeeks.org/problems/topological-sort/1
// This is only eligible in DAG
// It makes no sense in Cyclic Graph and there are no dependencies in UDG
// We need to sort the graph according to nodes having minimum dependencies.

// This can also detect cycle in a DG
// if we can't do topological sort, we have a cycle.
// This can be done using BFS. Which is also called Kahn's algorithm

// Algorithm:


// Trick with DFS!
// DFS always goes to node that has maximum dependency!
// We can do dfs and then reverse the result! 

// Viz
// https://leetcode.com/discuss/general-discussion/1078072/introduction-to-topological-sort

#include<bits/stdc++.h>
using namespace std;

void dfs(int source, vector<vector<int>> &adj, vector<int> &visited, vector<int> &res)
{
    visited[source] = 1;

    for(int neigh: adj[source])
    {
        if(!visited[neigh])
        {
            dfs(neigh, adj, visited, res);
        }
    }
    res.push_back(source);

}


vector<int> topologicalSort(vector<vector<int>>& adj) 
{
    int n = adj.size();
    vector<int> visited(n, 0);
    vector<int> res;

    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            dfs(i, adj, visited, res);
        }
    }
    reverse(begin(res), end(res));
    return res;
}



