// Bubble Sort is the simplest sorting algorithm that works by
// repeatedly swapping the adjacent elements if they are in wrong order.

#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr.size() - i - 1; i++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[i], arr[j]);
      }
    }
  }
}

void print_v(vector<int> v) {
  for (auto x : v) {
    cout << x << " ";
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  vector<int> arr = {1, -2, 3, 4, 7, 6, 5};
  print_v(arr);

  bubble_sort(arr);

  print_v(arr);

  return 0;
}
