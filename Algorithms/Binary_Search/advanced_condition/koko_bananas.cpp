// // https://leetcode.com/problems/koko-eating-bananas/description/

// Koko loves to eat bananas. There are n piles of bananas, the ith pile has
// piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she
// chooses some pile of bananas and eats k bananas from that pile. If the pile
// has less than k bananas, she eats all of them instead and will not eat any
// more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas
// before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h
// hours.

// Example 1:

// Input: piles = [3,6,7,11], h = 8
// Output: 4

// Example 2:

// Input: piles = [30,11,23,4,20], h = 5
// Output: 30

#include <bits/stdc++.h>

using namespace std;

bool is_possible(vector<int> piles, int n, int mid, int h) {
  // we need to check if at this rate we can finish in h steps
  int n_steps = 0;
  // cout<<mid<<endl;

  for (int i = 0; i < n; i++) {
    int to_eat = piles[i];
    // cout<<to_eat<<endl;
    // number of steps needed to eat this one
    n_steps = n_steps + ceil((double)to_eat / mid);
    // cout<<"n_steps = "<<n_steps<<endl;
    // float calc = (to_eat / mid);
    // cout<<calc<<endl;

    if (n_steps > h) {
      return false;
    }
  }

  return true;
}

int minEatingSpeed(vector<int>& piles, int h) {
  int n = piles.size();

  // bare minimum eating speed should be a tleast one.
  int left = 1;
  int right = *max_element(begin(piles), end(piles));
  int ans = -1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    // cout<<mid<<endl;
    // if we can eat in this, we should minimize;
    if (is_possible(piles, n, mid, h)) {
      // we have an answer.
      ans = mid;
      right = mid - 1;
    }

    // otherwise we can eat at more pace.
    else {
      left = mid + 1;
    }
  }

  return ans;
}