// https://leetcode.com/problems/rotate-list/description/

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

    int find_length(ListNode* head) {
        int ln = 0;
        while(head != nullptr) {
            head = head->next;
            ln += 1;
        }

        return ln;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0) {
            return head;
        }

        if(head == nullptr) {
            return nullptr;
        }

        int ln = find_length(head);
        int rot = k % ln;

        if(rot == 0) {
            return head;
        }
        
        int break_pt = ln - rot - 1;

        // break the loop
        ListNode *temp = head;

        while(break_pt--) {
            temp = temp->next;
        }

        // Make a loop
        ListNode *curr = head;
        while(curr->next != nullptr) {
            curr = curr->next;
        }

        ListNode *new_head = temp->next;
        temp->next = nullptr;

        // make a loop;
        curr->next = head;

        return new_head;
    }
};