// https://leetcode.com/problems/first-bad-version/

// You are a product manager and currently leading a team to develop a new
// product

// Unfortunately, the latest version of your product fails the quality check
// Since each version is developed based on the previous version, all the
// versions after a bad version are also bad.

// Suppose you have n versions [1, 2, ..., n] and you want to find out the first
// bad one, which causes all the following ones to be bad.

#include <bits/stdc++.h>

using namespace std;

bool isBadVersion(int version);

int firstBadVersion(int n) {
  int left = 1;
  int right = n;
  int ans = -1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (isBadVersion(mid)) {
      // one possible ans;
      // there can be bad versions after it, but we don't care
      ans = mid;
      right = mid - 1;
    }

    // since this is not bad version, bad version can only be on right
    // a version after this is only bad, shift left bound
    else {
      left = mid + 1;
    }
  }
  return ans;
}
