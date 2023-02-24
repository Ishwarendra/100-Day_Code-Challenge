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
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        std::vector<std::vector<int>> ans;
        if (!root)
            return ans;

        std::queue<TreeNode *> q;
        q.emplace(root);

        int reverse = 0;

        while (!q.empty())
        {
            int sz = std::size(q);
            std::vector<int> cur_level;

            for (int i = 0; i < sz; i++)
            {
                auto cur = q.front();
                q.pop();
                cur_level.emplace_back(cur->val);

                if (cur->left)
                    q.emplace(cur->left);
                if (cur->right)
                    q.emplace(cur->right);
            }

            if (reverse)
                std::reverse(std::begin(cur_level), std::end(cur_level));

            reverse ^= 1;
            ans.emplace_back(cur_level);
        }

        return ans;
    }
};
int main()
{
    return 0;
}