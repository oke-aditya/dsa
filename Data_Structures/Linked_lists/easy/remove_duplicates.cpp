// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description
// Given the head of a sorted linked list, 
// delete all duplicates such that each element appears only once.
// Return the linked list sorted as well.

// Input: head = [1,1,2]
// Output: [1,2]

// Option 1 is to build a new List
// New list can have new nodes
// this is slightly better if we don't like inplace operations

#include <cstddef>
#include <climits>


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *res = new ListNode(INT_MAX);
        ListNode *curr = res;

        while(head != nullptr) {
            
            if(curr->val != head->val) {
                ListNode *newnode = new ListNode(head->val);
                curr->next = newnode;
                curr = curr->next;
            }

            head = head->next;
        }
        
        return res->next;
    }
};

// an inplace solution, just delete the node pointers
// note this can have memory leak if we don't free the pointers

class Solution2 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp = head;
        while(temp != nullptr && temp->next != nullptr)
        {
            if(temp->next->val == temp->val)
            {
                temp->next = temp->next->next;
                continue;
            }
            temp = temp->next;
        }

        return head;
    }
};

