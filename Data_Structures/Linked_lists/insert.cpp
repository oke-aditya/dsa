#include<iostream>
using namespace std;

class node
{
    public: 
    int data;
    node *next;
};

// Add a node at the front: (A 4 steps process)
// And newly added node becomes the new head of the Linked List. 
// For example if the given Linked List is 10->15->20->25 and we add an item 5 at the front, 
// then the Linked List becomes 5->10->15->20->25.

// Let us call the function that adds at the front of the list is insert_head(). 
// The insert_head() must receive a pointer to the head pointer, because push must change the head pointer to point to the new node 

void insert_head(node **headref, int new_data)
{
    // Create a newnode
    node* newnode = new node();
    // Push the data;;
    newnode->data = new_data;
    // Make next of newnode as head
    newnode->next = (*headref);
    // Move the newhead to newnode
    (*headref) = newnode;
}

// Inserting after a previous node

void insert_afer(node *prev_node, int new_data)
{
    if(prev_node == NULL)
    {
        cout<<"Previous cannot be null";
        cout<<endl;
    }
    //  Allocate new node
    node *newnode = new node();
    //  Put new data
    newnode->data = new_data;
    //  Shift this pointer to next
    newnode->next = prev_node->next;
    //  Shift the prev pointer to this
    prev_node->next = newnode;

}

//  Appending at the end of ll
void append(node **head_ref, int new_data)
{
    node *newnode = new node();

    // To keep a track of prev node
    node *last = *head_ref;

    // Put the data 
    newnode->data = new_data;

    // This newnode will be last node hence it will be NULL

    newnode->next = NULL;

    // If we are appending to empty list 
    if(*head_ref == NULL)
    {
        *head_ref = newnode;
        return;
    }

    // Else traverse till end and then insert
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = newnode;
    return;
}

void println(node *n)
{
    while(n != NULL)
    {
        cout<<n->data<<" ";
        n = n->next;
    }
}

int main()
{
    node *head = NULL;
    append(&head, 6);
    insert_head(&head, 2);
    insert_head(&head, 3);
    append(&head, 1);
    cout<<"The linked list is: "<<endl;
    println(head);
    // head = new() node;
    return(0);
}
