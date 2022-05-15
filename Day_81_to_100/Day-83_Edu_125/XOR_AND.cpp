#include <bits/stdc++.h>

#define int long long

int getBit(int x, int pos)
{
	return (x >> pos) & 1;
}

void solve()
{
	int n;
	std::cin >> n;
	
	std::map<int, int> firstSetBitPos;
		
	for (int _ = 0; _ < n; _++)
	{
		int x;
		std::cin >> x;
		
		for (int i = 30; i >= 0; i--)
		{
			if (getBit(x, i))
			{
				firstSetBitPos[i]++;
				break;
			}
		}
	}
	
	int ans = 0ll;
	
	for (auto i : firstSetBitPos)
		ans += (i.second) * (i.second - 1) / 2;
		
	std::cout << ans << "\n"; 	
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