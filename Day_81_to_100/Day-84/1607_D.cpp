#include <bits/stdc++.h>

void solve()
{
	int n;
	
	std::cin >> n;
	
	std::vector<std::pair<int, int>> a(n); // Blue -> 0 and Red -> 1
	
	for (int i = 0; i < n; i++)
		std::cin >> a[i].second;
	
	for (int i = 0; i < n; ++i)
	{
		char ch;
		std::cin >> ch;
		
		a[i].first = ch == 'R';
	}
	
	std::sort(a.begin(), a.end());
	
	for (int i = 0; i < n; i++)
	{
		if (a[i].first == 0 and a[i].second < i + 1)
		{
			std::cout << "NO\n";
			return;
		}
		else if (a[i].first == 1 and a[i].second > i + 1)
		{
			std::cout << "NO\n";
			return;
		}
	}
	
	std::cout << "YES\n";
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