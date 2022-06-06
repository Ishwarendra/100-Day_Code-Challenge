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
	i64 c, h, t;
	std::cin >> h >> c >> t;
	
	auto f = [&](i64 k) -> long double
	{
		return (k * c + k * h + h) / (2.0L * k + 1.0L);	
	};
	
	if (t == h)
		std::cout << "1\n";
	else if (t * 2LL <= (h + c))
		std::cout << "2\n";
	else
	{
		int signDen = (h + c - 2 * t > 0 ? 1 : -1);
		i64 k = (t - h + h + c - 2 * t - signDen) / (h + c - 2 * t);
		
		long double temp1 = f(k);
		long double temp2 = f(k - 1);
		
		print(k)
		
		if (abs(temp1 - t) < abs(temp2 - t))
			std::cout << 2 * k + 1 << "\n";
		else
			std::cout << 2 * k - 1 << "\n";
	}
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