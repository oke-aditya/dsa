// Find length of linked list

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

int length(Node *node) {
  int count = 0;
  while (node != NULL) {
    count += 1;
    node = node->next;
  }
  return count;
}

int main(int argc, char const *argv[]) {
  Node *head = NULL;
  insert_head(&head, 3);
  insert_head(&head, 2);
  insert_head(&head, 1);

  print_ln(head);
  cout << length(head) << endl;

  return 0;
}
