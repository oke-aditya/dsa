#include <algorithm>
#include <iostream>

using namespace std;

void print_arr(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  int arr[] = {1, 4, 5, 2, 3, 6, 7};
  int n = sizeof(arr) / sizeof(arr[0]);

  sort(arr, arr + n);

  if (binary_search(arr, arr + n, 2)) {
    cout << "Element is found";
  } else {
    cout << "Element not found";
  }

  return 0;
}
