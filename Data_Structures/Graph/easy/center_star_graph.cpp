// https://leetcode.com/problems/find-center-of-star-graph/description

// There is an undirected star graph consisting of n nodes labeled from 1 to n. 
// A star graph is a graph where there is one center node and exactly n - 1 edges 
// that connect the center node with every other node.

// You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates 
// that there is an edge between the nodes ui and vi. Return the center of the given star graph.

// Solution:

// here too we need to build the adjacency list. 
// We have the nodes numbered from 1.
// Find the node which has n connections.
// 


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
int findCenter(vector<vector<int>>& edges) 
{
    int n = edges.size();
    vector<vector<int>> adj(n+2);
    int res;

    for(auto e: edges)
    {
        int s = e[0];
        int d = e[1];

        adj[s].push_back(d);
        adj[d].push_back(s);
    }

    print_vv(adj); 

    // now find out node which has n edges
    // in adj matrix
    for(int i=0; i<adj.size(); i++)
    {
        if(adj[i].size() == n)
        {
            return i;
        }
    }

    return -1;

}

