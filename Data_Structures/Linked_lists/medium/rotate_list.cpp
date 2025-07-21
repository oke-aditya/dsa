
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

    int find_length(ListNode *head) {
        int count = 0;
        while(head != nullptr) {
            head = head->next;
            count += 1;
        }

        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        // find the length, 
        // if rotations > length then we need k % len rotations

        if(head == nullptr || k == 0) {
            return head;
        }

        int length = find_length(head);
        int rotations = k % length;

        // we need to join tail to head
        // then break the connection at head + rotations
        // find the breaking point in linked list
        // breaking point is not exactly rotation, it is the number of elements from start
        // so subtract length - rotations - 1
        int steps_to_break = length - rotations - 1;

        ListNode *break_head = head;

        while(steps_to_break--) {
            break_head = break_head->next;
        }

        // here is where the break_head next goes nullptr;
        // break_head we will use to break linkedlist

        // join tail to head
        ListNode* curr = head;
        while(curr->next != nullptr) {
            curr = curr->next;
        }

        // makes linkedList into a loop
        curr->next = head;
        
        // this would be new_head to return
        ListNode *new_head = break_head->next;
        
        // now break the loop with break_head
        break_head->next = nullptr;

        return new_head;

    }
};