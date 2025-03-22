// Design a Data Structure SpecialStack that supports all the
// stack operations like push(), pop(), isEmpty(), isFull() and an
// additional operation getMin() which should return minimum element from the
// SpecialStack. All these operations of SpecialStack must be O(1).
// To implement SpecialStack, you should only use standard Stack data
// structure and no other data structure like arrays, list, . etc.

// Consider the following SpecialStack
// 16  --> TOP
// 15
// 29
// 19
// 18

// When getMin() is called it should
// return 15, which is the minimum
// element in the current stack.

// If we do pop two times on stack,
// the stack becomes
// 29  --> TOP
// 19
// 18

// When getMin() is called, it should return 18
// which is the minimum in the current stack.

// Solution: -

// Use an auxiallary stack.
// This stack will store `minimum` elements from first stack.
// Top of aux stack will give minimum element.

// Push to aux stack only if the new element is greater than min of stack

// To return top, pop the element from both the stacks if we are popping a
// minimum element.

#include <bits/stdc++.h>
using namespace std;

// This is special stack that will do the job.
class SpecialStack {
 private:
  // Stack helper
  stack<int> s;
  // Auxillary stack
  stack<int> aux;

 public:
  void push(int a) {
    s.push(a);

    // If auxillary is empty
    // Or we have new minimum element
    if (aux.size() == 0 || a <= aux.top()) {
      aux.push(a);
    }
    return;
  }

  int pop() {
    // If stack is empty we can't pop
    if (s.size() == 0) {
      return -1;
    }

    // Pop element from special stack
    int ans = s.top();
    s.pop();

    // If popped element is equal to aux stack top
    if (ans == aux.top()) {
      // We pop the aux too
      aux.pop();
    }
    return ans;
  }

  // Return minimum in special stack.
  // Use aux and return top
  int getMin() {
    if (aux.size() == 0) {
      return -1;
    } else {
      return aux.top();
    }
  }
};

int main(int argc, char const *argv[]) {
  SpecialStack s;
  s.push(10);
  s.push(20);
  s.push(30);
  auto x = s.pop();
  cout << s.getMin() << endl;
  s.push(5);
  cout << s.getMin();
  cout << endl;

  return 0;
}
