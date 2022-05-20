#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
	#include <F:\CPP\Debug\debug.h> 
#else
  #define trace(x...) 42
#endif

void solve()
{
	int n, m;
	std::cin >> n >> m;
	
	std::vector<std::string> a(n);
	
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	
	std::function<int(std::string &, std::string &)> f = [&](std::string &a, std::string &b)
	{
		int cost = 0;
		for (int i = 0; i < m; i++)
			cost += abs(a[i] - b[i]);
		
		return cost;
	};	
	
	i64 ans = (i64)1e9;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
			ans = std::min(ans, f(a[i], a[j]) * 1LL);
	}	
	
	std::cout << ans << "\n";
	trace("hehe");
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