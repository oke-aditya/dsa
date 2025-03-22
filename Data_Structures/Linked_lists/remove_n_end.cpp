// Given the head of a linked list, remove the nth node from the end of the list
// and return its head.

// Follow up: Could you do this in one pass?
//
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

// Input: head = [1], n = 1
// Output: []

// Input: head = [1,2], n = 1
// Output: [1]

// Solution: -
// Create a dummy node in beginning to avoid overflow
// Move fast pointer by n steps.
// Move slow pointer and fast pointer together by n steps.
// Delete the node located at slow.
// Return temp->next as temp is attached extra to head.

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

Node *delete_at_n(Node *head, int n) {
  // Create a dummy node in beginning to avoid overflow

  Node *temp = new Node();
  temp->next = head;

  Node *fast = temp;
  Node *slow = temp;

  for (int i = 1; i <= n; i++) {
    fast = fast->next;
  }

  while (fast->next != NULL) {
    fast = fast->next;
    slow = slow->next;
  }

  slow->next = slow->next->next;

  // Return temp->next as temp is attached extra to head.
  return temp->next;
}

int main(int argc, char const *argv[]) {
  Node *head = new Node();
  head->data = 5;
  insert_head(&head, 4);
  insert_head(&head, 3);
  insert_head(&head, 2);
  insert_head(&head, 1);

  println(head);

  cout << endl;

  int n = 4;

  // delete_at_n(&head, n);
  auto head2 = delete_at_n(head, n);

  println(head2);

  cout << endl;

  return 0;
}
