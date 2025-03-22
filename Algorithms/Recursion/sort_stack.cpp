// Sort a stack using recursion

// Solution: -
// The idea is very simple  We recursively remove values from stack until stack
// becomes empty. Insert those values from call stack back into stack in sorted
// position.
//

#include <bits/stdc++.h>
using namespace std;

void print_stack(stack<int> s) {
  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
}

void sorted_insert(stack<int> &s, int ele) {
  // Base case. If stack is empty or key is greater than all
  if (s.empty() || ele > s.top()) {
    s.push(ele);
    return;
  }

  // If key is smaller than the top.
  // Recursively again insert

  // remove the top
  int top_ele = s.top();
  s.pop();

  // recur for remaining elements
  sorted_insert(s, ele);

  // insert popped elment into stack
  s.push(top_ele);
}

void sort_stack_rec(stack<int> &s) {
  if (s.empty()) {
    return;
  }

  // Remove the top element
  int ele = s.top();
  s.pop();

  // recur for remaining stack
  sort_stack_rec(s);

  // insert the popped element back into stack
  sorted_insert(s, ele);
}

int main(int argc, char const *argv[]) {
  vector<int> v = {-5, 2, 9, -7, 1};

  stack<int> s;
  for (int x : v) {
    s.push(x);
  }

  cout << "Stack before sorting " << endl;
  print_stack(s);

  sort_stack_rec(s);

  cout << endl << "Stack after sorting " << endl;
  print_stack(s);
  cout << endl;

  return 0;
}
