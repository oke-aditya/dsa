// https://leetcode.com/problems/leaf-similar-trees/


#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
    public:
        int val;
        TreeNode *left, *right;
};

void dfs(TreeNode *root, vector<int> &res)
{
    if(root == NULL)
        return;
    

    dfs(root->left, res);

    if(root->left == NULL && root->right == NULL)
    {
        res.push_back(root->val);
    }

    dfs(root->right, res);
}


bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> leav1;
    vector<int> leav2;
    
    dfs(root1, leav1);
    dfs(root2, leav2);
    
    // print_v(leav1);
    // print_v(leav2);

    // sort(begin(leav1), end(leav1));
    // sort(begin(leav2), end(leav2));

    // print_v(leav1);
    // print_v(leav2);

    return leav1 == leav2;

}
