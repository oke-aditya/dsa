// Given an array of integers, find the closest
// greater on left of every element.
// If an element has no greater on the left side, print -1.
// E.g. array {11, 13, 21, 3};
// Output will be {-1, -1, -1, 21}

#include <bits/stdc++.h>
using namespace std;

vector<int> nl_g_naive(int arr[], int n) {
  vector<int> res;
  for (int i = n - 1; i >= 0; i--) {
    int fg = 1;
    for (int j = i - 1; j >= 0; j--) {
      if (arr[j] > arr[i]) {
        res.push_back(arr[j]);
        fg = 0;
        break;
      }
    }
    if (fg) {
      res.push_back(-1);
    }
  }
  reverse(begin(res), end(res));
  return res;
}

vector<int> nl_g(int arr[], int n) {
  stack<int> stk;
  vector<int> res;

  for (int i = 0; i < n; i++) {
    if (stk.empty()) {
      res.push_back(-1);
    }

    if (!stk.empty() && stk.top() > arr[i]) {
      res.push_back(stk.top());
    }

    else if (!stk.empty() && stk.top() <= arr[i]) {
      while (!stk.empty() && stk.top() <= arr[i]) {
        stk.pop();
      }

      if (stk.empty()) {
        res.push_back(-1);
      } else {
        res.push_back(stk.top());
      }
    }

    stk.push(arr[i]);
  }
  return res;
}

void print_v(vector<int> v) {
  for (auto x : v) {
    cout << x << " ";
  }
}

int main(int argc, char const *argv[]) {
  int arr[] = {11, 13, 21, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  nl_g_naive(arr, n);
  cout << endl;

  auto res = nl_g(arr, n);
  print_v(res);

  return 0;
}
