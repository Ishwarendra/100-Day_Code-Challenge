#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

using i64 = long long;

void solve()
{
	int x, y;
	std::cin >> x >> y;

	i64 ans = x + y;
	
	if (y >= x)
	{
		ans = (x + y) / 2;
		ans += ((y - ans) / x) * x;
	}
	
	assert(ans % x == y % ans);
	std::cout << ans << "\n";
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;

	while (t--)
		solve();

	return 0;
}