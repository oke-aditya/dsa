// Write Code to Determine if Two Trees are Identical

// Two trees are identical when they have same data and arrangement of data is also same.

// To identify if two trees are identical, we need to traverse both trees simultaneously,
// and while traversing we need to compare data and children of the trees

// Approach 1
// Recursively check every node.

// sameTree(tree1, tree2)
// 1. If both trees are empty then return 1.
// 2. Else If both trees are non -empty
//      (a) Check data of the root nodes (tree1->data ==  tree2->data)
//      (b) Check left subtrees recursively  i.e., call sameTree( 
//           tree1->left_subtree, tree2->left_subtree)
//      (c) Check right subtrees recursively  i.e., call sameTree( 
//           tree1->right_subtree, tree2->right_subtree)
//      (d) If a,b and c are true then return 1.
// 3  Else return 0 (one is empty and other is not)


#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *left, *right;
};


bool is_identical(Node *t, Node *s)
{
    if(t == NULL && s == NULL)
    {
        return true;
    }

    if(t != NULL & s!= NULL)
    {
        return
        (
            (t->data == s->data) &&
            is_identical(t->left, s->left) &&
            is_identical(t->right, s->right)
        );
    }

    return false;
}


int main(int argc, char const *argv[])
{
    
    return 0;
}



