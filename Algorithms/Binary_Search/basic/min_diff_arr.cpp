// Given a sorted array,
// find the element in the array which has minimum difference with the given
// number.

// Solution: -
// Find the floor.
// Find the ceiling.
// Compare the abs() difference of both with the given number.

#include <bits/stdc++.h>
using namespace std;

int find_floor(int arr[], int n, int tgt) {
  int left = 0, right = n - 1, res;
  while (left <= right) {
    int mid = (left + right) / 2;

    if (tgt == arr[mid]) {
      return 0;
    } else if (tgt > arr[mid]) {
      // Move right
      res = arr[mid];
      left = mid + 1;
    } else if (tgt < arr[mid]) {
      // Move left
      right = mid - 1;
    }
  }
  return res;
}

int find_ceil(int arr[], int n, int tgt) {
  int left = 0, right = n - 1, res;
  while (left <= right) {
    int mid = (left + right) / 2;

    if (tgt == arr[mid]) {
      return 0;
    } else if (tgt > arr[mid]) {
      // Move right
      left = mid + 1;
    } else if (tgt < arr[mid]) {
      // Move left
      res = arr[mid];
      right = mid - 1;
    }
  }
  return res;
}

int min_diff_arr(int arr[], int n, int tgt) {
  // Find floor, find ceiling.
  // Minimum difference is minimum of those two.
  int floor = find_floor(arr, n, tgt);
  int ceil = find_ceil(arr, n, tgt);

  cout << floor << " " << ceil << endl;

  int min_diff = min(abs((tgt - floor)), abs((tgt - ceil)));

  return min_diff;
}

int main(int argc, char const *argv[]) {
  int arr[] = {1, 4, 5, 12, 34, 53, 111};
  int n = sizeof(arr) / sizeof(arr[0]);
  int tgt = 10;

  cout << min_diff_arr(arr, n, tgt) << endl;

  return 0;
}
