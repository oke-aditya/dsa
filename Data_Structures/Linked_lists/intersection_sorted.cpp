// Given two lists sorted in increasing order,
// create and return a new list representing the intersection of the two lists.
// The new list should be made with its own memory — the original lists should
// not be changed.

// For example, let the first linked list be 1->2->3->4->6 and second linked
// list be 2->4->6->8, then your function should create and return a third list
// as 2->4->6.

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

void print_ln(Node *node) {
  while (node != NULL) {
    cout << node->data << " ";
    node = node->next;
  }
  cout << endl;
}

// The strategy here uses a temporary dummy node as the
// start of the result list.
// The pointer tail always points to the last node
// in the result list, so appending new nodes is easy.
// The dummy node gives tail something to point
// to initially when the result list is empty.
// This dummy node is efficient, since it is only
// temporary, and it is allocated in the stack.
// The loop proceeds, removing one node from either ‘a’ or ‘b’,
// and adding it to tail.
// When we are done, the result is in dummy.next.

Node *sorted_intersect(Node *node1, Node *node2) {
  Node *dummy = NULL;
  while (node1 != NULL && node2 != NULL) {
    if (node1->data == node2->data) {
      // This appends intersection to head.
      // We should actually append to end of list.
      insert_head(&dummy, node1->data);
      node1 = node1->next;
      node2 = node2->next;
    } else if (node1->data > node2->data) {
      node2 = node2->next;
    } else {
      node1 = node1->next;
    }
  }
  return dummy;
}

int main(int argc, char const *argv[]) {
  Node *head1 = NULL;
  insert_head(&head1, 15);
  insert_head(&head1, 10);
  insert_head(&head1, 5);
  insert_head(&head1, 3);
  insert_head(&head1, 1);

  Node *head2 = NULL;
  insert_head(&head2, 12);
  insert_head(&head2, 5);
  insert_head(&head2, 3);
  insert_head(&head2, 2);
  insert_head(&head2, 1);

  print_ln(head1);

  print_ln(head2);

  auto res = sorted_intersect(head1, head2);
  print_ln(res);

  return 0;
}
