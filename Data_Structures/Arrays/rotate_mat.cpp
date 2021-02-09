// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
// DO NOT allocate another 2D matrix and do the rotation.

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]

// Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

// Input: matrix = [[1]]
// Output: [[1]]

// Input: matrix = [[1,2],[3,4]]
// Output: [[3,1],[4,2]]

// Solution: -
// Brute force.
// Create a new matrix, first row becomes last column and so on.
// Need a new O(mxn) space

// 1 2 3
// 4 5 6
// 7 8 9

// 7 4 1
// 8 5 2
// 9 6 3

// Optimal solution: -
// Find transpose of matrix
// Rotate every row of matrix.

#include <bits/stdc++.h>
using namespace std;

void print_mat(vector<vector<int>> mat)
{
    int n = mat.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void rot_mat(vector<vector<int>> &mat)
{
    // Find transpose in place
    int m = mat.size();
    int n = mat[0].size();
    for (int i = 0; i < m; i++)
    {
        // Traverse only half of the matrix.
        for (int j = 0; j < i; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Reverse every row
    for (int i = 0; i < m; i++)
    {
        reverse(mat[i].begin(), mat[i].end());
    }
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    print_mat(mat);

    rot_mat(mat);
    print_mat(mat);

    return 0;
}
