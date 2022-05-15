#include <bits/stdc++.h>

// using i64 = long long;
#define int long long

std::vector<int> powerOf2;

void preprocess()
{
	int i = 1;
	while (i <= 1e10)
	{
		powerOf2.push_back(i);
		i *= 2;
	}
}

void solve()
{
	int n;
	std::cin >> n;
	
	int ans = 0ll;
	
	int i = 1;
	
	while (powerOf2[i] - 1 <= n * 2)
	{
		// std::cout << i << " ";
		ans += std::min(n, powerOf2[i] - 1) - powerOf2[i - 1];
		i++;
	}
	
	std::cout << ans << "\n";
}

int32_t main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	preprocess();
	
	int t = 1;
	std::cin >> t;
	
	while(t--)
		solve();
	
	return 0;
}