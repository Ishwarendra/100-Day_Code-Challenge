#include <bits/stdc++.h>

#define LOCAL 1

#ifdef LOCAL
	#include <F:\CPP\Debug\debug.h> 
#else
	#define trace(x...) 1;
	#define print(x...) 1;
#endif

void solve()
{
	int n;
	std::cin >> n;
	
	std::vector<std::vector<int>> adj(n + 1);
	
	for (int i = 2; i <= n; i++)
	{
		int p; 
		std::cin >> p;
		
		adj[p].push_back(i);
		adj[i].push_back(p);
	}
	
	std::string s;
	std::cin >> s;
	
	s = '1' + s;
	
	std::vector<bool> vis(n + 1);
	std::vector<std::pair<int, int>> bw(n + 1, {0, 0});
	bw[0] = {-1, -2};
	
	std::function<void(int)> dfs = [&](int i)
	{
		vis[i] = true;
		
		if (s[i] == 'B')
			bw[i].first++;
		else
			bw[i].second++;
		
		for (int nb : adj[i])
		{
			if (not vis[nb])
			{
				dfs(nb);
				bw[i].first += bw[nb].first;
				bw[i].second += bw[nb].second;
			}
		}	
	};
	
	int cnt = 0;
	dfs(1);
	
	print(bw)
	
	for (auto &p : bw)
	{
		if (p.first == p.second)
			cnt++;
	}	
	
	std::cout << cnt << "\n";
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