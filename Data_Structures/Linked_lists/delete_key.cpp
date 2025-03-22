// Let us formulate the problem statement to understand the deletion process.
// Given a ‘key’, delete the first occurrence of this key in linked list.
// To delete a node from linked list, we need to do following steps.
// 1) Find previous node of the node to be deleted.
// 2) Change the next of previous node.
// 3) Free memory for the node to be deleted.

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

// Since we are modifying the linked list in place
// We will pass it by head_ref
void delete_key(Node **head_ref, int key) {
  // Traverse till you find the key
  Node *temp = *head_ref;
  Node *prev = new Node();

  // head has to be deleted.
  if (temp->data == key && temp != NULL) {
    *head_ref = temp->next;
    return;
  }

  // Otherwise to search for the key and delete it
  while (temp != NULL && temp->data != key) {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL) {
    // Key does not exist nothing is deleted.
    return;
  } else {
    prev->next = temp->next;
  }
}

void print_ln(Node *node) {
  while (node != NULL) {
    cout << node->data << " ";
    node = node->next;
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  Node *head = NULL;
  insert_head(&head, 5);
  insert_head(&head, 4);
  insert_head(&head, 3);
  insert_head(&head, 2);
  insert_head(&head, 1);

  print_ln(head);

  delete_key(&head, 3);

  print_ln(head);

  return 0;
}
