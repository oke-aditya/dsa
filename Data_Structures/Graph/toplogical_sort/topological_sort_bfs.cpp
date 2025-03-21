// Topological sort

// https://www.geeksforgeeks.org/problems/topological-sort/1
// This is only eligible in DAG
// It makes no sense in Cyclic Graph and there are no dependencies in UDG
// We need to sort the graph according to nodes having minimum dependencies.

// This can also detect cycle in a DG
// if we can't do topological sort, we have a cycle.
// This can be done using BFS. Which is also called Kahn's algorithm

// Algorithm
// Calculate in degree of all graph nodes
// For those with indegree as 0. push to queue
// Every iteration, reduce the indegree and keep pushing to queue whenever they are 0
// push to result
// 

#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>>& adj) 
{
    queue<int> q;
    int n = adj.size();
    vector<int> indegree(n);
    vector<int> res;

    // source for bfs
    int source = 0;

    for(int i=0; i<adj.size(); i++)
    {
        for(int j=0; j<adj[i].size(); j++)
        {
            indegree[adj[i][j]] += 1;
        }
    }

    // see the indegrees, just in case
    // for(auto x: indegree)
    // {
    //     cout<<x<<" ";
    // }

    // now push 0 indegrees to queue
    // we need the node which is i. not the degree!
    for(int i=0; i<n; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        res.push_back(node);
        
        for(int neigh: adj[node])
        {
            indegree[neigh] -= 1;
            if(indegree[neigh] == 0)
            {
                q.push(neigh);
            }
        }
    }

    return res;
   
}
