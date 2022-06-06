#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

const int inf = 1e9;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::vector<std::string> a(n);

	for (int i = 0; i < n; ++i)
		std::cin >> a[i];

	std::vector<std::vector<int>> distance(n, std::vector<int>(n));

	auto weight = [&](std::string &a, std::string &b) -> int
	{
		int ans = -1;
		
		for (int i = 0; i < m; i++)
			ans = std::max(ans, abs(a[i] - b[i]));
		
		return ans;
	};

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			distance[i][j] = weight(a[i], a[j]);
			distance[j][i] = distance[i][j];
		}
	}
	
	auto prims = [&](int src)
	{
		std::set<std::vector<int>> s;
		s.insert({0, src});
		
		int mstCost = 0;
		
		std::vector<int> Tprim(n);
		
		while (!s.empty())	
		{
			auto cur = *s.begin();
			int u = cur[1], w = cur[0];
			s.erase(cur);
			
			if (Tprim[u])
				continue;
			
			Tprim[u] = 1;
			mstCost = std::max(mstCost, w);
			
			for (int i = 0; i < n; ++i)
			{
				if (!Tprim[i])
					s.insert({distance[u][i], i});
			}
		}
		
		return mstCost;
	};
	
	int ans = prims(0);
	
	std::cout << ans << '\n';

	return 0;
}