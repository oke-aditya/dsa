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
}

void insert_head(node **head_ref, int newdata)
{
    node *newnode = new node();
    newnode->data = newdata;
    newnode->next = *head_ref;
    *head_ref = newnode;
}

void del_pos(node *head_ref, int pos)
{
    node *temp = head_ref;
    if(pos == 0)
    {
        // We want to delete the head
        head_ref = temp->next;
        return;
    }
    else
    {
        // Find the previous node to be deleted.
        for(int i=0; temp != NULL && i<pos-1; i++)
        {
            temp = temp->next;
        }
        // If position is more than the nodes.
        if(temp == NULL || temp->next == NULL)
        {
            return;
        }
        else
        {
            // Double push the temp pointer to delete.
            temp->next = temp->next->next;    
            return;
        }
    }
}

int main()
{

    node *head = NULL;
    insert_head(&head, 3);
    insert_head(&head, 2);
    insert_head(&head, 1);
    insert_head(&head, 4);
    cout<<"Before deleting linked list: "<<endl;
    println(head);
    del_pos(head, 0);
    del_pos(head, 3);
    cout<<endl<<"After deleting linked list"<<endl;
    println(head);
    return(0);
}


