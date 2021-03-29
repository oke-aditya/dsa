// Given a linked list,
// return the node where the cycle begins. If there is no cycle, return null.
// 
// There is a cycle in a linked list if there is some node in the
//  list that can be reached again by continuously
// following the next pointer.
// Internally, pos is used to denote the index of the
// node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
// Notice that you should not modify the linked list.

// Input: head = [3,2,0,-4], pos = 1
// Output: tail connects to node index 1
// Explanation: There is a cycle in the linked list, where tail connects to the second node.

// Input: head = [1,2], pos = 0
// Output: tail connects to node index 0
// Explanation: There is a cycle in the linked list, where tail connects to the first node.

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

int main(int argc, char const *argv[])
{
    
    return 0;
}

