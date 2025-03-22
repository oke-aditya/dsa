
// Two Pointers Technique

// Two pointers is really an easy and
// effective technique which is typically
// used for searching pairs in a sorted array.

// Given a sorted array A (sorted in ascending order),
// having N integers,
// find if there exists any pair of
// elements (A[i], A[j]) such that their sum is equal to X.

#include <iostream>
using namespace std;

bool check_sum_naive(int arr[], int n, int x) {
  // The time complexity of this solution is O(n2).
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i] + arr[j] == x) {
        return (true);
      }
      if (arr[i] + arr[j] > x) {
        break;
      }
    }
  }
  return (false);
}

bool check_sum_opt(int arr[], int n, int x) {
  // The above solution works in O(n)
  int i = 0;
  int j = n - 1;
  while (i < j) {
    if (arr[i] + arr[j] == x) {
      return (true);
    } else if (arr[i] + arr[j] < x) {
      i += 1;
    } else {
      j -= 1;
    }
  }
  // If we do not find anything worthwile.
  return (false);
}

int main() {
  int arr[] = {10, 20, 35, 50, 75, 80};
  int n = sizeof(arr) / sizeof(arr[0]);
  int x = 55;
  auto truth = check_sum_opt(arr, n, x);
  if (truth) {
    cout << "Sum is found";
  } else {
    cout << "Sum not found";
  }

  return (0);
}
