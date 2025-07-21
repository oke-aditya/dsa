// https://leetcode.com/problems/search-a-2d-matrix-ii/description/

// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. 
// This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.

// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
// Output: true

// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
// Output: false

// Solution:

// Difference from first question is that, here the property of matrix is different
// Solution won't work as is
// Start at the top-right corner of the matrix (i.e., the element in the first row and last column).
// We will call this element current.
// Compare current with the target value target. If current is equal to target,
// return true since we have found the target in the matrix.
// If current is greater than target, we can eliminate the entire last column
// (i.e., all elements in the last column are greater than current and therefore greater than target).
// Move one column to the left to consider the next element in that row.
// We will call this new element current.
// If current is less than target, we can eliminate the entire first
// row (i.e., all elements in the first row are less than current and therefore less than target).
// Move one row down to consider the next element in that column. We will call this new element current.
// Repeat steps 2-4 until current is equal to target or we reach the end of the matrix.
// If we reach the end of the matrix without finding the target, return false.

// The idea behind this algorithm is to take advantage of the sorted property of 
// the matrix to eliminate entire rows or columns at once, and narrow down 
// the search space for the target value. Since we start at the top-right corner, 
// we can eliminate rows or columns as we move left or down, respectively.

// The time complexity of this algorithm is O(m + n) since we move at most m + n 
// steps in the matrix. This is much more efficient than a naive approach of 
// iterating over every element in the matrix, which would take O(m x n) time.


#include <vector>
using namespace std;

class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n - 1;

        while(left < m && right >= 0) {
            if(matrix[left][right] == target) {
                return true;
            }

            else if(matrix[left][right] < target) {
                left += 1;
            }
            else {
                right -= 1;
            }
        }  

        return false;

    }
};
