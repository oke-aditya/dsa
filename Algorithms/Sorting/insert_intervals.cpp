// // https://leetcode.com/problems/insert-interval/

// You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] 
// represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. 
// You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

// Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and 
// intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
// Return intervals after the insertion.
// Note that you don't need to modify intervals in-place. You can make a new array and return it.

// Example 1:

// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]

// Example 2:

// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

// solution
// just insert and do merge intervals

#include <vector>
#include <algorithm>

using namespace std;


class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            // just insert and do merge intervals?
    
            intervals.push_back(newInterval);
            sort(begin(intervals), end(intervals));
    
            vector<vector<int>> res;
            res.push_back(intervals[0]);
    
            int n = intervals.size();
            for(int i=0; i<n; i++) {
    
                if(res[res.size() - 1][1] >= intervals[i][0]) {
                    res[res.size() - 1][1] = max(res[res.size() - 1][1], intervals[i][1]);
                    res[res.size() - 1][0] = min(res[res.size() - 1][0], intervals[i][0]);
                }
                else {
                    res.push_back(intervals[i]);
                }
    
            }
            return res;
        }
    };


