#include <bits/stdc++.h>
using namespace std;

#define trace(x, y) std::cerr << #x << ": " << x << " " << #y << ": " << y << "\n";

class Solution {
	vector<vector<int>> dirs { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
public:
	int numberOfCells(int n, int m, int r, int c, int u, int d,
	                  vector<vector<char>> &mat)
	{
		auto valid = [&](int i, int j)
		{
			bool cond1 = i >= 0 and j >= 0;
			bool cond2 = i < n and j < m;
			
			return cond1 and cond2 and mat[i][j] == '.';
		};
		
		queue<vector<int>> q;
			
		int cnt = 0;
		
		if (mat[r][c] != '#')
			q.push({r, c, 0, 0}), cnt++;
		
		mat[r][c] == '1';
		
		while (!q.empty())
		{
			auto cur = q.front();
			int i = cur[0], j = cur[1], up = cur[2], down = cur[3];	
			q.pop();
			
			if (valid(i + 1, j) and down != d)
			{
				q.push({i + 1, j, up, down + 1});
				mat[i + 1][j] = '1';
				cnt++;
			}
			
			if (valid(i, j + 1))
			{
				q.push({i, j + 1, up, down});
				mat[i][j + 1] = '1';
				cnt++;
			}
			
			if (valid(i, j - 1))
			{
				q.push({i, j - 1, up, down});
				mat[i][j - 1] = '1';
				cnt++;
			}
			
			if (valid(i - 1, j) and up != u)
			{
				q.push({i - 1, j, up + 1, down});
				mat[i - 1][j] = '1';
				cnt++;
			}
		}
		
		return cnt;
	}
};


int main()
{
	Solution a;
	int n, m, r, c, u, d;
	cin >> n >> m >> r >> c >> u >> d;

	vector<vector<char>> mat(n, vector<char>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mat[i][j];

	cout << a.numberOfCells(n, m , r, c, u, d, mat);

	return 0;
}