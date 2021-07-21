// https://leetcode.com/problems/reverse-linked-list/
// Given pointer to the head node of a linked list, the task is to reverse the linked list. 
// We need to reverse the list by changing links between nodes.

// Input: Head of following linked list
// 1->2->3->4->NULL
// Output: Linked list should be changed to,
// 4->3->2->1->NULL

// Input: Head of following linked list
// 1->2->3->4->5->NULL
// Output: Linked list should be changed to,
// 5->4->3->2->1->NULL

// Input: NULL
// Output: NULL

// Input: 1->NULL
// Output: 1->NULL 

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
};

void print_ln(Node *node)
{
    while (node != NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
    cout<<endl;
}

void insert_head(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

Node* reverse_list(Node *node)
{
    Node *new_head = NULL;
    while(node != NULL)
    {
        Node *temp = node->next;
        node->next = new_head;
        new_head = node;
        node = temp;
    }
    return new_head;
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

    auto new_head = reverse_list(head);

    print_ln(new_head);

    return 0;
}

