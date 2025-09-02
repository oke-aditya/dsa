// You are given an integer array nums. The unique elements of an array are the
// elements that appear exactly once in the array.

// Return the sum of all the unique elements of nums.

// https://leetcode.com/problems/sum-of-unique-elements/

// Input: nums = [1,2,3,2]
// Output: 4
// Explanation: The unique elements are [1,3], and the sum is 4.

// Form a hashmap of all the nums
// Check if num count is = 1 is hashmap add it.

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int uniq_sum(vector<int> nums) {
  // Map to store value and count
  map<int, int> mp;

  for (int i = 0; i < nums.size(); i++) {
    mp[nums[i]] += 1;
  }

  // Add the sum
  int sum = 0;

  for (int i = 0; i < nums.size(); i++) {
    if (mp[nums[i]] == 1) {
      sum += nums[i];
    }
  }

  return sum;
}

// one pass algo

int uniq_sum2(vector<int> nums) {
  unordered_map<int, int> mp;
  int sum = 0;

  for(int i=0; i<nums.size(); i++) {
    if(mp.find(nums[i]) == mp.end()) {
      sum += nums[i];
    }
    else {
      mp[nums[i]] += 1;
    }
  }

  return sum;

}


int main(int argc, char const *argv[]) {
  vector<int> nums = {1, 2, 3, 2};

  cout << uniq_sum(nums);

  return 0;
}
