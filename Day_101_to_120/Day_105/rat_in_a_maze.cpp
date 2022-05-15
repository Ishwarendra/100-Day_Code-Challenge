#include <bits/stdc++.h>
using namespace std;

#define print(x, y) cout << x << " " << y << "\n";

class Solution
{
	vector<vector<int>> dirs { {1, 0}, { -1, 0}, {0, 1}, {0, -1} };
	vector<char> name {'D', 'U', 'R', 'L'};
	map<char, vector<int>> m;
	vector<vector<int>> original;

	bool isValidPath(string &path)
	{
		int x = 0, y = 0;

		vector<vector<int>> can_go = original; // 1 -> can go, 0 blocked
		
		if (can_go[x][y])
			can_go[x][y] = 0;
		else
			return false;
		
		for (char ch : path)
		{
			auto dir = m[ch];
			
			int i = x + dir[0], j = y + dir[1];
				
			if (can_go[i][j])
				x = i, y = j, can_go[x][y] = 0;
			else
			{
				// print(x, can_go[x][y])
				return false;
			}
		}

		return true;
	}

	bool bound(int i, int j, int n)
	{
		return (i < n and j < n) and (i >= 0 and j >= 0);
	}

	void solve(vector<vector<int>> &grid, vector<string> &ans, string &s, int i, int j)
	{
		int n = grid.size();
		
		if (i == n - 1 && j == n - 1)
		{
			if (isValidPath(s))
				ans.push_back(s);
			return;
		}

		for (int d = 0; d < 4; d++)
		{
			int di = dirs[d][0], dj = dirs[d][1];

			if (bound(i + di, j + dj, n) and grid[i + di][j + dj] == 1)
			{
				grid[i + di][j + dj] = 0;
				s += name[d];
				solve(grid, ans, s, i + di, j + dj);
				grid[i + di][j + dj] = 1;
				s.pop_back();
			}
		}
	}

public:
	vector<string> findPath(vector<vector<int>> &grid, int n) {
		m['D'] = {1, 0};
		m['U'] = { -1, 0};
		m['R'] = {0, 1};
		m['L'] = {0, -1};

		original = grid;

		vector<string> ans;
		string s;
		solve(grid, ans, s, 0, 0);
		return ans;
	}
};


int main()
{
	Solution a;
	int n; cin >> n;

	vector<vector<int>> grid(n, vector<int>(n));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> grid[i][j];

	vector<string> ans = a.findPath(grid, n);
	for (auto s : ans)
		cout << s << '\n';

	return 0;
}