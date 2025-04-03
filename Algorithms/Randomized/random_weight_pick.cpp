// https://leetcode.com/problems/random-pick-with-weight/description/

// You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.
// You need to implement the function pickIndex(), which randomly 
// picks an index in the range [0, w.length - 1] (inclusive) and returns it. 
// The probability of picking an index i is w[i] / sum(w).
// For example, if w = [1, 3], the probability of picking index 0 is 1 / (1 + 3) = 0.25 
// (i.e., 25%), and the probability of picking index 1 is 3 / (1 + 3) = 0.75 (i.e., 75%).

// Example 1:

// Input
// ["Solution","pickIndex"]
// [[[1]],[]]
// Output
// [null,0]

// Explanation
// Solution solution = new Solution([1]);
// solution.pickIndex(); // return 0. The only option is to return 0 since there is only one element in w.

// solution
// compute the total sum and the running sum
// to pick and index, choose a target number randomly generated
// now binary search for this random number (find the left lower bound)


#include <algorithm>
#include<vector>
#include<iostream>
using namespace std;


class Solution {
    public:
        vector<int> running_sum;
        int total_sum;
        
        Solution(vector<int>& w) {
            // compute sum and running sum
            int sum = 0;
    
            for(auto num: w) {
                sum += num;
                running_sum.push_back(sum);
            }
            total_sum = sum;
    
        }
        
        int pickIndex() {
            int target = rand() % total_sum + 1;
            int n = running_sum.size();
            
            cout<<" tg: "<<target<<endl;
            // int left = 0, right = running_sum.size() - 1;
    
            // while(left < right) {
            //     int mid = left + (right - left)  / 2;
    
            //     if(target > running_sum[mid]) {
            //         left = mid + 1;
            //     }
    
            //     else {
            //         right = mid - 1;
            //     }
            // }
    
            // return left;

           return lower_bound(running_sum.begin(), running_sum.end(), n) - running_sum.begin(); 
    
        }
    };
    
    /**
     * Your Solution object will be instantiated and called as such:
     * Solution* obj = new Solution(w);
     * int param_1 = obj->pickIndex();
     */

