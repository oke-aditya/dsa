/*

// https://leetcode.com/problems/path-sum/
Given a tree and a sum, return true if there is a path from the root
down to a leaf, such that adding up all the values along the path
equals the given sum.
 
Strategy: subtract the node value from the sum when recurring down,
and check to see if the sum is 0 when you run out of tree.
*/

#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int data;
        Node *left, *right;
};

bool has_path_sum(Node *root, int sum)
{
    if(root == NULL)
    {
        return (sum == 0);
    }

    else
    {
        bool ans = false;
        int remaining = sum - root->data;

        // if the remaining is 0 and we have reached end of path
        if(remaining == 0 && root->left == NULL && root->right == NULL)
        {
            return true;
        }

        // Othwerwise check both tree. Since either will be left.
        if(root->left)
        {
            ans = ans || has_path_sum(root->left, remaining);
        }

        if(root->right)
        {
            ans = ans || has_path_sum(root->right, remaining);
        }
        return ans;
    }
}


int main(int argc, char const *argv[])
{
    
    return 0;
}


