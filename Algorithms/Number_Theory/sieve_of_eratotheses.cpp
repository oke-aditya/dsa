#include <iostream>
using namespace std;

void print_arr(int arr[], int n) {
  for (int i = 0; i < n; i++)
    if (arr[i] == 1) {
      cout << i << " ";
    }
}

void sieve(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    // Assigning that entire array is filled up with primes
    arr[i] = 1;
  }
  // We know this
  arr[0] = 0;
  arr[1] = 0;

  // Applying sieve which whil pick every number below sqrt(n) and find its
  // factors Then mark it's factors which are composite

  for (int i = 2; i * i <= n; i++) {
    if (arr[i] == 1)  // If it is a composite number then mark all its factors
                      // as composite
    {
      for (int j = i * i; j <= n; j += i) {
        arr[j] = 0;
      }
    }
  }

  print_arr(arr, n);
}

int main() {
  int arr[101];
  int n = sizeof(arr) / sizeof(arr[0]);
  sieve(arr, n);
  return (0);
}
