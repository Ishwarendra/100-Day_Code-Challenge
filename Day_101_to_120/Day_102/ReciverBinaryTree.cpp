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
	void inorder(TreeNode *&root, std::vector<int> &ans)
	{
		if (!root)
			return;
		
		inorder(root->left, ans);
		ans.push_back(root->val);
		inorder(root->right, ans);
	}
	
	TreeNode* &find(TreeNode *&root, int x)
	{
		if (!root)
			return root;
		
		if (root->val == x)
			return root;
		else if (root->val < x)
			return find(root->right, x);
		
		return find(root->left, x);
	}
	
	bool minima(std::vector<int> &a, int i)
	{
		int n = a.size();
		
		int prev = (i == 0 ? INT_MAX : a[i - 1]);
		int next = (i == n - 1 ? INT_MAX : a[i + 1]);
		
		return a[i] < prev and a[i] < next;
	}
	
	bool maxima(std::vector<int> &a, int i)
	{
		int n = a.size();
		
		int prev = (i == 0 ? INT_MAX : a[i - 1]);
		int next = (i == n - 1 ? INT_MAX : a[i + 1]);
		
		return a[i] > prev and a[i] > next;
	}
public:
    void recoverTree(TreeNode* root) {
        std::vector<int> in;
        inorder(root, in);
        
        int n = in.size();
		
		int f = -1, s = -1;        
        
        for (int i = 0; i < n; i++)
        {
        	if (minima(in, i))
        		f = i;
        	if (maxima(in, i))
        		s = i;
        }
        
        auto to_swap1 = find(root, in[f]);
        auto to_swap2 = find(root, in[s]);
        
        swap(to_swap1->val, to_swap2->val);
    }
};

int main()
{
	
	return 0; 
}    