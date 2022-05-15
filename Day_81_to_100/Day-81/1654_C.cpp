#include <bits/stdc++.h>

#define int long long

void solve()
{
	int n;
	std::cin >> n;
	
	std::multiset<int, std::greater<int>> a, q;
	
	int maibi_this = 0;
	
	for (int i = 0; i < n; ++i)
	{
		int x;
		std::cin >> x;
		
		maibi_this += x;
		a.insert(x);
	}
	
	q.insert(maibi_this);
	
	while (!q.empty())
	{
		auto cur = q.begin();
		
		if (*cur < *a.begin())
		{
			std::cout << "NO\n";
			return;
		}
		
		if (a.find(*cur) != a.end())
		{
			a.erase(a.find(*cur));
			q.erase(cur);
		}
		else
		{
			// q.erase(cur) f
			q.insert((*cur) / 2);
			q.insert((*cur + 1) / 2);
			q.erase(cur); // Erase later 
		}
	}
	
	if (a.empty())
		std::cout << "YES\n";
	else
		std::cout << "NO\n";
}

int32_t main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;
	
	while(t--)
		solve();
	
	return 0;
}