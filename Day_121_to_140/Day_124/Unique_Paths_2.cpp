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
	vector<vector<int>> dirs {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
	int uniquePathsWithObstacles(vector<vector<int>>& grid)
	{
		int n = grid.size(), m = grid[0].size();
		vector<vector<int>> dp(n, vector<int>(m));
			
		function<bool(int, int)> bound = [&](int x, int y)
		{
			return x >= 0 and y >= 0 and x < n and y < m;
		};
				
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = m - 1; j >= 0; j--)
			{
				if (grid[i][j] == 1)
					continue;
				if (i ==  n - 1 and j == m - 1)
				{
					dp[i][j] = grid[i][j] == 0;
					continue;
				}
				
				for (auto dir : dirs)
				{
					int x = i + dir[0], y = j + dir[1];
					
					if (bound(x, y))
						dp[i][j] += dp[x][y];
				}
			}
		}
		
		return dp[0][0];
	}
};

int main()
{
	int n, m;
	std::cin >> n >> m;
	
	std::vector<std::vector<int>> grid(n, std::vector<int>(m));
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			std::cin >> grid[i][j];
		
	Solution sol;
	sol.uniquePathsWithObstacles(grid);
	return 0;
}