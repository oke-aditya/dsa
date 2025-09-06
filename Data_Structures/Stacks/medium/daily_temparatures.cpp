// https://leetcode.com/problems/daily-temperatures/description/

// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

// Example 1:

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]

// Example 2:

// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]

// Example 3:

// Input: temperatures = [30,60,90]
// Output: [1,1,0]

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// brute force
// fails for 10**5 input

class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& arr) {
            // loosely translates to finding index of next greater element to right
    
            // brute force, gives TLE
            
            int i=0, j=0, m=arr.size();
            vector<int> res;
    
            for(i=0; i<m; i++) {
                bool flag = true;
                for(j=i+1; j<m;j++) {
                    // cout<<"i: "<<i<<endl;
                    // cout<<"j: "<<j<<endl; 
                    // cout<<'-'<<endl;
                    if(arr[j] > arr[i]) {
                        // j - i are the number of days required
                        res.push_back((j - i));
                        flag = false;
                        break;
                    }
                    // we searched the whole array to not find anything
                    if(j == m-1) {
                        res.push_back(0);
                    }
                }
            }
    
            // last element will be forever 0
            res.push_back(0);
            return res;    
        }
    };

    vector<int> dailyTemperatures(vector<int>& arr) {
        // O(n)
        vector<int> res;
        int n = arr.size();
        stack<int> stk;

        for(int i=n-1; i>=0; i--) {
            while(!stk.empty() && arr[stk.top()] <= arr[i]) {
                stk.pop();
            }
            if(stk.empty()) {
                res.push_back(0);
            }
            else {
                res.push_back(stk.top() - i);
            }

            stk.push(i);
        }
        
        reverse(begin(res), end(res));

        return res;
    }
    