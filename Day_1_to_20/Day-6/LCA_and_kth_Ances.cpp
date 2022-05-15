#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode *lowestCommonAncestorInBST(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root)
        return root;
    if (!p and q)
        return q;
    if (p and !q)
        return p;

    // one is lesser than cur_node and other is more_than cur_node
    int val1 = (root->val - p->val);
    int val2 = (root->val - q->val);

    if (val1 * val2 < 0)
        return root;
    else if (val1 > 0 and val2 > 0)
        return lowestCommonAncestor(root->left, p, q);
    else if (val1 < 0 and val2 < 0)
        return lowestCommonAncestor(root->right, p, q);
    else if (val1 == 0 and val2 != 0)
        return p;
    else if (val2 == 0)
        return q;

    return root;
}

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root->val == p->val or root->val == q->val)
        return root;

    TreeNode *a = {nullptr}, *b = {nullptr};

    if (root->left)
        a = lowestCommonAncestor(root->left, p, q);
    if (root->right)
        b = lowestCommonAncestor(root->right, p, q);

    if (a and !b)
        return a;
    else if (!a and b)
        return b;
    else if (!a and !b)
        return NULL;

    return root;
}

class TreeAncestor
{
public:
    vector<vector<int>> dp;
    TreeAncestor(int n, vector<int> &parent)
    {
        dp = vector<vector<int>>(n + 1, vector<int>(21, -1));

        // Base-Case
        for (int i = 0; i < n; i++)
            dp[i][0] = parent[i]; // 1st ancestor is parent

        // for every node get it's one smaller parent
        for (int i = 1; i < 21; i++)
        {
            for (int j = 1; j < n; j++)
            {
                int x = dp[j][i - 1]; // 2^(i - 1)th parent of j
                if (x == -1)
                    dp[j][i] = x;
                else
                    dp[j][i] = dp[x][i - 1];
            }
        }
    }

    int getKthAncestor(int node, int k)
    {
        for (int j = 0; j < 21; j++)
        {
            if (k & (1 << j))
            {
                node = dp[node][j];
                if (node == -1)
                    return node;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

int main()
{
    return 0;
}