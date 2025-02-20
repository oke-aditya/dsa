// https://leetcode.com/problems/course-schedule-ii/description/

#include<bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
{
    int n = numCourses;

    // construct an adjacency list
    vector<vector<int>> adj(n);

    // also maintain the indegrees
    vector<int> indegree(n, 0);

    int m = prerequisites.size();

    for(int i=0; i<m; i++)
    {
        vector<int> node_pair = prerequisites[i];
        int source = node_pair[1];
        int dest = node_pair[0];
        adj[source].push_back(dest);
        indegree[dest] += 1;
    }

    // try to do topological traversal
    // if we end up doing graph traversal and not visit all the nodes
    // then there is a loop

    queue<int> q;
    vector<int> topo;

    for(int i=0;i<n;i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);        
        }
    }

    // // topo iter
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(int neigh: adj[node])
        {
            // cout<<"neig"<<neigh<<endl;
            indegree[neigh] -= 1;
            if(indegree[neigh] == 0)
            {
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

    // return the order
    if (topo.size() == n) 
        return topo;
    else
        return vector<int>{};
}

