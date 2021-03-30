// Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
// (i) a next pointer to the next node,
// (ii) a bottom pointer to a linked list where this node is head.
// Each of the sub-linked-list is in sorted order.
// Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 

// Note: The flattened list will be printed using the bottom pointer instead of next pointer.

// Input:
// 5 -> 10 -> 19 -> 28
// |     |     |     | 
// 7     20    22   35
// |           |     | 
// 8          50    40
// |                 | 
// 30               45
// Output:  5-> 7-> 8- > 10 -> 19-> 20->
// 22-> 28-> 30-> 35-> 40-> 45-> 50.
// Explanation:
// The resultant linked lists has every 
// node in a single level.
// (Note: | represents the bottom pointer.)

// Input:
// 5 -> 10 -> 19 -> 28
// |          |                
// 7          22   
// |          |                 
// 8          50 
// |                           
// 30              
// Output: 5->7->8->10->19->20->22->30->50
// Explanation:
// The resultant linked lists has every
// node in a single level.

// Solution: -
// First we need to merge two linked list togeether.
// We can merge them using same logic as in merge sort, by comparing the greater elements.
// We keep this to a temp node and return it. This flattens two lists.
// Now we again need to flatten two lists, we again call merge.
// 
// 


#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node *bottom; 
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

Node *merge_two_lists(Node *a, Node *b)
{
    Node *temp = new Node();
    // Keep track of temp.
    Node *res = temp;

    while(a != NULL && b != NULL)
    {
        // If a is smaller, we need to add a's data
        // We add a's data to temp list.
        if(a->data < b->data)
        {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }

        // Otherwise keep b's data.
        else
        {
            temp->bottom = b;
            temp = temp->bottom;
            b = b ->bottom;
        }
    }

    // At the end we will have finished either a or b
    if(a)
    {
        temp->bottom = a;
    }
    else
    {
        temp->bottom = b;
    }

    // Res was pointing to temp, we can use that to return.
    return res->bottom;
}

Node *flatten(Node *root)
{
    if(root == NULL || root->next == NULL)
    {
        return root;
    }

    // Recur on the right
    root->next = flatten(root->next);

    // Now merge
    root = merge_two_lists(root, root->next);

    // Return the root
    return (root);

}


int main(int argc, char const *argv[])
{
    
    return 0;
}

