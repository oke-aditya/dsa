// https://leetcode.com/problems/linked-list-cycle-ii/

// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

// There is a cycle in a linked list if there is some node in the
// list that can be reached again by continuously following the next pointer.
// Internally, pos is used to denote the index of the node that tail's
// next pointer is connected to. Note that pos is not passed as a parameter.

// Notice that you should not modify the linked list.

// Input: head = [3,2,0,-4], pos = 1
// Output: tail connects to node index 1
// Explanation: There is a cycle in the linked list, where tail connects to the second node.

// Input: head = [1,2], pos = 0
// Output: tail connects to node index 0
// Explanation: There is a cycle in the linked list, where tail connects to the first node.

// Solution: -
// Keep a fast pointer and a slow pointer and entry pointer all to head.
// if head is null and head->next is null, we can't have cycle.
// while fast->next and fast->next->next exists, keep advancing
// fast by 2. slow by 1.
// if fast and slow meet together.
// while slow is not equal to entry.
// keep moving slow by 1.
// keep moving entry by 1.
// Return entry pointer.
//

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void insert_head(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void println(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

Node *find_first_cycle(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *slow = head, *fast = head, *entry = head;

    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            while(slow != entry)
            {
                slow = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }

    return NULL;
    
}

int main(int argc, char const *argv[])
{

    return 0;
}
