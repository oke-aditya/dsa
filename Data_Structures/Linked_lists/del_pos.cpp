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
            temp->next = temp->next->next;    
            return;
        }
    }
}

int main()
{
    // cout<<"Hello GCC"<<endl;

    return(0);
}


