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

// If Leaf Node -> simply cur_min and cur_max = min and max of leaf val, cur_min, cur_max respectively
// else see root, cur_min to find cur_min and cur_max and root to find cur_max

class Solution
{
    void pre_process(TreeNode *root, int cur_max, int cur_min)
    {
        if (!root)
            return;

        ans = max({ans, abs(root->val - cur_max), abs(root->val - cur_min)});
        cur_max = max(cur_max, root->val);
        cur_min = min(cur_min, root->val);

        pre_process(root->left, cur_max, cur_min);
        pre_process(root->right, cur_max, cur_min); 
    }

    int ans = 0;

public:
    int maxAncestorDiff(TreeNode *root)
    {
        if (!root)
            return 0;

        pre_process(root, root->val, root->val);
        return ans;
    }
};

int main()
{
    return 0;
}