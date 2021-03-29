// Given head, the head of a linked list, determine if the linked list has a cycle in it.

// There is a cycle in a linked list if there is some node in the list 
// that can be reached again by continuously following the next pointer.
//  Internally, pos is used to denote the index of the node that tail's next pointer is
// connected to. Note that pos is not passed as a parameter.

// Return true if there is a cycle in the linked list. Otherwise, return false.

// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

// Solution: -
// Keep a slow pointer and a fast pointer.
// Proceed fast by 2, slow by 1.
// If fast and slow meet together, there is cylce in list.

#include<bits/stdc++.h>
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
    while(node != NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
    cout<<endl;
}

bool detect_loop(Node *head)
{
    if(head == NULL || head->next == NULL)
    {
        return false;
    }

    Node *fast = head;
    Node *slow = head;

    while(fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
        {
            return true;
        }
    }
    return false;

}


int main(int argc, char const *argv[])
{
    Node *head = NULL;
    insert_head(&head, 10);
    insert_head(&head, 5);
    insert_head(&head, 3);
    insert_head(&head, 4);
    // Create a loop for testing
    println(head);
    head->next->next->next->next = head;

    auto is_loop = detect_loop(head);
    
    if(is_loop)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    

    return(0);

}