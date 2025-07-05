// https://leetcode.com/problems/intersection-of-two-linked-lists/

// Given the heads of two singly linked-lists headA and headB, 
// return the node at which the two lists intersect. If the two linked lists have no 
// intersection at all, return null.
// For example, the following two linked lists begin to intersect at node c1:

// Find difference in the length and use this to traverse
// now find the intersection


#include <cstddef>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:

    int find_length(ListNode *head) {
        int length = 0;
        while(head != nullptr) {
            head = head->next;
            length += 1;
        }
        return length;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int ln1 = find_length(headA);
        int ln2 = find_length(headB);

        // cout<<ln1<<endl;
        // cout<<ln2<<endl;

        if(ln1 > ln2) {
            int diff = ln1 - ln2;
            while(diff--) {
                headA = headA->next;
            }
        }

        else if(ln2 > ln1) {
            int diff = ln2 - ln1;
            while(diff--) {
                headB = headB->next;
            }
        }

        while(headA != nullptr && headB != nullptr) {

            if(headA == headB) {
                return headA;
            }

            headA = headA->next;
            headB = headB->next;
            
        }

        return nullptr;
    }
};

