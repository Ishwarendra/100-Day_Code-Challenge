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
    int binToDec(string &num)
    {
        int decimal_num = 0;
        for(char &dig : num)
            decimal_num = (decimal_num + (dig - '0'))*2;
        return decimal_num;
    }

    void sumRootToLeafHelper(TreeNode* root, string cur, int &ans)
    {
        if (!root)
            return;

        cur += (root->val == 0) ? '0' : '1'; 
        if (!root->left and !root->right)
        {
            ans += binToDec(cur);
        }

        sumRootToLeafHelper(root->left, cur, ans);
        sumRootToLeafHelper(root->right, cur, ans);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        string cur;
        int ans = 0;
        sumRootToLeafHelper(root, cur, ans);
        return ans/2;
    }
};

int main()
{
    return 0;
}