#include <bits/stdc++.h>

void solve()
{
	int n;
	std::cin >> n;
	
	std::vector<std::vector<int>> freq(n + 1);
	
	for (int i = 0; i < n; i++)
	{
		int x;
		std::cin >> x;
		
		freq[x].push_back(i);
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (freq[i].size() >= 2)
		{
			if (freq[i].back() - freq[i][0] > 1)
			{
				std::cout << "YES\n";
				return;
			}
		}
	}
	
	std::cout << "NO\n";
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