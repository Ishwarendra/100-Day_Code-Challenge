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
    const int none_left = -201;
    const int none_right = 201;
    void inorder(TreeNode *root, std::vector<int> &in, int right = true)
    {
        if (!root)
        {
            in.emplace_back(right ? none_right : none_left);
            return;
        }

        inorder(root->left, in, false);
        in.emplace_back(root->val);
        inorder(root->right, in, true);
    }

    std::vector<int> inorder(TreeNode *root)
    {
        std::vector<int> in;
        inorder(root, in);
        return in;
    }
public:
    std::vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        std::map<std::vector<int>, std::vector<TreeNode *>> m;
        std::function<void(TreeNode *)> dfs;
        dfs = [&](TreeNode *root)
        {
            if (!root)
                return;

            m[inorder(root)].emplace_back(root);
            dfs(root->left);
            dfs(root->right);
        }; dfs(root);

        std::vector<TreeNode *> ans;
        for (auto [in, p] : m)
        {
            if (std::size(p) > 1)
                ans.emplace_back(p[0]);
        }

        return ans;
    }
};

int main()
{
    return 0; 
}    