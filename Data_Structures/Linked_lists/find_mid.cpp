// Given a singly linked list, find middle of the linked list. 
// For example, if given linked list is 1->2->3->4->5 then output should be 3.
// If there are even nodes, then there would be two middle nodes, we need to print second middle element. 
// For example, if given linked list is 1->2->3->4->5->6 then output should be 4.

// Traverse linked list using two pointers. Move one pointer by one and other pointer by two. 
// When the fast pointer reaches end slow pointer will reach middle of the linked list.

#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;
};

void insert_head(node **head_ref, int newdata)
{
    node *newnode = new node();
    newnode->data = newdata;
    newnode->next = *head_ref;
    *head_ref = newnode;
}

void println(node *n)
{
    while(n != NULL)
    {
        cout<<n->data<<" ";
        n = n->next;
    }
}

void detect_middle(node *head)
{
    node *fast = head;
    node *slow = head;

    if(head != NULL)
    {
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        cout<<endl<<"Middle of linked list: "<<slow->data<<endl; 
    }
    else
    {
        cout<<endl<<"No middle element exists for only head";
    }
    
}

int main()
{
    node *head = NULL;
    insert_head(&head, 5);
    insert_head(&head, 2);
    insert_head(&head, 3);
    insert_head(&head, 1);
    insert_head(&head, 4);
    cout<<"Linked list is "<<endl;
    println(head);
    detect_middle(head);
    return(0);
}
