#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
	void helper(TreeNode *cur, int &sum)
	{
		if (!cur)
			return;
		
		helper(cur->right, sum);
		sum += cur->val;
		cur->val = sum;
		helper(cur->left, sum);
	}
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        helper(root, sum);
        return root;
    }
};

int main()
{
	
	return 0; 
}    