// Implement Queue using Stacks

#include <iostream>
#include <stack>

using namespace std;

// Method 1 (By making enQueue operation costly)
// This method makes sure that oldest entered element is always at the top of
// stack 1, so that deQueue operation just pops from stack1. To put the element
// at top of stack1, stack2 is used.

// enQueue(q, x):
// While stack1 is not empty, push everything from stack1 to stack2.
// Push x to stack1 (assuming size of stacks is unlimited).
// Push everything back to stack1.

// deQueue(q):

// If stack1 is empty then error
// Pop an item from stack1 and return it

struct Queue {
  stack<int> s1, s2;

  void enqueue(int x) {
    while (!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }
    // Push to s1
    s1.push(x);

    // Push overyrhing back to stack1
    while (!s2.empty()) {
      s1.push(s2.top());
      s2.pop();
    }
  }
  int dequeue() {
    if (s1.empty()) {
      cout << "Cannot dequeue empty queue";
      return -1;
    }
    int x = s1.top();
    s1.pop();
    return x;
  }
};

int main(int argc, char const *argv[]) {
  Queue q1;
  q1.enqueue(1);
  q1.enqueue(2);
  q1.enqueue(3);

  cout << endl << q1.dequeue();
  cout << endl << q1.dequeue();
  cout << endl << q1.dequeue();

  return 0;
}
