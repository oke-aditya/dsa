// https://leetcode.com/problems/longest-consecutive-sequence/
// Given an unsorted array of integers nums, return the length of the longest
// consecutive elements sequence.

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
// Therefore its length is 4.

// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9
// Explaination: Longest sequence = 0, 1, 2, 3, 4, 5, 6, 7, 8.

#include <bits/stdc++.h>
using namespace std;

int longest_cons_seq_brute(vector<int> nums) {
  // Simple sorting solution.
  if (nums.size() == 0) {
    return 0;
  }

  sort(begin(nums), end(nums));
  int current_streak = 1;
  int max_streak = 0;

  int n = nums.size();

  for (int i = 1; i < n; i++) {
    // same numbers don't do anything
    if (nums[i] == nums[i - 1]) {
      continue;
    }

    // add to streak
    if (nums[i] == nums[i - 1] + 1) {
      current_streak += 1;
    }

    // new result and reset the streak
    else {
      max_streak = max(max_streak, current_streak);
      current_streak = 1;
    }
  }

  // finally if we have a remaining streak
  max_streak = max(max_streak, current_streak);

  return max_streak;
}

int longest_cons_seq_opt(vector<int> v) {
  // Optimized O(n) solution.
  // We only attempt to build sequences from numbers that
  // are not already part of a longer sequence.
  // This is accomplished by first ensuring that the number that
  // would immediately precede the current number in a sequence is not
  // present, as that number would necessarily be part of a longer sequence.

  // Store each number in set to keep unique counts.
  set<int> hashset;
  for (auto ele : v) {
    hashset.insert(ele);
  }

  int max_streak = 0, current_streak;

  // For every element check if ele - 1 is present.
  for (auto ele : v) {
    if (!hashset.count(ele - 1)) {
      int current_num = ele;
      // Reset the streak
      current_streak = 1;

      while (hashset.count(current_num + 1)) {
        current_num += 1;
        current_streak += 1;
      }
      max_streak = max(current_streak, max_streak);
    }
  }
  return max_streak;
}

int main(int argc, char const *argv[]) {
  vector<int> v = {100, 4, 101, 1, 3, 2};
  auto res = longest_cons_seq_brute(v);
  cout << res << endl;

  auto res2 = longest_cons_seq_opt(v);
  cout << res2 << endl;

  return 0;
}
