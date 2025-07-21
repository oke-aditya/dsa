// https://leetcode.com/problems/find-the-middle-index-in-array/


// class Solution {
// public:
//     int findMiddleIndex(vector<int>& nums) {
//         int sum = accumulate(begin(nums), end(nums), 0);
//         int n = nums.size(), prefix_sum = 0;

//         for(int i=0; i<n; i++) {
            
//             sum -= nums[i];
//             if(prefix_sum == sum) {
//                 return i;
//             }

//             prefix_sum += nums[i];
//         }

//         return -1;

//     }
// };

