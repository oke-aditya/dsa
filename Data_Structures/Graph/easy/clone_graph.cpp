// https://leetcode.com/problems/clone-graph/description/
// Given a reference of a node in a connected undirected graph.

// Return a deep copy (clone) of the graph.

// Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {

    unordered_map<Node*, Node*> mp;

public:

    // do a dfs and maintain copy of nodes to to a hashmap
    void dfs(Node* node) {
        Node* copy = new Node(node->val);
        mp[node] = copy;

        // neighbors is a list of vectors
        // we need to traverse the neigbors
        for(auto neigh: node->neighbors) {

            // if we have not processed this neigh
            // then we need to traverse
            if(mp.find(neigh) == mp.end()) {
                dfs(neigh);
            }

            // at end of recursion
            // simply add map copy
            copy->neighbors.push_back(mp[neigh]);
        }
    }

    Node* cloneGraph(Node* node) {
        if(node == nullptr) {
            return nullptr;
        }

        dfs(node);
        return mp[node];
    }
};