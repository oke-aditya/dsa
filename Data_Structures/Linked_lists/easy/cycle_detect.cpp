// https://leetcode.com/problems/linked-list-cycle/description/?

// Detect cycle in LinkedList
// Given head, the head of a linked list, determine if the linked list has a cycle in it.
// There is a cycle in a linked list if there is some node in the list 
// that can be reached again by continuously following the next pointer.
// Internally, pos is used to denote the index of the node that tail's 
// next pointer is connected to. Note that pos is not passed as a parameter.
// Return true if there is a cycle in the linked list. Otherwise, return false.

// Example 1:

// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

// Example 2:

// Input: head = [1,2], pos = 0
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

struct ListNode {
    int val;
    ListNode *next;

    // initializer list syntax
    // we can avoid the this-> convention
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}

};

class Solution {
    public:
        bool hasCycle(ListNode *head) {
            ListNode *fast = head;
            ListNode *slow = head;

            while(fast != nullptr && fast->next != nullptr) {
                fast = fast->next->next;
                slow = slow->next;
                
                if(fast == slow) {
                    return true;
                }
            }

            return false;
            
        }
};

