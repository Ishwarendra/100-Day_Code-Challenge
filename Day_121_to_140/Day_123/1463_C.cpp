#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

constexpr i64 inf = 1e12;

template <typename T>
bool between(T a, T b, T c)
{
	return std::min(a, c) <= b and b <= std::max(a, c);
}

template<typename T1, typename T2>
int direction(T1 cur, T2 to_go)
{
	if (cur == to_go)
		return 0;
	else if (cur > to_go)
		return -1;
	else
		return 1;
}

void solve()
{
	int n;
	std::cin >> n;

	std::vector<i64> t(n + 1, inf), x(n + 1);

	for (int i = 0; i < n; i++)
		std::cin >> t[i] >> x[i];

	i64 cur = 0LL, rem = 0LL, dir = 0;
	int success = 0;

	for (int i = 0; i < n; i++)
	{
		// next command
		if (rem == 0)
		{
			rem = abs(cur - x[i]);
			dir = direction(cur, x[i]);
		}
		
		i64 T = std::min(rem, t[i + 1] - t[i]);

		i64 st = cur;
		rem -= T;
		cur += dir * T;

		if (between(st, x[i], cur))
		{
			print(st, x[i], cur);
			success++;
		}
	}

	std::cout << success << "\n";
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