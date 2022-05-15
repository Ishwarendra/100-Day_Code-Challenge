#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void invertTreeAux(TreeNode *root)
    {
        if (!root)
            return;
        swap(root->left, root->right);
        if (root->left)
            invertTreeAux(root->left);
        if (root->right)
            invertTreeAux(root->right);
            
    }
    
    TreeNode* invertTree(TreeNode* root) {
        invertTreeAux(root);
        return root;
    }
};

int main()
{
    return 0;
}