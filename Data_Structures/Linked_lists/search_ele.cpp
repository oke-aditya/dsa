// Write a function that searches a given key ‘x’ in a given singly linked list.
// The function should return true if x is present in linked list and false otherwise.

// Iterative solution
// 2) Initialize a node pointer, current = head.
// 3) Do following while current is not NULL
//     a) current->key is equal to the key being searched return true.
//     b) current = current->next
// 4) Return false

#include <bits/stdc++.h>
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

void print_ln(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

bool search(Node *node, int ele)
{
    while(node != NULL) {
        if(node ->data == ele) {
            return true;
        }
        node = node->next;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    Node *head = new Node();
    head->next = NULL;

    insert_head(&head, 5);
    insert_head(&head, 4);
    insert_head(&head, 3);
    insert_head(&head, 2);
    insert_head(&head, 1);

    if (search(head, 3))
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    return 0;
}
