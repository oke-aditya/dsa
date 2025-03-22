// You're given strings jewels representing the types of stones that are jewels,
// and stones representing the stones you have. Each character in stones is a
// type of stone you have. You want to know how many of the stones you have are
// also jewels.

// Letters are case sensitive, so "a" is considered a different type of stone
// from "A".

// https://leetcode.com/problems/jewels-and-stones/

// Input: jewels = "aA", stones = "aAAbbbb"
// Output: 3

// Input: jewels = "z", stones = "ZZ"
// Output: 0

// Form a hashmap mapping all jewels
// For every stone character check if it exists in jewels.

#include <bits/stdc++.h>
using namespace std;

int jew_stones(string jewels, string stones) {
  map<char, int> mp;

  for (int i = 0; i < jewels.length(); i++) {
    mp[jewels[i]] += 1;
  }

  int count = 0;

  for (int i = 0; i < stones.length(); i++) {
    if (mp[stones[i]] > 0) {
      count += 1;
    }
  }

  return count;
}

int main(int argc, char const *argv[]) {
  string jewels1 = "aA";
  string stones1 = "aAAbbbb";

  string jewels2 = "z";
  string stones2 = "ZZ";

  cout << jew_stones(jewels1, stones1);
  cout << jew_stones(jewels2, stones2);

  return 0;
}
