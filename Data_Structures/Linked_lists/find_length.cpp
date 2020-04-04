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
    newnode->next = (*head_ref);
    (*head_ref) = newnode;
}

void println(node *n)
{
    while(n != NULL)
    {
        cout<<n->data<<" ";
        n = n->next;
    }
}

int getlength(node *n)
{
    /* 
    Returns length from the given node
    */
   int count = 0;
   while(n != NULL)
   {
       n = n->next;
       count += 1;
   }
   return count;
}

int main()
{
    node *head = NULL;
    insert_head(&head, 3);
    insert_head(&head, 2);
    insert_head(&head, 1);
    cout<<"The linked list is"<<endl;
    println(head);
    cout<<endl<<"Length of linked list is: "<<getlength(head);
    return(0);
}