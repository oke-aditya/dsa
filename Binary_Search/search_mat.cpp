// Given an n x n matrix and a number x, find the position of x in the matrix if it is present in it.
// Otherwise, print “Not Found”. In the given matrix, every row and column is sorted in increasing order.
// The designed algorithm should have linear time complexity.

// Input: mat[4][4] = { {10, 20, 30, 40},
//                       {15, 25, 35, 45},
//                       {27, 29, 37, 48},
//                       {32, 33, 39, 50}};
//               x = 29
// Output: Found at (2, 1)

// Input : mat[4][4] = { {10, 20, 30, 40},
//                       {15, 25, 35, 45},
//                       {27, 29, 37, 48},
//                       {32, 33, 39, 50}};
//               x = 100
// Output : Element not found
// Explanation: Element 100 is not found

// Solution: -
// Start from top right.
// Use binary search to traverse rows and columns
// If element is greater than tgt then move left.
// If element is smaller then move bottom.
// If we hit the target then return it,
// If we have reached left most column or bottom most row, return.

#include <bits/stdc++.h>
using namespace std;

int search_mat(int mat[4][4], int n, int target)
{
    int i = 0, j = n - 1;
    while (i < n && j >= 0)
    {
        if (target == mat[i][j])
        {
            cout << i << " " << j << endl;
            return 1;
        }
        else if (target > mat[i][j])
        {
            i += 1;
        }
        else if (target < mat[i][j])
        {
            j -= 1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int mat[4][4] = {{10, 20, 30, 40},
                     {15, 25, 35, 45},
                     {27, 29, 37, 48},
                     {32, 33, 39, 50}};
    int n = 4;
    int target = 27;
    int res = search_mat(mat, n, target);

    return 0;
}
