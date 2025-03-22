// https://leetcode.com/problems/reorder-list/

// You are given the head of a singly linked-list. The list can be represented
// as:

// L0 → L1 → … → Ln - 1 → Ln

// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

// You may not modify the values in the list's nodes. Only nodes themselves may
// be changed.

// Input: head = [1,2,3,4]
// Output: [1,4,2,3]

// logic
// Find the middle of linked list
// Reverse the second half.
// Merge them.

#include <bits/stdc++.h>
using namespace std;

class ListNode {
 public:
  int val;
  ListNode *next;

  ListNode(int val) { this->val = val; }
};

ListNode *reverse_list(ListNode *head) {
  ListNode *new_head = NULL;
  while (head != NULL) {
    ListNode *next_node = head->next;
    head->next = new_head;
    new_head = head;
    head = next_node;
  }

  return new_head;
}

void reorderList(ListNode *head) {
  ListNode *slow = head;
  ListNode *fast = head;

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }

  ListNode *second = reverse_list(slow->next);
  slow->next = NULL;

  ListNode *first = head;

  while (second) {
    ListNode *temp1 = first->next;
    ListNode *temp2 = second->next;

    first->next = second;
    second->next = temp1;
    first = temp1;
    second = temp2;
  }
}
