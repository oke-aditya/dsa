// We are given a Queue data structure that supports
// standard operations like enqueue() and dequeue().
// We need to implement a Stack data structure
// using only instances of Queue and queue operations allowed on the instances.

// Using two queues and making push function costly

#include <bits/stdc++.h>
using namespace std;

class Stack {
  // Two Queues
  queue<int> q1, q2;

 public:
  // Insert item to stack
  void push(int data) {
    // Move all elements from first queue to second queue
    while (!q1.empty()) {
      q2.push(q1.front());
      q1.pop();
    }

    // Push the given item to front of queue
    q1.push(data);

    // Move all items back
    while (!q2.empty()) {
      q1.push(q2.front());
      q2.pop();
    }
  }

  // Pop an item from the stack
  int pop() {
    // Remove the front of queue
    if (q1.empty()) {
      cout << "[Error] Popping from empty queue " << endl;
      return -1;
    }

    int ele = q1.front();
    q1.pop();

    return ele;
  }
};

int main(int argc, char const *argv[]) {
  Stack s;
  s.push(2);
  s.push(4);
  s.push(3);
  cout << s.pop() << endl;
  cout << s.pop() << endl;

  return 0;
}
