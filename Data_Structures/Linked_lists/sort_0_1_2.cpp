// Sort linked list containing 0’s, 1’s, and 2’s in a single traversal

// Input:
// 0 -> 1 -> 2 -> 0 -> 1 -> 2 -> 2 -> 0 -> 1

// Output:
// 0 -> 0 -> 0 -> 1 -> 1 -> 1 -> 2 -> 2 -> 2

// Solution 1: -

// Simple solution is to count number of 0s, 1s and 2s.
// Traverse the list and put them back in order.
// We need 2 passes.

// Solution 2 : -

// Single traversal
// Maintain three pointers, zeros, ones and twos.
// Traverse the list from head to end.
// Move node corresponding list depending on value.
// Combine all three linked lists, and fix head.

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

void sort_list(Node **head) {
  if (*head == NULL || ((*head)->next) == NULL) {
    return;
  }

  // Maintain 3 dummy nodes
  Node *Zero = new Node();
  Node *One = new Node();
  Node *Two = new Node();

  Node *zero = Zero, *one = One, *two = Two, *curr = *head;

  while (curr != NULL) {
    if (curr->data == 0) {
      zero->next = curr;
      zero = zero->next;
    }

    else if (curr->data == 1) {
      one->next = curr;
      one = one->next;
    }

    else {
      two->next = curr;
      two = two->next;
    }

    curr = curr->next;
  }

  // Combine one two and three
  if (One->next != NULL) {
    zero->next = One->next;
  } else {
    zero->next = Two->next;
  }

  one->next = Two->next;
  two->next = NULL;
  *head = Zero->next;
}

int main(int argc, char const *argv[]) {
  Node *head = NULL;
  insert_head(&head, 2);
  insert_head(&head, 1);
  insert_head(&head, 1);
  insert_head(&head, 0);
  insert_head(&head, 2);
  insert_head(&head, 2);
  insert_head(&head, 0);
  insert_head(&head, 0);
  insert_head(&head, 1);

  println(head);

  sort_list(&head);

  println(head);

  return 0;
}
