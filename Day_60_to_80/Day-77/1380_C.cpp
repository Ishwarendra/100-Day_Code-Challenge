#include <bits/stdc++.h>

void solve()
{
	int n, x;
	std::cin >> n >> x;
	
	std::vector<std::pair<int, int>> a(n);
	
	for(int i = 0; i < n; i++)
	{
		std::cin >> a[i].second;
		a[i].first = std::max(1, (x + a[i].second - 1) / a[i].second);
	}	
	
	std::sort(a.begin(), a.end());
	
	int start = -1, ans = 0;
	
	for(int i = 0; i < n; i++)	
	{
		int have = i - start, need = a[i].first;
		
		if (have >= need)
		{
			ans++;
			start = i;
		}
	}
	
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