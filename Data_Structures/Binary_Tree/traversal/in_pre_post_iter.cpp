// Iterative tree traversals

#include<bits/stdc++.h>

using namespace std;

class Node 
{
    public:
        int data;
        Node *left, *right;
};

void pre_order(Node *root)
{
    // Base case
    if(root == NULL) 
    {
        return;
    }

    // Stack of type Node
    stack<Node*> stk;

    stk.push(root);
    
    while (!stk.empty())
    {
        root = stk.top();
        stk.pop();
        cout<<root->data;

        if(root->right != NULL)
            stk.push(root->right);
        
        if(root->left != NULL)
            stk.push(root->left);
        
    }

}

void in_order(Node *root)
{

}

void post_order(Node *root)
{

}


int main(int argc, char const *argv[])
{
    Node *root = new Node();
    root->data = 1;
    root->left = new Node();
    root->right = new Node();
    
    root->left->data = 2;
    root->right->data = 3;

    root->left->left = new Node();
    root->left->right = new Node();
    
    root->left->left->data = 4;
    root->left->right->data = 5;

    cout<<"Pre order traversal "<<endl;
    pre_order(root);
    cout<<endl;

    cout<<"Post order traversal "<<endl;
    post_order(root);
    cout<<endl;

    cout<<"In order traversal "<<endl;
    in_order(root);
    cout<<endl;

    
    return 0;
}
