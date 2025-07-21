// https://leetcode.com/problems/middle-of-the-linked-list/description/

// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.

struct ListNode {
    int val;
    ListNode *next;

    // initializer list syntax
    // we can avoid the this-> convention
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}

};

// classic fast and slow trick

class Solution {
    public:
        ListNode* middleNode(ListNode* head) {
            ListNode* fast = head;
            ListNode* slow = head;
    
            while(fast != nullptr && fast->next != nullptr) {
                fast = fast->next->next;
                slow = slow->next;
            }
    
            return slow;
    
        }
    };


