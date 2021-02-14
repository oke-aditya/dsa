// Given a singly linked list, find middle of the linked list. 

// For example, if given linked list is 1->2->3->4->5 then output should be 3.
// If there are even nodes, then there would be two middle nodes, we need to print second middle element. 
// For example, if given linked list is 1->2->3->4->5->6 then output should be 4.

// Traverse linked list using two pointers. Move one pointer by one and other pointer by two. 
// When the fast pointer reaches end slow pointer will reach middle of the linked list.

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

void print_ln(Node *node)
{
    while(node != NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
    cout<<endl;
}

int mid(Node *head)
{
    Node *slow = new Node();
    slow = head;
    Node *fast = new Node();
    fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    insert_head(&head, 5);
    insert_head(&head, 4);
    insert_head(&head, 3);
    insert_head(&head, 2);
    insert_head(&head, 1);
    
    print_ln(head);
    cout<<mid(head)<<endl;

    return 0;
}

