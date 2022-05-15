#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
	int n;
	std::cin >> n;
	
	i64 max = 0;
	i64 total_passes = 0;	
	
	for (int i = 0; i < n; i++)
	{
		i64 x;
		std::cin >> x;
		
		total_passes += x;
		max = std::max(x, max);
	}
	
	// std::cout << std::max(1LL, 2 * max - total_passes) << "\n";
	if (total_passes == 0)
		std::cout << "0\n";
	else if (2 * max - total_passes <= 0)
		std::cout << "1\n";
	else
		std::cout << 2 * max - total_passes << "\n";
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