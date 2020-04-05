// Given a linked list, check if the linked list has loop or not.
// Floyd’s Cycle-Finding Algorithm: This is the fastest method and has been described below:

//     Traverse linked list using two pointers. 
//     Move one pointer(slow_p) by one and another pointer(fast_p) by two. 
//     If these pointers meet at the same node then there is a loop. If pointers do not meet then linked list doesn’t have a loop

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
    while(n != NULL)
    {
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<endl;
}

void insert_head(node **head_ref, int newdata)
{
    node *newnode = new node();
    newnode->data = newdata;
    newnode->next = *head_ref;
    *head_ref = newnode;
}

int detect_loop(node *head)
{
    int fg = 0;
    node *slow = head;
    node *fast = head;

    while(slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            cout<<"Found loop"<<endl;
            fg = 1;
            return fg;
        }
    }
    if(fg == 0)
    {
        cout<<"No loop found"<<endl;
        return fg;
    }
}


int main()
{
    node *head = NULL;
    insert_head(&head, 10);
    insert_head(&head, 5);
    insert_head(&head, 3);
    insert_head(&head, 4);
    // Create a loop for testing
    // head->next->next->next->next = head;
    println(head);
    auto is_loop = detect_loop(head);
    // cout<<is_loop<<endl;
    return(0);
}

