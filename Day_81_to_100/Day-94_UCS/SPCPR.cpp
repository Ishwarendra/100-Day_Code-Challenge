#include<bits/stdc++.h>

int n, m;
std::vector<std::vector<std::string>> grid;

std::vector<int> dy { 0, 1, 0, -1 },
				 dx { -1, 0, 1, 0 };

bool bound(int i, int j)
{
	return i >= 0 and j >= 0 and i < n and j < m;
}

void dfs(int i, int j, std::vector<std::vector<bool>> &vis, int &cnt)
{	
	cnt++;
	vis[i][j] = true;
	
	for (int d = 0; d < 4; d++)
	{
		int new_i = i + dx[d], new_j = j + dy[d];
		
		if (not bound(new_i, new_j))
			continue;
		if (vis[new_i][new_j])
			continue;
		
		if (grid[i][j][d] == '0')
			dfs(new_i, new_j, vis, cnt);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> n >> m;
	
	grid.resize(n, std::vector<std::string>(m));
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			std::cin >> grid[i][j];
	}
	
	std::vector<int> components;
	std::vector<std::vector<bool>> vis(n, std::vector<bool>(m));
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (not vis[i][j])
			{
				int cnt = 0;
				dfs(i, j, vis, cnt);
				if (cnt)
					components.push_back(cnt);
			}
		}
	}
	
	std::sort(components.begin(), components.end());
	
	int ans = INT_MIN, max = 0;
	
	for (int i = 0; i < components.size(); i++)
	{
		if (i % 2)
			max -= components[i];
		else
			max += components[i];
		
		ans = std::max(max, ans);
		
		if (max < 0)
			max = 0;
	}
	
	std::cout << ans << "\n";
	
	return 0;
}