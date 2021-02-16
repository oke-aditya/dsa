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

    // We assume node1 to be the node with smallest data at head.
    if(node1->data > node2->data)
    {
        swap(node1, node2);
    }

    // To this list with inital smallest value, we merge.
    Node *res = node1;
    while(node1 != NULL && node2 != NULL)
    {
        // Temporary node to fill values.
        Node *temp = NULL;
        while(node1 != NULL && node1->data <= node2->data)
        {
            // Continue linking the smallest nodes, theya re in node1.
            temp = node1;
            node1 = node1->next;
        }
        // Since now node1->data > node2->data.
        // We wil link temp to smallset, that is node2. 
        temp->next = node2;
        swap(node1, node2);
    }
    return res;
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
