// https://leetcode.com/problems/reverse-linked-list/description/?
// Given the head of a singly linked list, reverse the list, and return the reversed list.

// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]

// Solution : -
// Keep 3 pointers, next Node and previous Node
// keep nextPointer and head->next
// switch head->next to prevNode
// move prev to head
// move head to nextPointer
// finally prevNode is at end of LL


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
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
};


