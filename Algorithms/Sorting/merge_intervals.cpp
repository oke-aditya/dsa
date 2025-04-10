// https://leetcode.com/problems/merge-intervals/description/

// Very classic question
// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
// and return an array of the non-overlapping intervals that cover all the intervals in the input.

// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

// Example 2:

// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.


// Solution:

// Keep it very simple.
// Sort the intervals at first
// Try to process each interval and see if it is > than previous
// Alter the result in place for efficiency

// Python code

// def merge(self, intervals: List[List[int]]) -> List[List[int]]:
//         intervals.sort()
//         res = [intervals[0]]

//         for i in range(len(intervals)):
    
//             if(res[-1][1] >= intervals[i][0]):
//                 res[-1][1] = max(res[-1][1], intervals[i][1])
//                 res[-1][0] = min(res[-1][0], intervals[i][0])
//             else:
//                 res.append(intervals[i])
//         return res


#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            
            vector<vector<int>> res;
            sort(begin(intervals), end(intervals));
            res.push_back(intervals[0]);
            
            for(int i=0; i<intervals.size(); i++) {
                
                if(res[res.size() - 1][1] >= intervals[i][0]) {
                    res[res.size() - 1][1] = max(res[res.size() -1][1], intervals[i][1]);
                    res[res.size() - 1][0] = min(res[res.size() -1][0], intervals[i][0]);
                }
                else {
                    res.push_back(intervals[i]);
                }
            }

            return res;
        }
    };



