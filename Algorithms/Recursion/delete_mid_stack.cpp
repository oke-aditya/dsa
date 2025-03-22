// Delete middle element of stack using Recursion

#include <bits/stdc++.h>
using namespace std;

void delete_mid(stack<int> &s, int n, int curr = 0) {
  // if stack is empty or all items are traversed.
  if (s.empty() || curr == n) {
    return;
  }

  // Remove current item
  int temp = s.top();
  s.pop();

  // remove other items
  delete_mid(s, n, curr + 1);

  // Put all items back except middle
  if (curr != (n / 2)) {
    s.push(temp);
  }
}

void print_st(stack<int> s) {
  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  s.push(6);
  s.push(7);

  cout << "Stack before deleting: ";
  print_st(s);

  delete_mid(s, s.size());

  cout << "Stack after deleting mid ";
  print_st(s);

  return 0;
}
