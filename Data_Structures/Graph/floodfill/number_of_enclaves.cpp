// https://leetcode.com/problems/number-of-enclaves/description/

// You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
// Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
// Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
// Output: 3
// Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.

// solution:
// This is very similar to surrounded regiones.
// Just do a BFS / DFS from the edge cells
// Once we do BFS, we will know all visited nodes.
// Just do a count of non visited ones.

#include<bits/stdc++.h>
using namespace std;


class Solution 
{
    public:
        vector<int> dx = {-1, 0, 0, 1};
        vector<int> dy = {0, 1, -1, 0};
    
    
        int numEnclaves(vector<vector<int>>& grid) 
        {
            // track all nodes which are on edges of matrix
            // add these to a queue?
    
            int m = grid.size();
            int n = grid[0].size();
            vector<vector<int>> visited(m, vector<int>(n, 0));
    
    
            queue<pair<int, int>> q;
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if((i == 0 || j == 0 || i == m-1 || j == n -1) && grid[i][j] == 1)
                    {
                        q.push({i, j});
                        visited[i][j] = 1;
                    }
                }
            }
    
            cout<<q.size();
            
            // just a bfs and marking those as visited
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
    
                        if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n 
                            && !visited[new_x][new_y] && grid[new_x][new_y] == 1)
                        {
                            q.push({new_x, new_y});
                            visited[new_x][new_y] = 1;
                        }
                    }
                }
            }
            
            // unvisited nodes at end of bfs are enclaves
            int unvisited_ones = 0;
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(!visited[i][j] && grid[i][j] == 1)
                    {
                        unvisited_ones += 1;
                    }
                }
            }
            return unvisited_ones;
    
        }
    };