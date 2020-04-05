// Write a function that searches a given key ‘x’ in a given singly linked list. 
// The function should return true if x is present in linked list and false otherwise.

// Iterative solution
// 2) Initialize a node pointer, current = head.
// 3) Do following while current is not NULL
//     a) current->key is equal to the key being searched return true.
//     b) current = current->next
// 4) Return false 

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
}

void insert_head(node **head_ref, int newdata)
{
    node *newnode = new node();
    newnode->data = newdata;
    newnode->next = (*head_ref);
    (*head_ref) = newnode;
}

void search_ele(node *head_ref, int ele)
{
    int fg = 0;
    node *temp = head_ref;
    while(temp != NULL)
    {
        // cout<<endl<<temp->data;
        if(temp->data == ele)
        {
            cout<<endl<<"The required "<<ele<<" is found";
            fg = 1;
            break;
        }
        temp = temp->next;
    }
    if(fg == 0)
    {
        cout<<endl<<"Element "<<ele<<" not found";
    }
    // cout<<endl<<temp->next->data;
}


int main()
{
    node *head = new node();
    head->next = NULL;
    insert_head(&head, 3);
    insert_head(&head, 2);
    insert_head(&head, 1);
    cout<<"The linked list is: ";
    cout<<endl;
    println(head);
    search_ele(head, 2);
    search_ele(head, 5);
    return(0);
}


