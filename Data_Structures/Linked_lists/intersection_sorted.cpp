// Given two lists sorted in increasing order, 
// create and return a new list representing the intersection of the two lists.
// The new list should be made with its own memory — the original lists should not be changed.

// For example, let the first linked list be 1->2->3->4->6 and second linked list be 2->4->6->8, 
// then your function should create and return a third list as 2->4->6.

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
    cout<<endl;
}

// The strategy here uses a temporary dummy node as the start of the result list. 
// The pointer tail always points to the last node in the result list, so appending new nodes is easy. 
// The dummy node gives tail something to point to initially when the result list is empty. 
// This dummy node is efficient, since it is only temporary, and it is allocated in the stack. 
// The loop proceeds, removing one node from either ‘a’ or ‘b’, and adding it to tail. 
// When we are done, the result is in dummy.next.

node *sorted_intersect(node *a, node *b)
{
    node dummy;
    node *tail = &dummy;
    dummy.next = NULL;

    while(a != NULL && b != NULL)
    {
        if(a->data == b->data)
        {
            insert_head(&(tail->next), a->data);
            tail = tail->next;
            a = a->next;
            b = b->next;
        }
        else if (a->data < b->data)
        {
            a = a->next;
        }
        else
        {
            b = b->next;
        }
    }
    return dummy.next;
}

int main()
{
    node *a = NULL;
    node *b = NULL;
    node *intersect = NULL;

    insert_head(&a, 5);
    insert_head(&a, 4);
    insert_head(&a, 3);
    insert_head(&a, 1);

    insert_head(&b, 6);
    insert_head(&b, 5);
    insert_head(&b, 3);
    insert_head(&b, 2);

    intersect = sorted_intersect(a, b);

    cout<<"Linked list with intersection of a and b"<<endl;
    println(intersect);

    return(0);
}
