// Consider a rat placed at position (0, 0) in an n x n square matrix mat. 
// The rat's goal is to reach the destination at position (n-1, n-1). 
// The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

// The matrix contains only two possible values:

//     0: A blocked cell through which the rat cannot travel.
//     1: A free cell that the rat can pass through.

// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, 
// the rat cannot move to any other cell. In case of no path, return an empty list.

// The task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) 
// and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. 
// Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.

// 1s in matrix are free, 0s are blocked

#include<bits/stdc++.h>

using namespace std; 

void print_vs(vector<string> vv)
{
    for(auto s: vv)
    {
        cout<<s<<", ";
    }
}

struct Choice
{
    char direction;
    int dx, dy;
};

// check if we have reached the bottom right
bool is_solved(int x, int y, int n)
{
    return ((x == n-1) && (y == n-1));
}

// withing limits and free cell
bool is_valid(int x, int y, int n, vector<vector<int>> mat)
{
    return x >= 0 && y >= 0 && x <= n -1 && y <= n-1 && mat[x][y] == 1;

}

void backtrack(vector<vector<int>> mat, int x, int y, int n, vector<Choice> &choices, string &sol, vector<string> &res)
{
    if (is_solved(x, y, n))
    {
        res.push_back(sol);
        return;
    }

    for(auto &choice: choices)
    {
        int new_x = x + choice.dx;
        int new_y = y + choice.dy;
        if (is_valid(new_x, new_y, n, mat))
        {
            mat[x][y] = 0;
            sol.push_back(choice.direction);
            backtrack(mat, new_x, new_y, n, choices, sol, res);
            
            // undo step
            mat[x][y] = 1;
            sol.pop_back();
        }
    }
}


vector<string> solve_maze(vector<vector<int>> mat)
{
    vector<string> res;
    string sol = "";
    int x = 0;
    int y = 0;
    int n = mat.size();

    vector<Choice> choices = {{'U', -1, 0}, {'D', 1, 0}, {'R', 0, 1}, {'L', 0, -1}};

    if(mat[0][0] == 1)
    {
        backtrack(mat, x, y, n, choices, sol, res);
    }

    return res;

}



int main(int argc, char const *argv[])
{
    // Matrix is n x n square matrix
    vector<vector<int>> mat = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    auto res = solve_maze(mat);
    print_vs(res);
    return 0;
}


