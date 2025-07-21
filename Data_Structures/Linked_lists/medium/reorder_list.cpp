// https://leetcode.com/problems/reorder-list/

// You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:
// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes.
// Only nodes themselves may be changed.

// Input: head = [1,2,3,4]
// Output: [1,4,2,3]

// Input: head = [1,2,3,4,5]
// Output: [1,5,2,4,3]

// Solution

// We need to keep reversing the list several times
// reverse, head->next, then head->next->next, till we reach end

// 1 2 3 4 5
//   -------     reverse
// 1 5 4 3 2
//     -----     reverse
// 1 5 2 3 4
//       ---     reverse
// 1 5 2 4 3
//         -     reverse
// 1 5 2 4 3

// 1 2 3 4
//   -----       reverse
// 1 4 3 2
//     ---       reverse
// 1 4 2 3
//       -       reverse
// 1 4 2 3    

// The above approach is super hard for linked list
// it is v easy to do on array, but v hard on LL

// Better idea is 

// 1 2 3 4 5

// Find mid and break 2

// 1 2 3
// 4 5

// Reverse 2nd half

// 1 2 3
// 5 4

// Merge these 2
// 1 -> 5 -> 2 -> 4 -> 3



// Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:

    ListNode* reverse_list(ListNode *head) {
        ListNode *prevNode = nullptr;
        ListNode *nextNode = nullptr;

        while(head != nullptr) {
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;
    }



    void reorderList(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // reverse the next half
        ListNode *rev = reverse_list(slow->next);

        // break the first list
        slow->next = nullptr;

        // now weave and stich these 2 lists

        ListNode *curr = head;

        while(curr != nullptr && rev != nullptr) {
            ListNode *temp1 = curr->next;
            ListNode *temp2 = rev->next;

            curr->next = rev;
            rev->next = temp1;
            curr = temp1;
            rev = temp2;
        }

    }
};


