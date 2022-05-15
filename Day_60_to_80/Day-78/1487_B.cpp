#include <bits/stdc++.h>

void solve()
{
	int n, k;
	std::cin >> n >> k;
	
	if (n % 2 == 0) 
	{
		if (k % n != 0)
			std::cout << k % n << "\n";
		else
			std::cout << n << "\n";
	}
	else
	{
		int offset = (k - 1) / (n / 2);
		int ans = (k + offset) % n;
		
		if (ans == 0)
			std::cout << n << "\n";
		else
			std::cout << ans << "\n";
	}
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