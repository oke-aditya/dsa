// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
// Given an array of positive integers arr. 
// Find the maximum sum subsequence of the given array such that the integers in 
// the subsequence are sorted in strictly increasing order i.e. a strictly increasing subsequence. 

// Examples:

// Input: arr[] = [1, 101, 2, 3, 100]
// Output: 106
// Explanation: The maximum sum of a increasing sequence is obtained from [1, 2, 3, 100].

// Input: arr[] = [4, 1, 2, 3]
// Output: 6
// Explanation: The maximum sum of a increasing sequence is obtained from {1, 2, 3}.

// Solution:
// What is the base case for this dp?
// This is very similar to LIS, for the last element 100, max sum possible is number itself.
// So base condition here is the number itself, basically the same array!
// If we go reverse, if a number is smaller, we can update it's max possible increasing sum
// that would be max(dp[i], arr[i] + dp[j]) ! That number + the jth number on dp array.
// TC O(n2)
// SC O(n)


#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    public:
      int maxSumIS(vector<int>& arr) {
        // Your code goes here  
        vector<int> dp = arr;
        int n = arr.size();
        for(int i=n-1; i>=0; i--) {
            for(int j=n-1; j>i; j--) {

                if(arr[j] > arr[i]) {
                    dp[i] = max(dp[i], arr[i] + dp[j]);
                }
            }
        }
        return *max_element(begin(dp), end(dp));
    }
};

