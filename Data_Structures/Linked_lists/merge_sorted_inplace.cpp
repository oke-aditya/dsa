// Merge two sorted linked lists and return it as a sorted list.

// The list should be made by splicing together the nodes of the first two lists.
// For example if the first linked list a is 5->10->15 and the other 
// linked list b is 2->3->20, then SortedMerge() 
// should return a pointer to the head node of the merged list 2->3->5->10->15->20.


#include<bits/stdc++.h>
using namespace std;

// Method 1
// Use a dummy node and extra linekd list to store result.

class Node
{
    public:
        int data;
        Node *next;
};

void print_ln(Node *node)
{
    while(node != NULL)
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

// This is an inplace merge operation.
Node* merge_lists(Node *node1, Node* node2)
{
    // Edge case, where any one is empty.
    if(node1 == NULL)
    {
        return node2;
    }
    if(node2 == NULL)
    {
        return node1;
    }

    Node *new_list = NULL;

    // Assign the first to smallest node.
    if(node1->data < node2->data)
    {
        new_list = node1;
        node1 = node1->next;
    }
    else
    {
        new_list = node2;
        node2 = node2->next;
    }

    Node *temp = new_list;

    // Add the smaller ones
    while (node1 != NULL && node2 != NULL)
    {
        if(node1->data < node2->data)
        {
            temp->next = node1;
            node1 = node1->next;
        }
        else
        {
            temp->next = node2;
            node2 = node2->next;
        }
        temp = temp->next;
    }

    // Add rest of the tail
    if(node1 != NULL)
        temp->next = node1;
    else
        temp->next = node2;

    return new_list;
}

int main(int argc, char const *argv[])
{
    Node *head1 = NULL;
    Node *head2 = NULL;

    insert_head(&head1, 15);
    insert_head(&head1, 10);
    insert_head(&head1, 5);

    cout<<endl<<"First list = ";
    print_ln(head1);

    insert_head(&head2, 20);
    insert_head(&head2, 5);
    insert_head(&head2, 3);

    cout<<endl<<"Second list = ";
    print_ln(head2);

    auto merged_list = merge_lists(head1, head2);
    cout<<"Merged List = ";
    print_ln(merged_list);

    return 0;
}
