// https://www.geeksforgeeks.org/problems/alien-dictionary/1
// Problem Statement: Given a sorted dictionary of an alien language having N words and 
// k starting alphabets of a standard dictionary. Find the order of characters in the alien language.
// Input: N = 5, K = 4
// dict = {"baa","abcd","abca","cab","cad"}
// Output: b d a c

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        
        // kahn's bfs algorithm
        vector<int> topo_sort(vector<vector<int>>& adj, int k)
        {
            vector<int> in_degree(k, 0);
            
            // Calculate in-degrees
            for(int i = 0; i < k; i++) {
                for(int neigh : adj[i]) {
                    in_degree[neigh]++;
                }
            }
            
            // Queue for BFS
            queue<int> q;
            
            // Start with nodes with in-degree of 0
            for(int i = 0; i < k; i++) {
                if(in_degree[i] == 0) {
                    q.push(i);
                }
            }
            
            vector<int> res;
            
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                res.push_back(node);
                
                // Process neighbors
                for(int neigh : adj[node]) {
                    in_degree[neigh]--;
                    if(in_degree[neigh] == 0) {
                        q.push(neigh);
                    }
                }
            }
            
            // If the result size is not equal to number of characters, cycle detected
            if(res.size() != k) {
                return {};
            }
            
            return res;
        }
      
        string findOrder(vector<string>& words) 
        {
            int n = words.size();
            
            // Map each character to a unique integer
            unordered_map<char, int> mp;
            for(int i = 0; i < n; i++) 
            {
                for(char ch : words[i]) 
                {
                    mp[ch] += 1;  // Mark characters to be considered
                }
            }
            
            // Number of unique characters
            // it is better to know this from question itself. if not.
            int k = mp.size();
            
            // Create adjacency list for the graph
            vector<vector<int>> adj(k);
            
            // Build the graph based on word pairs
            for(int i = 0; i < n - 1; i++) 
            {
                string word1 = words[i], word2 = words[i + 1];
                int len = min(word1.size(), word2.size());
                for(int j = 0; j < len; j++) 
                {
                    if(word1[j] != word2[j]) 
                    {
                        // Create a directed edge from word1[j] to word2[j]
                        adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                        break;
                    }
                }
            }
            
            // Perform topological sort on the adjacency list
            vector<int> topo = topo_sort(adj, k);
            
            // If topo sort is not valid (cycle detected), return empty string
            if(topo.empty()) 
            {
                return "";
            }
            
            // Convert the result into a string
            string res;
            for(int r : topo) 
            {
                res += char(r + 'a');
            }
            
            return res;
        }
    };
    
