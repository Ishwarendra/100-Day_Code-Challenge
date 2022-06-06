#include <bits/stdc++.h>

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
	
	std::vector<std::pair<int, int>> a(n);
	
	for (int i = 0; i < n; ++i)
	{
		std::cin >> a[i].first >> a[i].second;
		a[i].first--, a[i].second--;
	}
	
	std::vector<int> nexts(n);
	
	for (int i = 0; i < n; i++)
	{
		if (a[i].second != -1)
			nexts[a[i].second] = 1;
	}
	
	int tail;
	
	for (int i = 0; i < n; i++)
	{
		if (!nexts[i])
			tail = i;
	}
	
	for (auto &p : a)
	{
		std::swap(p.first, p.second);	
		
		if (p.first == -1)
			p.first = tail, p.second = -1;
	}
	
	for (auto [u, v] : a)
		std::cout << u + 1 << " " << v + 1 << '\n';
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