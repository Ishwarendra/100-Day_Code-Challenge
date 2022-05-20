#include<bits/stdc++.h>

#ifdef LOCAL
	#include <F:\CPP\Debug\debug.h> 
#else
	#define trace(x...) 1;
	#define print(x...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e14;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;
	std::cin >> n;
	
	std::vector<std::vector<std::pair<int, int>>> adj(n);
	std::vector<int> x(n);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int w;
			std::cin >> w;
			
			adj[i].push_back({j, w});
		}
	}
	
	for (int i = 0; i < n; ++i)
	{
		std::cin >> x[i];
		x[i]--;
	}
	
	std::reverse(x.begin(), x.end());
	
	std::vector<std::vector<i64>> d(n, std::vector<i64>(n, inf));
	
	for (int i = 0; i < n; i++)
	{
		d[i][i] = 0;
		
		for (auto [v, w] : adj[i])
			d[i][v] = w;
	}
	
	std::vector<i64> ans(n);
	
	int pos = 0;
	
	for (int k : x)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (d[i][k] != inf and d[k][j] != inf)
					d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
			}
		}
		
		for (int i = 0; i <= pos; i++)
		{
			for (int j = 0; j <= pos; j++)
				if (d[x[i]][x[j]] != inf)
					ans[pos] += d[x[i]][x[j]];
		}
		
		pos++;
	}
	
	std::reverse(ans.begin(), ans.end());
	
	for (int i = 0; i < n; ++i)
		std::cout << ans[i] << " \n"[i == n - 1];
	
	return 0;
}

