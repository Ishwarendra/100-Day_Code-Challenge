#include<bits/stdc++.h>

#define int long long

void solve()
{
	int n, m, k;
	std::cin >> n >> m >> k;

	if (n == 1 and m == 0)
	{
		std::cout << (k - 2 >= 0 ? "Yes\n" : "No\n");
		return;
	}

	if (m > n * (n - 1) / 2 or m < n - 1)
		std::cout << "No\n";
	else if (m == n * (n - 1) / 2)
		std::cout << (k - 2 >= 1 ? "Yes\n" : "No\n");

	else
	{
		std::cout << (k - 2 >= 2 ? "Yes\n" : "No\n");
	}

}

int32_t main()
{
	int t;
	std::cin >> t;

	while (t--)
		solve();

	return 0;
}