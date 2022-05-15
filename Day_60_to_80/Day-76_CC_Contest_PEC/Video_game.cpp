#include <bits/stdc++.h>

void solve()
{
	int n, m;
	std::cin >> n >> m;
	
	std::vector<std::vector<int>> adj(n);
	
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		std::cin >> u >> v;
		
		adj[v].push_back(u);
	}
	
	std::vector<int> indeg(n), vis(n);
	
	for(int i = 0; i < n; i++)
	{
		for(int nb : adj[i])
			indeg[nb]++;
	}
	
	std::queue<int> q;
	
	for(int i = 0; i < n; i++)
	{
		if (indeg[i] == 0)
			q.push(i);
	}
	
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		
		vis[cur] = 1;
		
		for(int nb : adj[cur])
		{
			indeg[nb]--;
			if (indeg[nb] == 0)
				q.push(nb);
		}
	}
	
	for (int i = 0; i < n; ++i)
	{
		if (not vis[i])
		{
			std::cout << "No\n";
			return;
		}
	}
	
	std::cout << "Yes\n";
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;
	
	while(t--)
		solve();
	
	return 0;
}