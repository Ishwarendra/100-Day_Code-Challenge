#include <bits/stdc++.h>
using namespace std;

#define LOCAL 1

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

class Solution {
	vector<int> dx { -1, 1, 0, 0},
	       dy {0, 0, -1, 1};

	vector<vector<int>> dp;

	bool bound(int i, int j, vector<vector<int>> &a)
	{
		int n = a.size(), m = a[0].size();

		return i >= 0 and j >= 0 and i < n and j < m;
	}

	int dfs(int i, int j, vector<vector<int>> &m)
	{
		if (dp[i][j] != -1)
			return dp[i][j];

		vector<int> ans(4);

		for (int d = 0; d < 4; d++)
		{
			int x = i + dx[d], y = j + dy[d];

			if (bound(x, y, m) and m[i][j] < m[x][y])
				ans[d] = max(ans[d], dfs(x, y, m));
		}

		return dp[i][j] = 1 + (*max_element(ans.begin(), ans.end()));
	}
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		int n = matrix.size(), m = matrix[0].size();
		dp.resize(n, vector<int>(m, -1));

		int ans = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				ans = max(ans, dfs(i, j, matrix));
		}

		return ans;
	}
};

int main()
{

	return 0;
}