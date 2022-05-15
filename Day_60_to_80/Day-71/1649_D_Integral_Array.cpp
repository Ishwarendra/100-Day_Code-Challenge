#include<bits/stdc++.h>

#define int long long

void solve()
{
	int n, c;
	std::cin >> n >> c;
	
	std::vector<int> cnt(c + 1), prefix(c + 1);
	
	for(int i = 0; i < n; i++)
	{
		int x;
		std::cin >> x;
		
		cnt[x]++;
	}
	
	if (cnt[1] == 0)
	{
		std::cout << "No\n";
		return;
	}
	
	for(int i = 1; i <= c; i++)
		prefix[i] = prefix[i - 1] + cnt[i];
	
	// y * r <= x < y * (r + 1)
	for(int y = 1; y <= c; y++)
	{
		if (not cnt[y])
			continue;
		
		for(int r = 1; r * y <= c; r++)
		{
			int lower_lim = y * r - 1;
			int upper_lim = std::min(c, y * (r + 1) - 1);
			
			int cnt_x = prefix[upper_lim] - prefix[lower_lim]; // occurence of x
			
			if (cnt_x > 0 and not cnt[r])
			{
				std::cout << "No\n";
				return;
			}
		}
	}
	
	std::cout << "Yes\n";
}

int32_t main()
{
	int t;
	std::cin >> t;
	
	while(t--)
		solve();
			
	return 0;
}