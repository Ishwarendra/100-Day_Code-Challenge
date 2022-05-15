#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 1e9;

class Solution {
	vector<vector<int>> dirs {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};
public:
	int minimumEffortPath(vector<vector<int>>& heights) {
		int n = heights.size(), m = heights[0].size();

		auto safe = [&](int i, int j)
		{
			return (i >= 0 and j >= 0 and i < n and j < m);
		};

		auto good = [&](int mid)
		{
			vector<vector<int>> vis(n, vector<int>(m));
			queue<pair<int, int>> q;

			q.emplace(0, 0);
			vis[0][0] = 1;

			while (!q.empty())
			{
				auto cur = q.front();
				q.pop();

				if (cur.first == n - 1 and cur.second == m - 1)
					return true;
				for (auto &dir : dirs)
				{
					int i = cur.first + dir[0];
					int j = cur.second + dir[1];


					if (safe(i, j) and !vis[i][j])
					{
						if (abs(heights[i][j] - heights[cur.first][cur.second]) <= mid)
						{
							q.emplace(i, j);
							vis[i][j] = 1;
						}
					}
				}
			}

			return false;
		};

		int left = 0, right = inf;
		int ans = 0;

		while (left <= right)
		{
			int mid = (left + right) / 2;

			if (good(mid))
				right = mid - 1, ans = mid;
			else
				left = mid + 1;
		}

		return ans;
	}
};