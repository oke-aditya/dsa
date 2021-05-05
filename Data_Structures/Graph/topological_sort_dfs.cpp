// Topological Sorting.

// Topological sorting for Directed Acyclic Graph (DAG) is a
// linear ordering of vertices such that for every directed edge u v, vertex
// u comes before v in the ordering. Topological Sorting
// for a graph is not possible if the graph is not a DAG.

// There can be more than one topological sorting for a graph.

// The first vertex in topological sorting is
// always a vertex with in-degree as 0 (a vertex with no incoming edges).


// https://www.geeksforgeeks.org/topological-sorting/

// Time Complexity: O(V+E). 

// Auxiliary space: O(V). 
// The extra space is needed for the stack.


// Given a Directed Graph with V vertices and E edges, Find any Topological Sorting of that Graph.

// Algorithm: -

// This can be implemented as a modified DFS.
// In topological sorting, we use a temporary stack. We don’t print the vertex immediately, we 
// first recursively call topological sorting for all
// its adjacent vertices, then push it to a stack.
// Finally, print contents of the stack.
// Note that a vertex is pushed to stack only when
// all of its adjacent vertices (and their adjacent vertices and so on) are already in the stack. 
// 
// Traverse DFS such that ending edge is first to go into stack. This ensures ordering.


#include<bits/stdc++.h>
using namespace std;


void find_topo_sort(int node, vector<int> &vis, stack<int> &stk, vector<int> adj[])
{
    // Mark as visited.
    vis[node] = 1;

    // Visit all neighbors.
    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            // Visit the non visited nodes.
            find_topo_sort(it, vis, stk, adj);
        }
    }

    // Push the node after dfs
    stk.push(node);

}

vector <int> topo_sort(int V, vector<int> adj[])
{

    // Stack to store the toposort.
    stack<int> st;

    // Vecotr to store visited vertices.
    // Initially all are not visited.
    vector <int> vis(V, 0);

    for(int i=0; i<V; i++)
    {
        // If not visited.
        if(vis[i] == 0)
        {
            find_topo_sort(i, vis, st, adj);
        }
    }

    // Reverse the stack and return
    vector <int> res;
    while(!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }

    return res;
}


int main(int argc, char const *argv[])
{
    // Number of vertices and Edges.
    int V, E;
    cin >> V >> E;
    vector<int> adj[V+1];
    // Adjacenct list for all the vertices.

    // Process each edge to build the graph.
    for (int i = 0; i < E; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);

        // If directed graph this is not true.
        adj[v2].push_back(v1);
    }

    // Peform bfs for the given graph with adjacenc list and number of vertices.
    vector <int> res = topo_sort(V, adj);
    return 0;

}

