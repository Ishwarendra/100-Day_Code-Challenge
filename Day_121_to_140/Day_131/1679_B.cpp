#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

using i64 = long long;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, q;
	std::cin >> n >> q;

	std::vector<int> a(n);

	for (int i = 0; i < n; ++i)
		std::cin >> a[i];

	std::vector<int> firstChange(n, -1);
	std::pair<int, int> secondChange { -1, -1};

	i64 sum = std::accumulate(a.begin(), a.end(), 0LL);

	for (int pos = 1; pos <= q; pos++)
	{
		int t;
		std::cin >> t;

		if (t == 1)
		{
			int i, x;
			std::cin >> i >> x;
			i--;

			if (firstChange[i] >= secondChange.first)
				sum += x - a[i];
			else
				sum += x - secondChange.second;

			firstChange[i] = pos;
			a[i] = x;
		}
		else
		{
			int x;
			std::cin >> x;

			sum = 1LL * n * x;
			secondChange = {pos, x};
		}

		std::cout << sum << "\n";
	}

	return 0;
}