// https://leetcode.com/problems/combination-sum/description/

// Given an array of distinct integers candidates and a target integer target,
// return a list of all unique combinations of candidates where the chosen
// numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times.
// Two combinations are unique if the frequency of at least one of the chosen
// numbers is different.

// The test cases are generated such that the number of unique combinations that
// sum up to target is less than 150 combinations for the given input.

// Example 1:

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple
// times. 7 is a candidate, and 7 = 7. These are the only two combinations.

// Example 2:

// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]

// Example 3:

// Input: candidates = [2], target = 1
// Output: []

// Note that we can pick multiple times the same number
// We will need an extra temp array because we cannot do operations in place
// We will backtrack the solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void backtrack(vector<int> &candidates, int start, int target,
                 vector<int> &temp, vector<vector<int>> &res) {
    // If target goes -ve. Discard the result, don't take it in res;
    if (target < 0) {
      return;
    }

    // if we hit the target we have found a result
    if (target == 0) {
      res.push_back(temp);
      // we need to return since we don't need duplicates
      return;
    }

    // for all the choices from start coz of recursive calls
    for (int i = start; i < candidates.size(); i++) {
      // if(i > start && (candidates[i] == candidates[i-1]))
      // {
      //     // no recerse
      //     continue;
      // }

      // backtrack by reducing target.
      // take them in temp as possible result;
      temp.push_back(candidates[i]);

      // backtrack reducing target, we can take again
      backtrack(candidates, i, target - candidates[i], temp, res);
      // undo backtrack
      temp.pop_back();
    }
  }

  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> temp;
    int start = 0;
    sort(candidates.begin(), candidates.end());
    backtrack(candidates, start, target, temp, res);

    return res;
  }
};
