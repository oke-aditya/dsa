// https://leetcode.com/problems/path-with-minimum-effort/description/

// You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, 
// where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), 
// and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). 
// You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.
// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
// Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

// Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
// Output: 2
// Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
// This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

// solution:
// 
// DP Will not work here. That is key to realise. We do not have subproblems.
// We can take a path and then have no clue if it is substep of bigger solution
// Key is to realise we can use djisktra here and solve this.
// We need to modify the priority queue in djisktra
// Instead of pair, we can push 3 values, minimum distance, and the (r, c) of the location
// Then do djisktra.


#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    vector<int> dx = {-1, 0, 0, 1};
    vector<int> dy = {0, -1, 1, 0};


    public:
        int minimumEffortPath(vector<vector<int>>& heights) 
        {

            //  min heap stores {min_dist, {r, c}} double pair
            priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minh;
    
            int m = heights.size();
            int n = heights[0].size();

            vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
            // as usual distance of start location is 0
            distance[0][0] = 0;
            minh.push({0, {0, 0}});

            while(!minh.empty())
            {
                pair<int, pair<int, int>> pp = minh.top();
                minh.pop();

                int dist_diff = pp.first;
                int x = pp.second.first;
                int y = pp.second.second;

                // if we have reached the bottom right
                if(x == m-1 && y == n-1)
                {
                    return dist_diff;
                }

                for(int i=0; i<4; i++)
                {
                    int new_x = x + dx[i];
                    int new_y = y + dy[i];

                    if(new_x >= 0 && new_y >= 0 && new_x < m && new_y < n)
                    {
                        int new_effort = max(abs(heights[x][y] - heights[new_x][new_y]), dist_diff);
                        if(new_effort < distance[new_x][new_y])
                        {
                            distance[new_x][new_y] = new_effort;
                            minh.push({new_effort, {new_x, new_y}});
                        }
                    }
                }
            }
            return 0;
        }
};