// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

// Given head which is a reference node to a singly-linked list. The value of
// each node in the linked list is either 0 or 1. The linked list holds the
// binary representation of a number.

// Return the decimal value of the number in the linked list

// Input: head = [1,0,1]
// Output: 5
// Explanation: (101) in base 2 = (5) in base 10

// Input: head = [0]
// Output: 0

// Input: head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
// Output: 18880

#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node *next;
};

void insert_head(Node **head_ref, int new_data) {
  Node *new_node = new Node();
  new_node->data = new_data;
  new_node->next = *head_ref;
  *head_ref = new_node;
}

void println(Node *node) {
  while (node != NULL) {
    cout << node->data << " ";
    node = node->next;
  }
}

// Solution

// Initialize result number to be equal to head value: num = head.val.
// This operation is safe because the list is guaranteed to be non-empty.

// Parse linked list starting from the head: while head.next:

// The current value is head.next.val.
// Update the result by shifting it by one to the left and adding the current
// value: num = num * 2 + head.next.val.

int getDecimalValue(Node *node) {
  int num = node->data;

  while (node->next != NULL) {
    num = (num * 2) + node->next->data;

    // ALternatively
    // num = (num << 1) | node->next->data;

    node = node->next;
  }

  return num;
}

int main(int argc, char const *argv[]) { return 0; }
