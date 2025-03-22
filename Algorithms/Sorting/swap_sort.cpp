// Given numbers 1 to N in an array.
// Some numbers are missing, some numbers are repeating.
// We need to find which numbers are missing and which are duplicate.

#include <bits/stdc++.h>
using namespace std;

void print_v(vector<int> v) {
  for (auto x : v) {
    cout << x << " ";
  }
}

// Approach 1:
// Hashamp
// Create a hashmap which will store numbers from 1 to N.
// Count of each of these numbers is 0 initially.
// Iterate through the array and increase count of numbers.
// If count of number is 0, it is missing,
// if it is > 1 the number is duplicate.

void find_dup_miss_map(vector<int> v) {
  unordered_map<int, int> mp;
  int n = v.size();

  for (int i = 1; i <= n; i++) {
    mp[i] = 0;
  }

  for (int i = 0; i < v.size(); i++) {
    mp[v[i]] += 1;
  }

  // If element in map occurs 0 times it is missing.
  // If it occurs more that 1 it is duplicate

  vector<int> miss;
  vector<int> dup;
  for (auto itr = mp.begin(); itr != mp.end(); itr++) {
    // Second is value of map.
    if (itr->second == 0) {
      // Missing elmeent.
      miss.push_back(itr->first);
    }
    // Multiple times
    if (itr->second > 1) {
      dup.push_back(itr->second);
    }
  }
  cout << "Missing elements are: ";
  print_v(miss);
  cout << endl;
  cout << "Duplicate elements are: ";
  print_v(dup);
  cout << endl;
}

// Approach 2
// Swap elements and sort them in order such that
// ith index of array contains element with value i + 1
// If ith index contains value which is not i + 1
// i is the missing number and arr[i] which is i + 1 is duplicate number
// E.g. given array will be converted to
// [1, 2, 3, 6, 5, 6, 7, 8, 7, 10]
// So 4th position does not have correct value hence 6 is repeated.
// Hence 7 is also repeated in 9th position.
//  And we can see that 4 is missing and 9 is missing

void dup_miss_swap(vector<int> v) {
  // Finds duplicate and missing using swap sort logic.
  int n = v.size();

  int i = 0;
  while (i < n) {
    // If element in current position is not equal to expected
    // Expected element at ith position is v[i] - 1
    if (v[i] != v[v[i] - 1]) {
      // Swap it to correct position
      swap(v[i], v[v[i] - 1]);
    } else {
      // Element is at correct place we can move ahead.
      i += 1;
    }
  }

  // Now Post process this array.
  print_v(v);
  cout << endl;

  for (int i = 0; i < v.size(); i++) {
    // current element is not in its correct place
    if (v[i] != i + 1) {
      cout << "Missing " << (i + 1) << endl;
      cout << "Duplicate " << v[i] << endl;
    }
  }
}

int main(int argc, char const *argv[]) {
  vector<int> v1 = {2, 3, 1, 5, 7, 7, 8, 6, 6, 10};
  find_dup_miss_map(v1);
  cout << endl;
  dup_miss_swap(v1);
  cout << endl;
  return 0;
}
