#include <bits/stdc++.h>

#define int long long

std::vector<std::vector<int>> adj, color;
std::vector<std::pair<int, int>> edges;

int color_cnt = 1;

void dfs(int cur, std::vector<int> &vis)
{
	vis[cur] = 1;
	
	for (int nb : adj[cur])
	{
		if (not vis[nb])
			dfs(nb, vis);
		else if (vis[nb] == 1)
		{
			color_cnt = 2;
			color[cur][nb] = 2;
		}
	}

	vis[cur] = 2;
}

void solve()
{
	int n, m;
	std::cin >> n >> m;
	
	adj.resize(n + 1);
	color.resize(n + 1, std::vector<int>(n + 1, 1));
	
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		std::cin >> u >> v;
		
		edges.emplace_back(u, v);
		adj[u].push_back(v);
	}
	
	std::vector<int> vis(n + 1);
	
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == 0)
			dfs(i, vis);
	}
	
	std::cout << color_cnt << "\n";
	
	for (auto edge : edges)
	{
		int u = edge.first, v = edge.second;
		std::cout << color[u][v] << " ";
	}
	
	std::cout << "\n";
}

int32_t main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	// std::cin >> t;
	
	while(t--)
		solve();
	
	return 0;
}