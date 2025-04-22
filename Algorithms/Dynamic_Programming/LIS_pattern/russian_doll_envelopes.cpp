// https://leetcode.com/problems/russian-doll-envelopes/
// You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] 
// represents the width and the height of an envelope.
// One envelope can fit into another if and only if both the width and height 
// of one envelope are greater than the other envelope's width and height.

// Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
// Note: You cannot rotate an envelope.

// Example 1:

// Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
// Output: 3
// Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

// Example 2:

// Input: envelopes = [[1,1],[1,1],[1,1]]
// Output: 1

// Note that here LIS gets TLE. But it's fine, in an interview OK to take this
// We want to fit the boxes, so sorting boxes in ascending order and then going reverse to fit them
// [[2, 3], [5, 4], [6, 4], [6, 7]]
// On the sorted envelopes, we can see that finding LIS of [2, 3] would give us number of boxes [2, 3] can be fitted into.
// We can simply do LIS on the boxes, comparing the 0th of j andi with 1st of j and i; updating the dp array.
// LIS is O(N2) but it's fine, we can take it.

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        int maxEnvelopes(vector<vector<int>>& envelopes) {
            sort(envelopes.begin(), envelopes.end());
    
            int n = envelopes.size();
            vector<int> dp(n, 1);    
    
            for(int i=n-1; i>=0; i--) {
                for(int j=n-1; j>i; j--) {
    
                    if(envelopes[j][0] > envelopes[i][0] && envelopes[j][1] > envelopes[i][1]) {
                        dp[i] = max(dp[i], 1 + dp[j]);
                    }
                }
            }     
    
            return *max_element(begin(dp), end(dp));
    
        }
    };


