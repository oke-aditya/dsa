// https://leetcode.com/problems/intersection-of-two-linked-lists/

// Given the heads of two singly linked-lists headA and headB,
// return the node at which the two lists intersect. If the two linked lists
// have no intersection at all, return null.

// It is guaranteed that there are no cycles anywhere in the entire linked
// structure.

// Note that the linked lists must retain their original structure after the
// function returns.

// Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA =
// 2, skipB = 3 Output: Intersected at '8' Explanation: The intersected node's
// value is 8 (note that this must not be 0 if the two lists intersect). From
// the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as
// [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are
// 3 nodes before the intersected node in B

// Solution: -
// Start traversing both the lists till first and second are not equal.
// if we reach null with list1 assign it to head of list2
// if we reach null with list2 assign it to head of list1
// keep moving list1 and list2 forward.
// Return list1.

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

Node *calculate_intersection(Node *head1, Node *head2) {
  if (head1 == NULL || head2 == NULL) {
    return NULL;
  }

  Node *temp1 = head1;
  Node *temp2 = head2;

  while (temp1 != temp2) {
    if (temp1 == NULL) {
      temp1 = head2;
    } else {
      temp1 = temp1->next;
    }

    if (temp2 == NULL) {
      temp2 = head1;
    } else {
      temp2 = temp2->next;
    }
  }

  return temp1;
}

int main(int argc, char const *argv[]) { return 0; }
