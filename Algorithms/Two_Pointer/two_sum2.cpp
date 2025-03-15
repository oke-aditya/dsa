// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that 
// they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2]
// where 1 <= index1 < index2 <= numbers.length.
// Return the indices of the two numbers, index1 and index2, added by one as an 
// integer array [index1, index2] of length 2.

// Example 1:

// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]
// Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

// Example 2:

// Input: numbers = [2,3,4], target = 6
// Output: [1,3]
// Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) 
        {
            int left = 0;
            int right = numbers.size() - 1;
    
            vector<int> res;
    
            while(left <= right)
            {
                int sum = numbers[left] + numbers[right];
    
                if(sum > target)
                {
                    // reduce sum so reduce right
                    right = right - 1;
                }
    
                else if(sum < target)
                {
                    left = left + 1;
                }
    
                else
                {
                    res.push_back(left + 1);
                    res.push_back(right + 1);
                    return res;
                }
            }
            
            return res;
    
        }
    };


