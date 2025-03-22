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

// Use only O(1) space, no auxillary stack / space is allowed

// Solution: -

// Use a variable to keep track of minimum element.
// In stack push back (2 * ele - min). This would indicate there is some anamoly
// in stack. While popping if we find such anamoly (element > min). Then we will
// re compute back the element.

#include <bits/stdc++.h>
using namespace std;

// This is special stack that will do the job.
class SpecialStack {
 private:
  int min;
  stack<int> s;

 public:
  void push(int ele) {
    // No element in stack
    if (s.size() == 0) {
      s.push(ele);
      min = ele;
    }

    else {
      if (ele >= min) {
        // Bigger element.
        s.push(ele);
      }

      // If it is smaller than min
      else {
        // We push 2 * ele - min
        s.push((2 * ele) - min);
        min = ele;
      }
    }
  }

  // This return minimum element in stack
  int top() {
    if (s.size() == 0) {
      // There is no element
      return -1;
    } else {
      // Element on top is >
      if (s.top() >= min) {
        return s.top();
      }
      // We would need to return min;
      else {
        return min;
      }
    }
  }

  // Remove element from stack
  void pop() {
    if (s.size() == 0) {
      // Can't pop an empty stack.
      cout << "error" << endl;
      return;
    } else {
      // If top is greater, we can safely pop
      if (s.top() >= min) {
        s.pop();
      } else if (s.top() < min) {
        // We need to recompute back
        min = (2 * min) - s.top();
        s.pop();
      }
    }
  }

  int getMin() {
    if (s.size() == 0) {
      return -1;
    } else {
      return min;
    }
  }
};

int main(int argc, char const *argv[]) {
  SpecialStack s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.pop();
  cout << s.getMin() << endl;
  s.push(5);
  cout << s.getMin() << endl;
  return 0;
}
