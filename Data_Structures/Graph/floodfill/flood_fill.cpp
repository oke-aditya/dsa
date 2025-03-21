// https://leetcode.com/problems/flood-fill/description/

// You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image.
// You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

// To perform a flood fill:

//     Begin with the starting pixel and change its color to color.
//     Perform the same process for each pixel that is directly adjacent 
//      (pixels that share a side with the original pixel, either horizontally or vertically) 
//      and shares the same color as the starting pixel.
//     Keep repeating this process by checking neighboring pixels of the updated pixels 
//      and modifying their color if it matches the original color of the starting pixel.
//     The process stops when there are no more adjacent pixels of the original color to update.

// Return the modified image after performing the flood fill.

// Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
// Output: [[2,2,2],[2,2,0],[2,0,1]]

// solution:
// This is direct application of dfs / flood fill
// note the extra condition we need is to carry forward the initialColor
// If the initialColor does not match the color that we are gonna color, then don't
// that's the condition in the question
// else do the same flood fill trick
// we can also do this via BFS! 


#include<bits/stdc++.h>
using namespace std;

// DFS Solution
class Solution 
{
    public:

        vector<int> dx = {-1, 0, 0, 1};
        vector<int> dy = {0, 1, -1, 0};
        // all navigations

        // pass by reference to do inplace
        void dfs(vector<vector<int>> &image, int x, int y, int color, int m, int n, int initialColor)
        {
            image[x][y] = color;

            // all 4 directions
            for(int i=0; i<4; i++)
            {
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if(new_x >=0 && new_x < m && new_y >=0 && new_y < n && image[new_x][new_y] == initialColor)
                {
                    dfs(image, new_x, new_y, color, m, n, initialColor);
                }
            }

        }

        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
        {
            // we can just re-use the inplace image to do dfs
            // m rows, n cols
            int m = image.size();
            int n = image[0].size();

            // do dfs on the sr, sc positions
            // manipulate in place and return the image
            // we don't need to manipulate every cell here
            int initialColor = image[sr][sc];
            if(initialColor != color)
            {
                dfs(image, sr, sc, color, m, n, initialColor);
            }
            return image;


        }
};

// BFS Solution
class Solution2 {
    public:
    
        vector<int> dx = {-1, 0, 0, 1};
        vector<int> dy = {0, 1, -1, 0};
        // all navigations
    
        // pass by reference to do inplace
        void bfs(vector<vector<int>> &image, int x, int y, int color, int m, int n, int initialColor)
        {
            // note we need to cordinates in the q.
            queue<pair<int, int>> q;
            // push the cordinates
            q.push({x, y});
            image[x][y] = color;
    
            while(!q.empty())
            {
                int xi = q.front().first;
                int yi = q.front().second;
                q.pop();
    
                for(int i=0; i<4; i++)
                {
                    int new_x = xi + dx[i];
                    int new_y = yi + dy[i];
    
                    if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && initialColor == image[new_x][new_y])
                    {
                        q.push({new_x, new_y});
                        image[new_x][new_y] = color;
                    }
                }
            }
        }
    
    
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
        {
            // we can just re-use the inplace image to do dfs
            // m rows, n cols
            int m = image.size();
            int n = image[0].size();
    
            // do dfs on the sr, sc positions
            // manipulate in place and return the image
            // we don't need to manipulate every cell here
            int initialColor = image[sr][sc];
            if(initialColor != color)
            {
                bfs(image, sr, sc, color, m, n, initialColor);
            }
            return image;
    
    
        }
    };

