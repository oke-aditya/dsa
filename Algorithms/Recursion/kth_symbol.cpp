// https://leetcode.com/problems/k-th-symbol-in-grammar/

// On the first row, we write a 0. Now in every subsequent row, we look
// at the previous row and replace each occurrence of 0 with 01,
// and each occurrence of 1 with 10.

// Given row N and index K, return the K-th indexed symbol in row N.
// (The values of K are 1-indexed.) (1 indexed).

// Examples:
// Input: N = 1, K = 1
// Output: 0

// Input: N = 2, K = 1
// Output: 0

// Input: N = 2, K = 2
// Output: 1

// Input: N = 4, K = 5
// Output: 1

// The whole structure can be viewed a binary tree, when a node is 0, their two
// children nodes are 0 and 1, similarly, when a node is 1, two children nodes
// are 1 and 0. We can know whether the position of K is a left node or a right
// node by dividing 2. If K is even, current node is right child, and its parent
// is the (K/2)th node in previous row; else if K is odd, current node is left
// child and its parent is the ((K+1)/2)th node in previous row.
// The value of current node depends on its parent node, without knowing its
// parent node value, we still cannot determine current node value. That's why
// we need recursion, we keep going previous row to find the parent node until
// reach the first row. Then all the parent node value will be determined after
// the recursion function returns.

#include <bits/stdc++.h>
using namespace std;

int k_symbol(int n, int k) {
  if (n == 1) {
    return 0;
  }
  if (k % 2 == 0) {
    if (k_symbol(n - 1, k / 2) == 0) {
      return 1;
    } else {
      return 0;
    }
  } else {
    if (k_symbol(n - 1, (k + 1) / 2) == 0) {
      return 0;
    } else {
      return 1;
    }
  }
}

int main(int argc, char const *argv[]) {
  int n = 4, k = 5;
  cout << endl << k_symbol(n, k);

  return 0;
}
