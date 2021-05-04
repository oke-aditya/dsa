// Performing BFS in graph

// BFS (Breadth First Search)

// Note that there can be disconnected graphs as well.
// So we need to take care of such cases too.

// Consider a graph

//  1 --- 2 --- 4
//        |     |
//        |     |
//        7 --- 6

// Input for the graph

// 5 7 (5 vertices 5 edges)
// 1 2
// 2 4
// 2 7
// 4 6
// 6 7

//  Note that both are part of same graph but two different componenets.
//  We need to perfrom BFS.

// Algorithm: -
// We need to return a vector cotaining how the graph was traversed.
// We keep a vector that denotes if each of the node was visited.
// We make use of Queue to store the vertices that are processed.
// We use the adjacency list of graph.
// For each node we visit all the edges.
//

// BFS is more suitable for searching vertices which are closer to the given source.

// Time Complexity: -
// The Time complexity of BFS is O(V + E) when Adjacency List is
// used and O(V^2) when Adjacency Matrix is used, where V stands for vertices and E stands for edges.

// Space Comlexity: -
// For Adjacency List representation
// O(V + E) + O(E) + O(V)


#include <bits/stdc++.h>
using namespace std;

// Note that adjacency list is list of vectors.
vector <int> bfs(int V, vector<int> adj[])
{
    vector <int> res;
    // Initially all are not visited.
    vector <int> is_visited(V, 0);

    // A queue to store vertices.
    queue <int> q;

    // Visit the first one.
    q.push(0);
    is_visited[0] = 1;

    // Process each element from the queue
    while (!q.empty())
    {
        // Get the node to visit.
        int node = q.front();
        q.pop();

        // This node is visited to push to result.
        res.push_back(node);

        // Visit this node. Traverse through adjacent elements.
        for(auto it: adj[node])
        {
            // If it is not visited
            if(!is_visited[it])
            {
                // This will be visited next.
                q.push(it);
                // Since we will visit this mark it as done.
                is_visited[it] = 1;
            }
        }
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
    vector <int> res = bfs(V, adj);

    // Print out bfs
    for(auto r: res)
    {
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
