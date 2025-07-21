// https://leetcode.com/problems/palindrome-linked-list/
// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

// Input: head = [1,2,2,1]
// Output: true

// Example 2:

// Input: head = [1,2]
// Output: false


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode *reverse(ListNode *head) {
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


    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *rev_head = reverse(slow);

        while(rev_head != nullptr) {
            
            if(rev_head->val != head->val) {
                return false;
            }

            rev_head = rev_head->next;
            head = head->next;
        }
        return true;
    }
};
