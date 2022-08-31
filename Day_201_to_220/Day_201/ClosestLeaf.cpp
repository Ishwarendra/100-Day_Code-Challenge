#include <bits/stdc++.h>
using namespace std;

#define LOCAL 1

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
    TreeNode(int data, TreeNode *left, TreeNode *right) : data(data), left(left), right(right){}
};

TreeNode* find(TreeNode *root, int k, map<TreeNode*, TreeNode*> &par)
{
    TreeNode *weightK = root;
    TreeNode *it = nullptr;

    if (root->left)
    {
        par[root->left] = root;
        it = find(root->left, k, par);
        
        if (it->data == k)
            weightK = it;
    }

    if (root->right)
    {
        par[root->right] = root;
        it = find(root->right, k, par);

        if (it->data == k)
            weightK = it;
    }

    return weightK;
}

int closestLeaf(TreeNode *root, int k)
{
    if (!root)
        return -1;

    if (!root->left and !root->right)
        return 0;

    map<TreeNode*, TreeNode*> par;
    TreeNode *weightK = find(root, k, par);

    queue<TreeNode*> q;
    map<TreeNode*, int> vis;

    vis[weightK] = 1;
    q.emplace(weightK);

    while (!q.empty())
    {
        TreeNode *cur = q.front();
        q.pop();

        if (!cur->left and !cur->right)
            return d[cur];

        // Left
        if (cur->left and vis.find(cur->left) == vis.end())
        {
            q.emplace(cur->left);
            vis[cur->left] = vis[cur] + 1;
        }

        // Right
        if (cur->right and vis.find(cur->right) == vis.end())
        {
            q.emplace(cur->right);
            vis[cur->right] = vis[cur] + 1;
        }

        // Up
        if (par.find(cur) != par.end() and vis.find(par[cur]) == vis.end())
        {
            q.emplace(par[cur]);
            vis[par[cur]] = vis[cur] + 1;
        }
    }

    return 0; // If answer exists it will never come here
}

int main()
{
//     TreeNode *root = new TreeNode(5);
//     root->left = new TreeNode(6);
//     root->right = new TreeNode(3);
//     root->left->left = new TreeNode(4);
//     root->left->right = new TreeNode(2);
//     root->right->left = new TreeNode(1);
//     root->right->right = new TreeNode(9);

//     std::cout << closestLeaf(root, 3);

    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(5);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(3);

    root->left->left->left = new TreeNode(9);
    root->left->left->right = new TreeNode(11);

    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(14);

    root->left->left->left->left = new TreeNode(10);

    root->left->left->right->left = new TreeNode(12);
    root->left->left->right->right = new TreeNode(15);

    root->left->right->left->right = new TreeNode(16);

    root->left->right->right->left = new TreeNode(18);

    std::cout << closestLeaf(root, 5);
    return 0;
}