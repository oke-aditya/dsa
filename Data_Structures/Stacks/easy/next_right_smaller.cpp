// Given an array of integers, find the closest smaller on right of every
// element. If an element has no smaller on the right side, print -1.

// E.g. array {11, 8, 3, 44};
// Output is [8, 3, -1, -1]

#include <bits/stdc++.h>
using namespace std;

vector<int> nse_naive(int arr[], int n) {
  vector<int> res;
  for (int i = 0; i < n; i++) {
    int fg = 1;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[i]) {
        res.push_back(arr[j]);
        fg = 0;
      }
    }
    if (fg) {
      res.push_back(-1);
    }
  }
  return res;
}

void print_v(vector<int> v) {
  for (auto x : v) {
    cout << x << " ";
  }
}

vector<int> nr_s(int arr[], int n) {
	stack<int> stk;
	vector<int> res;
	for(int i=n-1; i>=0; i--) {
		while(!stk.empty() && arr[i] <= stk.top()) {
			stk.pop();
		}
		
		if(stk.empty()) {
			res.push_back(-1);
		}
		
		else {
			res.push_back(stk.top());
		}
		
		stk.push(arr[i]);
	}
  reverse(begin(res), end(res));
  return res;
}

int main(int argc, char const *argv[]) {
  int arr[] = {11, 8, 3, 44};
  int n = sizeof(arr) / sizeof(arr[0]);

  auto res = nse_naive(arr, n);
  print_v(res);

  auto res2 = nr_s(arr, n);

  print_v(res2);

  return 0;
}
