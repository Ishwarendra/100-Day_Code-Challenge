#include <bits/stdc++.h>

using i64 = long long;
#define trace(x) std::cerr << #x << ": " << x << "\n";

void solve()
{
	int n;
	std::cin >> n;
	
	std::vector<int> a(n), b(n);
	
	for (int i = 0; i < n; i++)	
		std::cin >> a[i];
	
	for (int i = 0; i < n; i++)
	{
		std::cin >> b[i];
		a[i] = a[i] - b[i];
	}
	
	i64 cur_cost = 0LL, min_cost = 7e18, ans = 0; 
	
	for (int i = 0; i < n; i++)
	{
		cur_cost += a[i];
		
		if (cur_cost < min_cost)
			min_cost = cur_cost, ans = i;
	}
	
	trace(ans);
	ans = (ans + 1) % n;
	
	cur_cost = a[ans];
	
	for (int i = ans + 1; i < ans + 1 + n; i++)
	{
		if (cur_cost < 0)
		{
			std::cout << "-1\n";
			return;
		}
		
		cur_cost += a[i % n];
	}
	
	if (cur_cost < 0)
		std::cout << "-1\n";
	else
		std::cout << ans << "\n";
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