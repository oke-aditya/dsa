// Given the head of a singly linked list, return true if it is a palindrome.

// Input: head = [1,2,2,1]
// Output: true

// Input: head = [1,2]
// Output: false

// Solution: -
// Find middle of linked list.
// Reverse the remaining linked list.
// Now check if data matches on either side.


#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;  
};

void insert_head(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;

}

Node* reverse_list(Node *node)
{
    Node *prev = NULL;
    Node *forw = NULL;

    while(node != NULL)
    {
        forw = node->next;
        node->next = prev;
        prev = node;
        node = forw;
    }
    return prev;
}

bool is_palindrome(Node *head)
{
    if(head == NULL || head->next == NULL)
    {
        return true;
    }

    Node *slow = head;
    Node *fast = head;

    // Find the middle element in the linked list.
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

    }

    // Reverse the forward half
    slow->next = reverse_list(slow->next);
    slow = slow->next;

    while(slow != NULL)
    {
        if(head->data != slow->data)
        {
            return false;
        }
        head = head->next;
        slow = slow->next;
    }

    return true;

}


void println(Node *node)
{
    while(node != NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
}

int main(int argc, char const *argv[])
{
    Node *head = new Node();

    insert_head(&head, 5);
    insert_head(&head, 4);
    insert_head(&head, 3);
    insert_head(&head, 4);
    insert_head(&head, 5);

    println(head);

    auto res = is_palindrome(head);

    cout<<endl;

    println(head);

    cout<<endl;

    if(res)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }

    cout<<endl;    

    return 0;
}

