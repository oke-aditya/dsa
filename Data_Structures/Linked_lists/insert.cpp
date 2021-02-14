// Insert at all 3 positions in linked list

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
            int data;
            Node *next;
};

// Insert into head node
void insert_head(Node **headref, int new_data)
{
    // Create a new node
    Node *new_node = new Node();
    
    // Add the data
    new_node->data = new_data;

    // Point next to head.
    new_node->next = *headref;

    // Mobe the newhead to newnode.
    (*headref) = new_node;
}

// Insert after a previous node.
void insert_after(Node *prev_node, int new_data)
{
    if(prev_node == NULL)
    {
        cout<<"Previous node cannto be null";
        cout<<endl;
    }

    // Allocate new node
    Node * new_node = new Node();
    new_node->data = new_data;
    
    // Shift this pointer to point as next of previous node.
    new_node->next = prev_node->next;

    // Shift the previous node pointer to newnode
    prev_node->next = new_node;
}

void insert_end(Node **head_ref, int new_data)
{
    Node *new_node = new Node();

    // Keep track of prev node
    Node *last = *head_ref;

    // Fill the data
    new_node->data = new_data;

    // Since this node is last we will set it to NULL
    new_node->next = NULL;

    // If we are appending to empty list
    if(*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    // Else traverse till end and then insert
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    return;
}

void print_ln(Node *node)
{
    while(node != NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
}

int main(int argc, char const *argv[])
{
    Node *head =  NULL;
    insert_end(&head, 6);
    insert_head(&head, 2);
    insert_head(&head, 3);
    insert_end(&head, 1);
    print_ln(head);
    return 0;
}

