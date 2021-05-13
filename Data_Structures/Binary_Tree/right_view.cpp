// Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

// Right view of following tree is 1 3 7 8.

//           1
//        /     \
//      2        3
//    /   \      /    \
//   4     5   6    7
//     \
//      8


// Solution: -

// Very similar to left view we will again use BFS.

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *left, *right;

};


vector <int> right_view(Node *root)
{

    vector<int> res;

    if(root == NULL)
    {
        return res;
    }

    queue<Node*> q;
    q.push(root);

    // BFS Like queue
    while (!q.empty())
    {
        int n = q.size();

        // Traverse all nodes of current level 
        for(int i=1; i<=n; i++)
        {
            Node *temp = q.front();
            q.pop();

            // Print the last element in the node.
            if(i == n)
            {
                res.push_back(temp->data);
            }

            if(temp->left != NULL)
            {
                q.push(temp->left);
            }

            if(temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
    return res;

}

int main(int argc, char const *argv[])
{
    
    return 0;
}


