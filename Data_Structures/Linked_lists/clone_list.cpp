// https://leetcode.com/problems/copy-list-with-random-pointer/
// A linked list of length n is given such that each node contains
// an additional random pointer, which could point to any node in the list, or null.

// Construct a deep copy of the list.
// The deep copy should consist of exactly n brand new nodes,
// where each new node has its value set to the value of its corresponding original node.
// Both the next and random pointer of the new nodes should point to new nodes
// in the copied list such that the pointers in the original list and copied
// list represent the same list state. None of the pointers in the new
// list should point to nodes in the original list.

// For example, if there are two nodes X and Y in
// the original list, where X.random --> Y, then for
// the corresponding two nodes x and y in the copied list, x.random --> y.

// Return the head of the copied linked list.

// Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

// Input: head = [[1,1],[2,1]]
// Output: [[1,1],[2,1]]

// Solution: -
// https://leetcode.com/problems/copy-list-with-random-pointer/solutions/4003329/c-2-approaches-o-n-space-and-o-1-space/

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int val;
        Node *next;
        Node *bottom; 
};

void insert_head(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->val = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;

}

void println(Node *node)
{
    while(node != NULL)
    {
        cout<<node->val<<" ";
        node = node->next;
    }
    cout<<endl;
}

Node* copyRandomList(Node* head) 
{
    
        
}



int main(int argc, char const *argv[])
{
    
    return 0;
}
