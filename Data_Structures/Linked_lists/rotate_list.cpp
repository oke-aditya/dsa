// https://leetcode.com/problems/rotate-list/description/

// Given the head of a linked list, rotate the list to the right by k places.

// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]

// Input: head = [0,1,2], k = 4
// Output: [2,0,1]

// Solution: -
// Naive approach
// For N times.
// Traverse the last element, attach it to head.
// Remove connection from second last element.
//

// Optimal approach.
// Find length of linked list.
//
//

// Followup
// Shift linked list, rotate to left.
// We can still solve with same logic
// Rotation to right = length - rotation to left.
// Continue in same way.

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

Node *rotate_list(Node *head, int k) {
  if (head == NULL || head->next == NULL || k == 0) {
    return head;
  }

  // Compute length of linked list.
  Node *temp = head;
  // We keep length as 1.
  int length = 1;

  // We want to traverse till last node.
  while (temp->next != NULL) {
    length += 1;
    temp = temp->next;
  }

  // We are at the last node. Link it to first.
  temp->next = head;
  // Modulo operator, since, k > length ops have no effect.
  k = k % length;
  // We need to patch this position.
  k = length - k;

  while (k--) {
    // Bring temp to this place.
    temp = temp->next;
  }

  // Make this node as head and break the connection.
  head = temp->next;
  temp->next = NULL;

  return head;
}

void println(Node *node) {
  while (node != NULL) {
    cout << node->data << " ";
    node = node->next;
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  Node *head = new Node();
  insert_head(&head, 5);
  insert_head(&head, 4);
  insert_head(&head, 3);
  insert_head(&head, 2);
  insert_head(&head, 1);

  println(head);

  int k = 2;

  auto res = rotate_list(head, k);

  println(res);

  return 0;
}
