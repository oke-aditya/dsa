// Given a Binary Tree, print left view of it.
// Left view of a Binary Tree is set of nodes visible when tree is visited from left side.
// Input : 
//                  1
//                /   \
//               2     3
//              / \     \
//             4   5     6             
// Output : 1 2 4

// Input :
//         1
//       /   \
//     2       3
//       \   
//         4  
//           \
//             5
//              \
//                6
// Output :1 2 4 5 6
// 
// 
// Solution: -
// In this method, level order traversal based solution is discussed.
// If we observe carefully, we will see that our main task is to print the left most node of every level.
// So, we will do a level order traversal on the tree and
// print the leftmost node at every level. Below is the implementation of above approach:
// 

#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int data;
        Node *left, *right;
};


vector <int> left_view(Node *root)
{
    vector<int> res;

    // Do a level order (like BFS)
    if(root == NULL)
    {
        return res;
    }

    // q for bfs
    queue<Node*> q;

    q.push(root);

    while (!q.empty())
    {
        // Number of nodes in current level
        int n = q.size();

        // Traverse all nodes of current level
        for(int i=1; i<=n; i++)
        {
            Node *node = q.front();
            q.pop();

            // Left most node.
            if(i == 1)
            {
                res.push_back(node->data);
            }

            if(node->left != NULL)
            {
                q.push(node->left);
            }

            if(node->right != NULL)
            {
                q.push(node->right);
            }
        }
    }
    return res;

}


int main(int argc, char const *argv[])
{
    
    return 0;
}


