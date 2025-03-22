// https://leetcode.com/problems/advantage-shuffle/description/
// You are given two integer arrays nums1 and nums2 both of the same length. The
// advantage of nums1 with respect to nums2 is the number of indices i for which
// nums1[i] > nums2[i].

// Return any permutation of nums1 that maximizes its advantage with respect to
// nums2.

// Example 1:

// Input: nums1 = [2,7,11,15], nums2 = [1,10,4,11]
// Output: [2,11,7,15]

// Solution: -

// Use Greedy Approach.
// Sort nums1, always find upper bound for every element in
// nums2. If it exists, that is result, otherwise the
// smallest number is result.

// To sort and find upper bound, use multiset.

#include <bits/stdc++.h>

using namespace std;

vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
  multiset<int> st(begin(nums1), end(nums1));

  vector<int> res;

  for (auto num : nums2) {
    auto p = st.upper_bound(num);
    if (p == st.end()) {
      p = st.begin();
    }
    res.push_back(*p);
    st.erase(p);
  }
  return res;
}
