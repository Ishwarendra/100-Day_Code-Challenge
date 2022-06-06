#include <bits/stdc++.h>

// #define LOCAL

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

using i64 = long long;

void solve()
{
	int n, k;
	std::cin >> n >> k;
	
	std::vector<int> adj[n];
	
	int x, y;
	std::cin >> x >> y;
	x--, y--;
	
	std::vector<int> a(k);
	
	for (int i = 0; i < k; ++i)
	{
		std::cin >> a[i];
		a[i]--;
	}
	
	a.push_back(y);
	
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		std::cin >> u >> v;
		
		adj[--u].push_back(--v);
		adj[v].push_back(u);
	}
	
	i64 ans = 0;
	std::vector<int> depth(n), par(n);
	
	std::function<void(int, int, int)> dfs = [&](int u, int p, int d)
	{
		depth[u] = d;
		par[u] = p;
				
		for (int v : adj[u])
		{
			if (v != p)
				dfs(v, u, d + 1);
		}
	};
	
	dfs(x, -1, 0);
	std::vector<int> vis(n);
	vis[x] = 1;
	
	for (int u : a)
	{
		while (!vis[u])
		{
			vis[u] = 1;
			ans += 2;
			u = par[u];
		}
	}
	print(depth)
	std::cout << ans - depth[y] << "\n";
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