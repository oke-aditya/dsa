// https://leetcode.com/problems/merge-two-sorted-lists/
// Merge two sorted linked lists and return it as a sorted list.

// The list should be made by splicing together the nodes of the first two
// lists. For example if the first linked list a is 5->10->15 and the other
// linked list b is 2->3->20, then SortedMerge()
// should return a pointer to the head node of the merged list
// 2->3->5->10->15->20.

#include <bits/stdc++.h>
using namespace std;

// Method 1
// Use a dummy node and extra linekd list to store result.

class Node {
 public:
  int data;
  Node *next;
};

void print_ln(Node *node) {
  while (node != NULL) {
    cout << node->data << " ";
    node = node->next;
  }
  cout << endl;
}

void insert_head(Node **head_ref, int new_data) {
  Node *new_node = new Node();
  new_node->data = new_data;
  new_node->next = *head_ref;
  *head_ref = new_node;
}

Node *merge_lists(Node *head1, Node *head2) {
  if (head1 == NULL) return head2;

  if (head2 == NULL) return head1;

  Node *merged_head = NULL;

  if (head1->data < head2->data) {
    merged_head = head1;
    head1 = head1->next;
  }

  else {
    merged_head = head2;
    head2 = head2->next;
  }

  Node *temp = merged_head;

  while (head1 != NULL && head2 != NULL) {
    if (head1->data < head2->data) {
      temp->next = head1;
      head1 = head1->next;
    }

    else {
      temp->next = head2;
      head2 = head2->next;
    }
    temp = temp->next;
  }

  if (head1 != NULL) {
    temp->next = head1;
  }

  else {
    temp->next = head2;
  }

  return merged_head;
}

int main(int argc, char const *argv[]) {
  Node *head1 = NULL;
  Node *head2 = NULL;

  insert_head(&head1, 15);
  insert_head(&head1, 10);
  insert_head(&head1, 5);

  cout << endl << "First list = ";
  print_ln(head1);

  insert_head(&head2, 20);
  insert_head(&head2, 5);
  insert_head(&head2, 3);

  cout << endl << "Second list = ";
  print_ln(head2);

  auto merged_list = merge_lists(head1, head2);
  print_ln(merged_list);

  return 0;
}
