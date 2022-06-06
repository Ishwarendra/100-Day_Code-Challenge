#include <bits/stdc++.h>
using namespace std;

#define LOCAL 1

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif


struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void bfs(TreeNode *root, ListNode *head, std::queue<TreeNode *> &all_head)
    {
        std::queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();

            if (cur->val == head->val)
                all_head.emplace(cur);

            if (cur->left)
                q.emplace(cur->left);
            if (cur->right)
                q.emplace(cur->right);
        }
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) 
    {
        std::queue<TreeNode *> q;
        bfs(root, head, q);

        std::function<bool(TreeNode *, ListNode *)> dfs;

        dfs = [&](TreeNode *cur, ListNode *to_find)
        {
            if (!to_find) // LL exhausted
                return true;

            if (!cur) // BT exhausted LL not
                return false;

            if (cur->val != to_find->val) // everyday we further stray away from LL
                return false;

            if (cur->left)
            {
                bool can_go = dfs(cur->left, to_find->next);

                if (can_go)
                    return true;
            }

            if (cur->right)
            {
                bool can_go = dfs(cur->right, to_find->next);

                if (can_go)
                    return true;
            }

            return (to_find->next ? false : true);
        };

        while (!q.empty())
        {
            bool can = dfs(q.front(), head);
            q.pop();

            if (can)
                return true;
        }

        return false;
    }
};

int main()
{
    return 0;
}