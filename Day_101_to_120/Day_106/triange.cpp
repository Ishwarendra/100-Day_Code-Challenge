#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 1e9;

class Solution {
	vector<vector<int>> dp;
	int f(int i, int j, vector<vector<int>> &a)
	{
		if (i >= a.size() or j >= a[i].size())
			return inf;
		
		if (i == int(a.size()) - 1)
			return a[i][j];
		
		if (dp[i][j] != inf)
			return dp[i][j];
		
		int right = a[i][j] + f(i + 1, j + 1, a);
		int down = a[i][j] + f(i + 1, j, a);
		
		return dp[i][j] = min(right, down);
	}
	
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		dp.resize(n, vector<int>(n, inf));
		
		return f(0, 0, triangle);
	}
};

int main()
{

	return 0;
}