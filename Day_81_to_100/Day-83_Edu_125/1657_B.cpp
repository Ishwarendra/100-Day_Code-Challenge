#include <bits/stdc++.h>

void solve()
{
	int n, b, x, y;
	std::cin >> n >> b >>x >> y;
	
	std::vector<int> a(n + 1);
	
	long long sum = 0ll;
	
	for (int i = 1; i <= n; i++)
	{
		if (a[i - 1] + x > b)
			a[i] = a[i - 1] - y, sum += a[i];
		else
			a[i] = a[i - 1] + x, sum += a[i];
	}	
	
	// for (int i : a) std::cout << i << " ";
	
	std::cout << sum << "\n";
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