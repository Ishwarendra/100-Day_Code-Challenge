#include <bits/stdc++.h>

#define int long long

int _lcm(int a, int b)
{
	return (a * b) / (std::__gcd(a, b));
}

bool good(int mid, std::vector<int> &a, int x, int y)
{
	int n = a.size();
	
	int sum = 0;
	
	for(int i = 0; i < n; i++)
	{
		sum += (mid / a[i]) * y;
		
		if (sum >= x)
			return true;
	}
	
	return sum >= x;
}

void solve()
{
	int n, x, y;
	std::cin >> n >> x >> y;

	std::vector<int> a(n);

	int lcm = 1, sum = 0;

	for (int i = 0; i < n; ++i)
	{
		std::cin >> a[i];
		lcm = _lcm(lcm, a[i]);
	}

	int left = 0, right = 1e8;

	int ans = -1;
	
	while (left <= right)
	{
		int mid = (left + right) / 2;
		
		if (good(mid, a, x, y))
			ans = mid, right = mid - 1;
		else
		{
			left = mid + 1;		
		}
	}
	
	std::cout << ans << "\n";
}

int32_t main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;

	while (t--)
		solve();

	return 0;
}