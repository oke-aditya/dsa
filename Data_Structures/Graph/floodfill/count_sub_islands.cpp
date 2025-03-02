// https://leetcode.com/problems/count-sub-islands/description/

// You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). 
// An island is a group of 1's connected 4-directionally (horizontal or vertical).
// Any cells outside of the grid are considered water cells.
// An island in grid2 is considered a sub-island if there is an island in grid1 that 
// contains all the cells that make up this island in grid2

// Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], 
// grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
// Output: 3
// Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
// The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.

// Solution:
// trick here is to not use any extra memory
// making an new result matrix to store every dfs iteration will lot more space for MLE
// We should check grid2 and grid1, and make use of these 2 in the dfs call
// On every dfs call check from grid2 and grid1 and mark flag as false


#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        vector<int> dx = {-1, 0, 0, 1};
        vector<int> dy = {0, 1, -1, 0};
    
        void dfs(int x, int y, vector<vector<int>>& visited,
                vector<vector<int>>& grid2, vector<vector<int>>& grid1, int m, int n, bool& flag) 
        {
            
            visited[x][y] = 1;
            
            // Check if this cell in grid2 is part of an island and it also exists in grid1
            if (grid2[x][y] == 1 && grid1[x][y] == 0) 
            {
                flag = false;  // This island is not a sub-island
            }
    
            // Explore all 4 directions (up, down, left, right)
            for (int i = 0; i < 4; i++)
            {
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && !visited[new_x][new_y] && grid2[new_x][new_y] == 1) 
                {
                    dfs(new_x, new_y, visited, grid2, grid1, m, n, flag);
                }
            }
        }
    
        int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
            int m = grid2.size();
            int n = grid2[0].size();
    
            vector<vector<int>> visited(m, vector<int>(n, 0));  // Track visited cells in grid2
            int count = 0;
    
            for (int i = 0; i < m; i++) 
            {
                for (int j = 0; j < n; j++) 
                {
                    // Start DFS when we find a cell in grid2 that is part of an island (1) and has not been visited yet
                    if (!visited[i][j] && grid2[i][j] == 1) 
                    {
                        bool isSubIsland = true;  // Assume it's a sub-island initially
                        dfs(i, j, visited, grid2, grid1, m, n, isSubIsland);
                        if (isSubIsland) 
                        {
                            count++;  // If it's a valid sub-island, increment the count
                        }
                    }
                }
            }
    
            return count;
        }
    };
    