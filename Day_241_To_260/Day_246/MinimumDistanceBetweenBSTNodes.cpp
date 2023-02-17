#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define print(...) 1;
#endif

using i64 = long long;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution 
{
    const int inf = 1e9;
    void inorder(TreeNode *root, std::vector<int> &res)
    {
        if (root)
        {
            inorder(root->left, res);
            res.emplace_back(root->val);
            inorder(root->right, res);
        }
    }
public:
    int minDiffInBST(TreeNode* root) 
    {
        auto res = std::vector<int>();
        inorder(root, res);

        int ans = inf;
        for (int i = 0; i + 1 < std::size(res); i++)
            ans = std::min(ans, res[i + 1] - res[i]);

        return ans;     
    }
};

int main()
{
    return 0; 
}    