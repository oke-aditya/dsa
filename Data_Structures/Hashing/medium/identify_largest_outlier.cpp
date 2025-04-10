// https://leetcode.com/problems/identify-the-largest-outlier-in-an-array/

// You are given an integer array nums. This array contains n elements, where exactly n - 2 elements are special numbers. 
// One of the remaining two elements is the sum of these special numbers, and the other is an outlier.
// An outlier is defined as a number that is neither one of the original special numbers nor the element representing the sum of those numbers.
// Note that special numbers, the sum element, and the outlier must have distinct indices, but may share the same value.
// Return the largest potential outlier in nums.
 
// Example 1:

// Input: nums = [2,3,5,10]
// Output: 10

// Explanation:
// The special numbers could be 2 and 3, thus making their sum 5 and the outlier 10.

// Example 2:
// Input: nums = [-2,-1,-3,-6,4]
// Output: 4

// Explanation:
// The special numbers could be -2, -1, and -3, thus making their sum -6 and the outlier 4.

// Example 3:
// Input: nums = [1,1,1,1,1,5,5]
// Output: 5

// Explanation:
// The special numbers could be 1, 1, 1, 1, and 1, thus making their sum 5 and the other 5 as the outlier.



#include <climits>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    public:
        int getLargestOutlier(vector<int>& nums) {
            // find the sum and make a map of nums
            unordered_map<int, int> mp;
            int sum = 0;
            for(auto num: nums) {
                sum += num;
                mp[num] += 1;
            }
    
            int res = INT_MIN;
    
            // try to check if each number is outlier?
            for(auto num: nums) {
                // if this is an outlier we can find (sum - num) / 2;
                
                int calc = sum - num;
    
                // only if it is even we need to do these comparisons
                if((calc % 2) == 0) {
                    int half_calc = (int) (calc / 2);       
                    // it should not be the same as number
                    // otherwise it should be recurring. the count > 1
                    if(mp.find(half_calc) != mp.end() && (half_calc != num || mp[half_calc] > 1)) {
                        res = max(res, num);
                    }
                }
                
            }
            return res;        
        }
    };

