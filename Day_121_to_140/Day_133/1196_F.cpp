#include<bits/stdc++.h>

#ifdef LOCAL
	#include <F:\CPP\Debug\debug.h> 
#else
	#define trace(x...) 1;
	#define print(x...) 1;
#endif

using i64 = long long;

const i64 inf = 1e15;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m, k;
	std::cin >> n >> m >> k;
	
	std::vector<std::vector<i64>> a;
	std::map<int, int> mp;
	
	int cur = 0;
	
	for (int i = 0; i < m; ++i)
	{
		i64 x, y, w;
		std::cin >> x >> y >> w;
		
		a.push_back({w, x, y});
	}
	
	std::sort(a.begin(), a.end());
	a.resize(std::min(m, k));
	
	for (auto &p : a)
	{
		if (!mp.count(p[2]))
			mp[p[2]] = cur++;
		if (!mp.count(p[1]))
			mp[p[1]] = cur++;
	}
	
	n = cur;
	std::vector<std::vector<long long>> distance(n, 
		std::vector<long long>(n, inf));
		
	for (auto p : a)
	{
		distance[mp[p[1]]][mp[p[2]]] = p[0]; 
		distance[mp[p[2]]][mp[p[1]]] = p[0];
	}
	
	
	for (int p = 0; p < n; p++)
	{
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				distance[i][j] = std::min(distance[i][j],
					distance[i][p] + distance[p][j]);
	}
	
	std::vector<i64> ans;
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
			ans.push_back(distance[i][j]);
	}
	
	std::sort(ans.begin(), ans.end());
	
	std::cout << ans[k - 1] << "\n";
	
	return 0;
}