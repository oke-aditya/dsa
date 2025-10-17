// https://leetcode.com/problems/time-needed-to-inform-all-employees/description/

// A company has n employees with a unique ID for each employee from 0 to n - 1. The head of the company is the one with headID.

// Each employee has one direct manager given in the manager array where manager[i] is 
// the direct manager of the i-th employee, manager[headID] = -1. Also, it is guaranteed that the
//  subordination relationships have a tree structure.

// The head of the company wants to inform all the company employees of an urgent piece of news. 
// He will inform his direct subordinates, and they will inform their subordinates, 
// and so on until all employees know about the urgent news.

// The i-th employee needs informTime[i] minutes to inform all of his direct subordinates 
// (i.e., After informTime[i] minutes, all his direct subordinates can start spreading the news).

// Return the number of minutes needed to inform all the employees about the urgent news.

// Example 1:

// Input: n = 1, headID = 0, manager = [-1], informTime = [0]
// Output: 0
// Explanation: The head of the company is the only employee in the company.

// Example 2:

// Input: n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime = [0,0,1,0,0,0]
// Output: 1
// Explanation: The head of the company with id = 2 is the direct manager of all the employees 
// in the company and needs 1 minute to inform them all.
// The tree structure of the employees in the company is shown.

// Main idea here is to build the graph
// Also push the time to the queue. Remember to do this.
// 

#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        // build a graph
        // do bfs from headId

        vector<vector<int>> adj(n);
        int source = headID;

        for(int i=0; i<n; i++) {
            if(manager[i] != -1) {
                adj[manager[i]].push_back(i);
            }
        }

        // queue of {node, time_taken}
        queue<pair<int, int>> q;
        vector<int> visited(n, 0);

        q.push({source, 0});
        visited[source] = 1;
        int max_time_taken = 0;

        while(!q.empty()) {
            int node = q.front().first;
            int time = q.front().second;
            q.pop();
            visited[node] = 1;
            
            max_time_taken = max(time, max_time_taken);

            for(int neigh: adj[node]) {
                if(!visited[neigh]) {
                    q.push({neigh, time + informTime[node]});
                }
            }
        }
        return max_time_taken;
    }
};

