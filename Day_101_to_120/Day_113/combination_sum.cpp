#include <bits/stdc++.h>
using namespace std;

class Solution {
	void f(vector<int> &a, int b, int id, vector<vector<int>> &complete_ans, vector<int> &ans)
	{
		int n = a.size();
		if (b == 0)
		{
			complete_ans.push_back(ans);
			return;
		}

		for (int i = id; i < a.size(); i++)
		{
			if (b - a[id] < 0)
				return;

			ans.push_back(a[id]);
			f(a, b - a[id], id, complete_ans, ans);

			id++;
			ans.pop_back();
		}
	}
public:
	vector<vector<int>> combinationSum(vector<int> &A, int B) {
		set<int> temp(A.begin(), A.end());
		A.clear();

		for (int ele : temp)
			A.push_back(ele);

		vector<vector<int>> complete_ans;
		vector<int> ans;

		f(A, B, 0, complete_ans, ans);

		return complete_ans;
	}
};


int main()
{

	return 0;
}