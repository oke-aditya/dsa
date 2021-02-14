// Delete a key at particular position in Linked List

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
};

void print_ln(Node *n)
{
    while(n != NULL)
    {
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<endl;
}

void insert_head(Node **head_ref, int new_data)
{
    Node *newnode = new Node();
    newnode->data = new_data;
    newnode->next = *head_ref;
    *head_ref = newnode;
}

// Delete the position of array.
void del_pos(Node **head_ref, int pos)
{
    Node *temp = *head_ref;
    if(pos == 0)
    {
        // We want to delete the head
        *head_ref = temp->next;
        return;
    }
    else
    {
        // Find the previosu node to be delete.
        while(temp != NULL && pos > 1)
        {
            temp = temp->next;
            pos -= 1;
        }
        // At end of this position will be 0 and we can delete.
        if(temp == NULL || temp->next == NULL)
        {
            // We have reached the end nothing to delete
            return;
        }
        else
        {
            // Remove the current pointer and assign to next, next
            temp->next = temp->next->next;
            return;
        }
    }
}

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    insert_head(&head, 5);
    insert_head(&head, 4);
    insert_head(&head, 3);
    insert_head(&head, 2);
    insert_head(&head, 1);

    print_ln(head);

    del_pos(&head, 2);

    print_ln(head);

    return 0;
}

