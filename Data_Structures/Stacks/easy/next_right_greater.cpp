
// Given an array, print the Next Greater Element (NGE) to right for every
// element. The Next greater Element for an element x is the first greater
// element on the right side of x in array. Elements for which no greater
// element exist, consider next greater element as -1.

// Solution: -
//
// Traverse array right to left (opposite)
// If stack is empty
//
// Given an array, print the Next Greater Element (NGE) for every element. The
// Next greater Element for an element x is the first greater element on the
// right side of x in array. Elements for which no greater element exist,
// consider next greater element as -1.
//
// Examples:
//
// For any array, rightmost element always has next greater element as -1.
// For an array which is sorted in decreasing order, all elements have next
// greater element as -1. For the input array [4, 5, 2, 25}, the next greater
// elements for each element are as follows. [5, 25, 25, -1]

#include <bits/stdc++.h>
using namespace std;

vector<int> nr_g(int arr[], int n) {
  vector<int> res;
  int fg;
  for (int i = 0; i < n; i++) {
    fg = 1;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] > arr[i]) {
        res.push_back(arr[j]);
        fg = 0;
        break;
      }
    }
    if (fg) res.push_back(-1);
  }

  return res;
}

vector<int> nr_g2(int arr[], int n) {
	stack<int> stk;
	vector<int> res;
	for(int i=n-1; i>=0; i--) {
		while(!stk.empty() && arr[i] >= stk.top()) {
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
	

void print_v(vector<int> v) {
  for (auto x : v) {
    cout << x << " ";
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  int arr[] = {11, 13, 21, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  // nge_naive(arr, n);
  // cout<<endl;

  auto res = nr_g2(arr, n);
  print_v(res);

  return 0;
}
