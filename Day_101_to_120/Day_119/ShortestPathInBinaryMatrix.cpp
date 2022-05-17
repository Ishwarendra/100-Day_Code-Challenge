#include <bits/stdc++.h>
using namespace std;

class Solution {
	vector<vector<int>> dirs { {0, 1}, {0, -1}, {1, 0}, { -1, 0}, {1, 1}, {1, -1}, { -1, 1}, { -1, -1} };
public:
	int shortestPathBinaryMatrix(vector<vector<int>>& grid)
	{
		int n = grid.size(), m = grid[0].size();

		std::function<bool(int, int)> safe = [&](int i, int j)
		{
			return i >= 0 and j >= 0 and i < n and j < m;
		};

		std::queue<std::vector<int>> q;
		std::vector<std::vector<int>> dist(n, std::vector<int>(m, -1));

		if (grid[0][0] == 0)
		{
			q.push({0, 0, 0});
			dist[0][0] = 0;
			grid[0][0] = 1;
		}

		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();

			int d = cur[0];
			int i = cur[1], j = cur[2];

			for (vector<int> &dir : dirs)
			{
				int x = i + dir[0], y = j + dir[1];

				if (safe(x, y) and grid[x][y] == 0)
				{
					dist[x][y] = d + 1;
					q.push({dist[x][y], x, y});
					grid[x][y] = 1;
				}
			}
		}

		return (dist[n - 1][m - 1] == -1 ? -1 : dist[n - 1][m - 1] + 1);
	}
};

int main()
{

	return 0;
}