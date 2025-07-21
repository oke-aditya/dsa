// Find the Minimum Number of Fibonacci Numbers Whose Sum Is K
// https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/

// Given an integer k, return the minimum number of Fibonacci numbers whose sum
// is equal to k. The same Fibonacci number can be used multiple times.

// The Fibonacci numbers are defined as:

//     F1 = 1
//     F2 = 1
//     Fn = Fn-1 + Fn-2 for n > 2.

// It is guaranteed that for the given constraints we can always find such
// Fibonacci numbers that sum up to k.

// Example 1:

// Input: k = 7
// Output: 2
// Explanation: The Fibonacci numbers are: 1, 1, 2, 3, 5, 8, 13, ...
// For k = 7 we can use 2 + 5 = 7.

#include<vector>
using namespace std;

class Solution {
  public:
      int findMinFibonacciNumbers(int k) {
          int n = 42;
          vector<int> dp(n + 1);
          dp[0] = 1;
          dp[1] = 2;
          for(int i=2; i<=42; i++) {
              dp[i] = dp[i-1] + dp[i-2];
              // cout<<"dp i "<<dp[i];
          }
  
          // reverse(begin(dp), end(dp));
  
          int count = 0;
          while(k > 0) {
              for(int i=n; i>=0; i--) {
                  if(dp[i] <= k) {
                      k -= dp[i];
                      // cout<<k<<endl;
                      count += 1;
                      
                  }
                  
              }
          }
  
          return count;
      }
  };