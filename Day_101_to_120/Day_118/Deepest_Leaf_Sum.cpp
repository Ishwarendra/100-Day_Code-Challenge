#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	
	TreeNode() 
		: val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) 
		: val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) 
		: val(x), left(left), right(right) {}
};

class Solution {
public:
	int deepestLeavesSum(TreeNode* root) {
		vector<pair<int, int>> a;
			
		std::function<void(TreeNode *, int)> dfs = [&](TreeNode *cur, int dep)
		{
			if (!cur)
				return;
				
			a.emplace_back(dep, cur->val);
			
			if (cur->left)
				dfs(cur->left, dep + 1);
			if (cur->right)
				dfs(cur->right, dep + 1);
						
		};
		
		dfs(root, 0);
		sort(a.begin(), a.end(), greater<pair<int, int>>());
		
		int max_dep = a[0].first;
		int sum = 0;
		
		for (int i = 0; i < a.size(); i++) 
		{
			if (a[i].first == max_dep)	
				sum += a[i].second;
			else
				break;
		}
		
		return sum;
	}
};

int main()
{

	return 0;
}