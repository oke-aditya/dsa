
// Find the closest pair from two sorted arrays

// Given two sorted arrays and a number x, find the pair whose sum is closest to
// x and the pair has an element from each array.

// Input:  ar1[] = {1, 4, 5, 7};
//         ar2[] = {10, 20, 30, 40};
//         x = 32
// Output:  1 and 30

// Input:  ar1[] = {1, 4, 5, 7};
//         ar2[] = {10, 20, 30, 40};
//         x = 50
// Output:  7 and 40

#include <climits>
#include <cstdlib>
#include <iostream>
using namespace std;

void simple_find_closest_pair(int arr1[], int arr2[], int x) {
  // We can do it in O(n) time using following steps.
  // 1) Merge given two arrays into an auxiliary array of size m+n using merge
  // process of merge sort. While merging keep another boolean array of size m+n
  // to indicate whether the current element in merged array is from ar1[] or
  // ar2[].

  // 2) Consider the merged array and use the linear time algorithm to find the
  // pair with sum closest to x. One extra thing we need to consider only those
  // pairs which have one element from ar1[] and other from ar2[], we use the
  // boolean array for this purpose.

  return;
}

void find_closest_pair(int arr1[], int m, int arr2[], int n, int x) {
  // single pass and O(1) extra space

  //     1) Initialize a variable diff as infinite (Diff is used to store the
  //    difference between pair and x).  We need to find the minimum diff.
  //     2) Initialize two index variables l and r in the given sorted array.
  //        (a) Initialize first to the leftmost index in ar1:  l = 0
  //        (b) Initialize second  the rightmost index in ar2:  r = n-1
  //     3) Loop while  l < m and r>=0
  //        (a) If  abs(ar1[l] + ar2[r] - sum) < diff  then
  //            update diff and result
  //        (b) If (ar1[l] + ar2[r] <  sum )  then l++
  //        (c) Else r--
  //     4) Print the result.

  int l = 0;
  int left_ele = -1;
  int right_ele = -1;
  int r = n - 1;
  int diff = INT_MAX;

  while (l < m && r >= 0) {
    if (abs(arr1[l] + arr2[r] - x) < diff) {
      left_ele = arr1[l];
      right_ele = arr2[r];
      diff = abs(arr1[l] + arr2[r] - x);
    } else if (arr1[l] + arr2[r] > x) {
      r -= 1;
    } else {
      l += 1;
    }
  }
  cout << "Element in array1:  " << left_ele;
  cout << "Element in array2: " << right_ele;
  cout << "Closest sum = " << (left_ele + right_ele);
}

int main() {
  int arr1[] = {1, 4, 5, 7};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  int arr2[] = {10, 20, 30, 40};
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  int x = 32;

  find_closest_pair(arr1, n1, arr2, n2, x);

  return (0);
}
