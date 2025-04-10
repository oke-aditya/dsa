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

bool is_possible(int eat_rate, vector<int> piles, int h) {
  // cout<<" eat_rate: "<<eat_rate<<endl;
  long long int time_taken = 0;
  for(auto num: piles) {
      time_taken = time_taken + ceil((double) num / eat_rate);
  }

  // cout<<" tk: "<<time_taken<<endl;
  // are we eating in sufficient hours?
  return (time_taken <= h);
}

int minEatingSpeed(vector<int>& piles, int h) {
  int left = 1;
  int ans = 0;
  int right = *max_element(begin(piles), end(piles));

  while(left <= right) {
      int mid = left + (right - left) / 2;

      // one possible answer
      // we need better answer, we can reduce the right
      
      if(is_possible(mid, piles, h)) {
          ans = mid;
          // cout<<"ans: "<<ans<<endl;
          right = mid - 1;
      }

      // we took more hours than intended
      // we are too slow
      else {
          left = mid + 1;
      }
  }
  return ans;
}