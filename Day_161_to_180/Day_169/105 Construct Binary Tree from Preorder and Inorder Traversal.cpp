#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : 
        val(x), left(left), right(right) {}
};

class Solution 
{
    std::map<int, int> inpos, prepos;
    int n, id;
    TreeNode* build(std::vector<int> &preorder, int left, int right)
    {
        if (left > right or left >= n or right < 0)
            return nullptr;

        int root_val = preorder[id];
        TreeNode *root = new TreeNode(root_val);
        id++;

        root->left = build(preorder, left, inpos[root_val] - 1);
        root->right = build(preorder, inpos[root_val] + 1, right);

        return root;
    }
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) 
    {
        n = std::size(preorder);
        for (int i = 0; i < n; i++)
        {
            prepos[preorder[i]] = i;
            inpos[inorder[i]] = i;
        }

        id = 0;
        return build(preorder, 0, n - 1);
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> p(n), in(n);
    for (int i = 0; i < n; ++i)
        std::cin >> p[i];
    for (int i = 0; i < n; ++i)
        std::cin >> in[i];

    Solution sol;
    
    return 0;
}