#include<bits/stdc++.h>
using namespace std;

// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order, and each of their nodes
// contains a single digit. Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.


// Solution: -
// Create a dummy node
// Keep track of carry
// traverse both the lists till carry is not 0
// add values to sum (check list 1 not Null, list2 not NULL)
// calculate carry
// Create new node and add the sum.

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

void println(Node *node)
{
    while(node != NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
    cout<<endl;
}

Node* add_nums(Node *n1, Node *n2)
{
    // Placeholder for answer
    Node *dummy = new Node();

    // To traverse dummy
    Node *temp = dummy;

    int carry = 0;
    while(n1 != NULL || n2 != NULL || carry)
    {

        int sum = 0;
        if(n1 != NULL)
        {
            sum += n1->data;
            n1 = n1->next;
        }
        if(n2 != NULL)
        {
            sum += n2->data;
            n2 = n2->next;
        }

        // Add the previous carry
        sum += carry;
        carry = sum / 10;
        Node *node = new Node();
        node->data = (sum % 10);
        temp->next = node;
        temp = temp->next;
    }

    return dummy->next;

}

int main(int argc, char const *argv[])
{
    Node *head1 = new Node();
    Node *head2 = new Node();

    insert_head(&head1, 3);
    insert_head(&head1, 4);
    insert_head(&head1, 2);

    insert_head(&head2, 5);
    insert_head(&head2, 6);
    insert_head(&head2, 4);
    
    println(head1);
    println(head2);

    auto ans = add_nums(head1, head2);

    println(ans);

    cout<<endl;

    return 0;
}

