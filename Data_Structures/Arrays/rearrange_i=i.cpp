// Given an array of elements of length N, ranging from 0 to N ? 1.
// All elements may not be present in the array.
// If element is not present then there will be -1 present in the array.
// Rearrange the array such that A[i] = i and if i is not present, display -1 at
// that place.

// Input : arr = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1}
// Output : [-1, 1, 2, 3, 4, -1, 6, -1, -1, 9]

// Input : arr = {19, 7, 0, 3, 18, 15, 12, 6, 1, 8,
//               11, 10, 9, 5, 13, 16, 2, 14, 17, 4}
// Output : [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
//          11, 12, 13, 14, 15, 16, 17, 18, 19]

#include <iostream>
#include <set>
using namespace std;

void print_arr(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

void rearrange_simple(int arr[], int n) {
  int new_arr[n];
  int count = 0;
  int fg = 1;
  while (count < n) {
    if (arr[count] != count) {
      fg = 1;
      // Search for it
      for (int i = 0; i < n; i++) {
        if (arr[i] == count) {
          // found it, use it
          new_arr[count] = count;
          fg = 0;
          count += 1;
        }
      }
      if (fg == 1) {
        new_arr[count] = -1;
        count += 1;
      }
    } else {
      new_arr[count] = count;
      count += 1;
    }
  }
  print_arr(new_arr, n);
}

void rearrange_hashmap(int arr[], int n) {
  // Initializing set from an array
  set<int> s1(arr, arr + n);
  // Checking if item is in set.
  for (int i = 0; i < n; i++) {
    int search = i;
    if (s1.count(search)) {
      arr[i] = i;
    } else {
      arr[i] = -1;
    }
  }
  print_arr(arr, n);
}

void swap_rearrange(int arr[], int n) {
  // 1) Iterate through elements in array
  // 2) If arr[i] >= 0 && arr[i] != i, put arr[i] at i ( swap arr[i] with
  // arr[arr[i]])
  for (int i = 0; i < n; i++) {
    if (arr[i] >= 0 && arr[i] != i) {
      swap(arr[i], arr[arr[i]]);
    } else {
      i++;
    }
  }
  print_arr(arr, n);
}

int main() {
  int arr[] = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
  int n = sizeof(arr) / sizeof(arr[0]);
  //    rearrange_simple(arr, n);
  rearrange_hashmap(arr, n);
}
