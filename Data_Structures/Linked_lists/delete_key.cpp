// Let us formulate the problem statement to understand the deletion process. Given a ‘key’, delete the first occurrence of this key in linked list.
// To delete a node from linked list, we need to do following steps.
// 1) Find previous node of the node to be deleted.
// 2) Change the next of previous node.
// 3) Free memory for the node to be deleted.

#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;
};

void println(node *n)
{
    while(n->next != NULL)
    {
        cout<<n->data<<" ";
        n = n->next;
    }
    return ;
}

void insert_head(node **head_ref, int newdata)
{
    node *newnode = new node();
    newnode->data = newdata;
    newnode->next = (*head_ref);
    (*head_ref) = newnode;

}

void del_key(node **head_ref, int key)
{
    node *temp = *head_ref;
    node *prev = new node();

    // head has to be deleted;
    if(temp->data == key && temp != NULL)
    {
        *head_ref = temp->next;
        return;
    }
    // Otherwise search for the key and delete it
    while(temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;

    }
    if(temp == NULL)
    {
        // Key does not exist, nothing deleted
        return;
    }
    else
    {
        prev->next = temp->next;
    }
}

int main()
{
    node *head = new node();
    insert_head(&head, 7);
    insert_head(&head, 10);
    insert_head(&head, 12);
    cout<<"Before deleting 10"<<endl;
    println(head);
    del_key(&head, 10);
    cout<<endl<<"After deleting 10"<<endl;
    println(head);
    return(0);
}

