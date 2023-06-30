#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

struct TreeNode 
{
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
    int maxLevelSum(TreeNode* root) 
    {
        int ans = 1;
        int level = 1;
        long long sum = -1e9;

        std::queue<TreeNode *> q;
        q.emplace(root);

        while (!q.empty())
        {
            int sz = std::size(q);
            long long cur_sum = 0;

            for (int i = 0; i < sz; i++)            
            {
                auto cur = q.front();
                q.pop();

                cur_sum += cur->val;
                if (cur->left)
                    q.emplace(cur->left);

                if (cur->right)
                    q.emplace(cur->right);
            }

            if (cur_sum > sum)
                ans = level, sum = cur_sum;

            level++;
        }

        return ans;
    }
};

int main()
{
    return 0;
}