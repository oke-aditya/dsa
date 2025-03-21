// https://leetcode.com/problems/surrounded-regions/

// You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

// Connect: A cell is connected to adjacent cells horizontally or vertically.

// Region: To form a region connect every 'O' cell.

// Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells 
// and none of the region cells are on the edge of the board.

// To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. 
// You do not need to return anything.

// Example 1:

// Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

// Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

// solution
// Iterate over all edge nodes and then do a bfs / dfs from them
// 
// 

#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
    
        vector<int> dx = {-1, 0, 0, 1};
        vector<int> dy = { 0, 1, -1, 0};
    
        void solve(vector<vector<char>>& grid) 
        {
            // we need to change the char board in place
            // trick is to mark all the edge nodes which are 0
            // these will never change
            // also nodes that can visit these edge nodes will never change
            // keeping track of visited will help here.
    
            queue<pair<int, int>> q;
            int m = grid.size();
            int n = grid[0].size();
            vector<vector<int>> visited(m, vector<int>(n));
    
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                {
                    // this is first row / col
                    // or last row / col
                    if(i == 0 || j == 0 || i == m - 1 || j == n -1)
                    {
                        if(grid[i][j] == 'O')
                        {
                            q.push({i, j});
                            visited[i][j] = 1;
                        }
                    }   
                }
            }
    
            // cout<<q.size();
    
            // now do a flood fill bfs here?
            // we can do dfs also
            // idea is to mark all things that can visited by 'O's
            while(!q.empty())
            {
                int l = q.size();
                while(l--)
                {
                    pair<int, int> p = q.front();
                    q.pop();
    
                    int x = p.first;
                    int y = p.second;
    
                    for(int i=0; i<4; i++)
                    {
                        int new_x = x + dx[i];
                        int new_y = y + dy[i];
    
                        if(new_x >= 0 && new_x < m && new_y >=0 && new_y < n  && grid[new_x][new_y] == 'O' && !visited[new_x][new_y])
                        {
                            q.push({new_x, new_y});
                            visited[new_x][new_y] = 1;
                        }
                    }
                }
            }
    
            // all Os that cannnot be visited
            // means they cannot be adjacent to the edges or corners
            // so they should get converted to Xs.
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(grid[i][j] == 'O' && !visited[i][j])
                    {
                        grid[i][j] = 'X';
                    }
                }
            }
    
        }
    };