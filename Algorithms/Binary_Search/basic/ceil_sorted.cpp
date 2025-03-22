// Given a sorted array and a value x, the ceil of x is
// the smallest element in array larger than or equal to x.
// Write efficient functions to find ceil of x.

// Input : arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 5
// Output : 8
// 8 is the smallest element in
// arr[] larger than 5.

// Input : arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 13
// Output : 19
// 19 is the smallest element in
// arr[] larger than 20.

// Input : arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 20
// Output : -1
// Since ceil doesn't exist,
// output is -1.

#include <bits/stdc++.h>
using namespace std;

int ceil_arr(int arr[], int n, int tgt) {
  int left = 0, right = n - 1;
  int res;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (arr[mid] == tgt) {
      return arr[mid];
    } else if (tgt > arr[mid]) {
      left = mid + 1;
    } else if (tgt < arr[mid]) {
      right = mid - 1;
      res = arr[mid];
    }
  }
  return res;
}

int main(int argc, char const *argv[]) {
  int arr[] = {1, 2, 8, 10, 10, 12, 19};
  int x = 5;
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << ceil_arr(arr, n, x) << endl;

  return 0;
}
