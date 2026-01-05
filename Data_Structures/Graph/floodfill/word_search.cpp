// https://leetcode.com/probl                                                                       ems/word-search/description/

// Given an m x n grid of characters board and a string word, return true if word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells, where adjacent 
// cells are horizontally or vertically neighboring. 
// The same letter cell may not be used more than once.

// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true

// Solution
// this is backtracking applied to classic dfs
// we just need to try every possible word combination
// but also backtrack if the word does not work

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(vector<vector<char>>& board, string word, vector<vector<int>> &visited, int x, int y, int m, int n, int idx) {
        if(idx == word.size()) {
            return true;
        }

        if(x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || board[x][y] != word[idx]) {
            return false;
        }

        visited[x][y] = 1;

        bool ls = dfs(board, word, visited, x+1, y, m, n, idx+1);
        bool rs = dfs(board, word, visited, x, y+1, m, n, idx+1);
        bool ts = dfs(board, word, visited, x-1, y, m, n, idx+1);
        bool bs = dfs(board, word, visited, x, y-1, m, n, idx+1);

        visited[x][y] = 0;

        return ls | rs | ts | bs;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == word[0] && !visited[i][j]) {
                    if (dfs(board, word, visited, i, j, m, n, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;

    }
};


