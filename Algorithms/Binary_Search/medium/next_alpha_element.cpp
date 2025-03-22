// Given an array of letters sorted in ascending order,
// find the smallest letter in the the array which is greater than a given key
// letter. Example arr: {'a', 'b', 'c', 'd', 'g'} tgt : 'f' Ans = 'g';

#include <bits/stdc++.h>
using namespace std;

char find_next_letter(char letters[], int n, char tgt) {
  int left = 0;
  int right = n - 1;
  char ans = '#';

  while (left <= right) {
    int mid = (left + right) / 2;
    int val = letters[mid] - 'a';
    if ((tgt - 'a') < val) {
      ans = letters[mid];
      right = mid - 1;
    } else if ((tgt - 'a') > val) {
      left = mid + 1;
    }
  }
  return ans;
}

int main(int argc, char const *argv[]) {
  char letters[] = {'a', 'b', 'c', 'd', 'g'};
  char tgt = 'f';

  int n = sizeof(letters) / sizeof(letters[0]);

  cout << find_next_letter(letters, n, tgt) << endl;

  return 0;
}
