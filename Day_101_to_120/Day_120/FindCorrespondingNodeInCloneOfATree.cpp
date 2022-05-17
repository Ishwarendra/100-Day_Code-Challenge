#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
	TreeNode *helper(TreeNode *root, TreeNode *target)
	{
		queue<TreeNode *> q;
		q.emplace(root);
		
		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();
			
			if (cur->val == target->val)
				return cur;
			
			if (root->left)
				q.emplace(root->left);
			
			if (root->right)
				q.emplace(root->right);
		}
		
		return NULL;
	}
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {
		TreeNode *ans = helper(cloned, target);
		return ans;  
    }
};

int main()
{
	
	return 0; 
}    