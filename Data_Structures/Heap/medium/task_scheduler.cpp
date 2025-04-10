// https://leetcode.com/problems/task-scheduler/

// You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. 
// Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, 
// but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.
// Return the minimum number of CPU intervals required to complete all tasks.

// Example 1:

// Input: tasks = ["A","A","A","B","B","B"], n = 2
// Output: 8

// Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
// After completing task A, you must wait two intervals before doing A again. The same applies to task B.
// In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.

// There are two approaches.
// One is trying to deduce a formula using greedy method
// Other is to figure out and simulate a max heap

#include <queue>
#include <unordered_map>
#include <vector>
using namespace std; 


class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {

            // main idea is to create a max heap first
            // that should take into the most frequent tasks

            unordered_map<char, int> mp;
            for(char task: tasks) {
                mp[task] += 1;
            }

            // keep the pairs in priority queue
            priority_queue<pair<int, char>> maxh;
            for(auto itr=mp.begin(); itr!=mp.end(); itr++) {
                maxh.push({itr->second, itr->first});
            }

            // now pick these pairs and do the count
            int res = 0;

            while(!maxh.empty()) {
                // create a vector of tasks
                // [{3: 'A'}, {2: 'B}] 
                // if the first task can be done in single step

                if(maxh.top().first == 1) {
                    res += maxh.size();
                    break;
                }

                vector<pair<int, char>> v;
                v.push_back(maxh.top());
                maxh.pop();
                
                // increment the answer as first is processed
                res += 1;

                // now for 'N' Time interval, process other tasks
                // all these tasks can be done without cooldown
                for(int i=0; i<n; i++) {
                    if(!maxh.empty()) {
                        v.push_back(maxh.top());
                        maxh.pop();
                    }
                    res += 1;
                }

                // re populate the tasks back
                for(auto t: v)  {
                    if(t.first > 1) {
                        maxh.push({t.first - 1, t.second});
                    }
                }
            }
            return res;
        }
    };


