// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
// You are given two integer arrays nums1 and nums2 sorted in non-decreasing
// order and an integer k.

// Define a pair (u, v) which consists of one element from the first array and
// one element from the second array.

// Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

// Example 1:

// Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
// Output: [[1,2],[1,4],[1,6]]
// Explanation: The first 3 pairs are returned from the sequence:
// [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    priority_queue<pair<int, pair<int, int>>> maxh;

    int m = nums1.size();
    int n = nums2.size();

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            int sum = nums1[i] + nums2[j];

            if(maxh.size() < k) {
                maxh.push({sum, {nums1[i], nums2[j]}});
            }

            else if(sum < maxh.top().first) {
                maxh.push({sum, {nums1[i], nums2[j]}});
                maxh.pop();
            }
            else {
                break;
            }
            
        }
    }

    vector<vector<int>> res;

    while(!maxh.empty()) {
        vector<int> temp;
        temp.push_back(maxh.top().second.first);
        temp.push_back(maxh.top().second.second);
        res.push_back(temp);
        maxh.pop();
    }

    return res;

}


int main(int argc, char const* argv[]) {
  vector<int> nums1 = {1, 7, 11};
  vector<int> nums2 = {2, 4, 6};
  int k = 3;

  auto res = kSmallestPairs(nums1, nums2, k);
  // int s = 1;
  // auto ind = binary_search(s, nums1);

  return 0;
}
