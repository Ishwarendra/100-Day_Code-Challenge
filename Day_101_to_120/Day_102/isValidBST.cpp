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
	bool isValidBST(TreeNode* root, int lower_lim, int upper_lim)
	{
		if (!root)
			return true;
		
		if (root->val <= upper_lim)
			return false;
		if (root->val >= lower_lim)
			return false;
		
		return isValidBST(root->left, lower_lim, root->val) && 
			   isValidBST(root->right, root->val, upper_lim);
	}
public:
    bool isValidBST(TreeNode* root) {
    	return isValidBST(root, INT_MAX, INT_MIN);
    }
};

int main()
{
	
	return 0; 
}    