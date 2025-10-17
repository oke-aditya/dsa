// https://leetcode.com/problems/valid-triangle-number/description/

// Given an integer array nums, return the number of triplets chosen from the 
// array that can make triangles if we take them as side lengths of a triangle.

// Example 1:

// Input: nums = [2,2,3,4]
// Output: 3
// Explanation: Valid combinations are: 
// 2,3,4 (using the first 2)
// 2,3,4 (using the second 2)
// 2,2,3

// Example 2:

// Input: nums = [4,2,3,4]
// Output: 4

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& arr) {
        int count = 0, n = arr.size();
        sort(begin(arr), end(arr));

        for(int i=n-1; i>1; i--) {

            int left = 0, right = i - 1;
            while(left < right) {
                if(arr[i] < (arr[left] + arr[right])) {
                    count += right - left;
                    right -= 1;
                }

                else {
                    left += 1;
                }

            }
        }
        return count;
    }
};

