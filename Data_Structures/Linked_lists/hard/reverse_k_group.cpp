// https://leetcode.com/problems/reverse-nodes-in-k-group/description/
// Given the head of a linked list, reverse the nodes of the list k at a time, 
// and return the modified list.

// k is a positive integer and is less than or equal 
// to the length of the linked list. 
// If the number of nodes is not a multiple of k then 
// left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

//  * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <bits/stdc++.h>


// 1 -> 2 -> 3

class Solution {
public:

    ListNode *reverse(ListNode *curr, ListNode *end) {
        ListNode *prev = nullptr;
        while(curr != end) {
            ListNode *next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        return prev;
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr) {
            return nullptr;
        }

        ListNode *tail = head;
        for(int i=0; i<k; i++) {
            if(tail == nullptr) {
                return head;
            }
            tail = tail->next;
        }

        ListNode *new_head = reverse(head, tail);
        head->next = reverseKGroup(tail, k);
        return new_head;
    }
};