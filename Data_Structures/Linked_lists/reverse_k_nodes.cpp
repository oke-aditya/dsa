// Reverse Nodes in k-Group
// https://leetcode.com/problems/reverse-nodes-in-k-group/

// Given a linked list, reverse the nodes of a linked list k at a time and
// return its modified list.

// k is a positive integer and is less than or equal to the length of the linked
// list. If the number of nodes is not a multiple of k then left-out nodes, in
// the end, should remain as it is.

// Follow up:

//     Could you solve the problem in O(1) extra memory space?
//     You may not alter the values in the list's nodes, only nodes itself may
//     be changed.

// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]

// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]

// Input: head = [1,2,3,4,5], k = 1
// Output: [1,2,3,4,5]

// Input: head = [1], k = 1
// Output: [1]

// Solution: -
// Add dummy to the head.
// Find length of linked list.
// Keep ptrs, prev, forw, curr.
// curr is ahead of prev. fowr is ahead of curr.
// Reverse the connects.
// Previous becomes current.
// Decrease count by k

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
  cout << endl;
}

Node *reverse_k(Node *head, int k) {
  // Edge case
  if (head == NULL || k == 1) {
    return head;
  }

  // Point a dummy to the head
  Node *dummy = new Node();
  dummy->next = head;

  // Length of list.
  int count = 0;

  Node *curr = dummy, *forw = dummy, *prev = dummy;

  // Find length of linked list
  while (curr->next != NULL) {
    curr = curr->next;
    count += 1;
  }

  while (count >= k) {
    // Current is ahed of prev (at start it is ahead of dummy)
    curr = prev->next;

    // Forward is ahead of current.
    forw = curr->next;

    // We need 1 less iteration since we have dummy.
    for (int i = 1; i < k; i++) {
      // Basically reverse the list
      curr->next = forw->next;
      forw->next = prev->next;

      prev->next = forw;
      forw = curr->next;
    }

    // Previous is new current
    prev = curr;
    count -= k;
  }

  // Return next of dummy.
  return dummy->next;
}

int main(int argc, char const *argv[]) {
  Node *head = NULL;

  insert_head(&head, 5);
  insert_head(&head, 4);
  insert_head(&head, 3);
  insert_head(&head, 2);
  insert_head(&head, 1);

  println(head);

  int k = 2;
  auto res = reverse_k(head, k);

  println(res);

  return 0;
}
