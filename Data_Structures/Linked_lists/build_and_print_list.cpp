#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
            int data;
            Node *next;  
};

void print_ln(Node *node)
{
    while(node != NULL)
    {
        cout<<node->data<<" ";
        node = node ->next;
    }
}

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;
    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;
    head->next = second;
    
    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    print_ln(head);

    return 0;
}

