// https://leetcode.com/problems/partition-list/description/

// Given the head of a linked list and a value x, partition it such that all
// nodes less than x
//  come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes
// in each of the two partitions.

// Input: head = [1,4,3,2,5,2], x = 3
// Output: [1,2,2,4,3,5]

// Example 2:

// Input: head = [2,1], x = 2
// Output: [1,2]

#include <bits/stdc++.h>
using namespace std;

class ListNode {
 public:
  int val;
  ListNode *next;

  ListNode(int val) { this->val = val; }
};

ListNode *partition(ListNode *head, int x) {
  ListNode *small = new ListNode(-1);
  ListNode *small_head = small;
  ListNode *large = new ListNode(-1);
  ListNode *large_head = large;

  while (head) {
    if (head->val < x) {
      small->next = head;
      small = small->next;
      head = head->next;
      small->next = NULL;
      // cout<<head->val<<endl;
    }

    else {
      large->next = head;
      large = large->next;
      head = head->next;
      large->next = NULL;
      // cout<<head->val<<endl;
    }
  }

  small->next = large_head->next;

  return small_head->next;
  // return large_head->next;
}
