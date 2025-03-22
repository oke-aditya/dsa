// Implement next permutation, which rearranges numbers into the
// lexicographically next greater permutation of numbers.

// If such an arrangement is not possible, it must rearrange it as the lowest
// possible order (i.e., sorted in ascending order).

// The replacement must be in place and use only constant extra memory.

// Input: nums = [1,2,3]
// Output: [1,3,2]

// Input: nums = [1,1,5]
// Output: [1,5,1]

// Input: nums = [3,2,1]
// Output: [1,2,3]

// Input: nums = [1,3,5,4,2]
// Output: [1,4,2,3,5]

// Solution: -
// 3 pass algorithm.
// Breakpoint element is decreasing element from reverse order.
// In first pass find the index that needs to be swapped. The breakpoint.
// In second pass identify element just greater than element at breakpoint.
// In third pass, reverse the reamining elmeents.

#include <bits/stdc++.h>
using namespace std;

void print_v(vector<int> v) {
  for (auto x : v) {
    cout << x << " ";
  }
  cout << endl;
}

void next_perm(vector<int> &v) {
  // In built function
  // next_permutation(v.begin(), v.end());
  int n = v.size(), i, j;
  for (i = n - 2; i >= 0; i--) {
    if (v[i + 1] > v[i]) {
      break;
    }
  }
  // No breakpoint found, we are in correct order.
  if (i < 0) {
    reverse(v.begin(), v.end());
  } else {
    // Find the element that is just greater than breakpoint index.
    for (j = n - 1; j > i; j--) {
      if (v[j] > v[i]) {
        break;
      }
    }
    // We need to swap these two elements
    swap(v[j], v[i]);
    // Reverse the remaining elements.
    reverse(v.begin() + i + 1, v.end());
  }
}

int main(int argc, char const *argv[]) {
  vector<int> v = {1, 3, 5, 4, 2};
  next_perm(v);
  print_v(v);

  return 0;
}
