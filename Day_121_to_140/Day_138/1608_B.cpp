#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void f(std::vector<int> &a, int c)
{
	if (!c)
		return;

	int n = a.size();
	for (int i = 0; i < n; i++)
		a[i] = n - a[i] + 1;

	std::reverse(a.begin(), a.end());
}

void solve()
{
	int n, a, b;
	std::cin >> n >> a >> b;

	if (abs(a - b) > 1 or a > (n - n % 2) / 2
	        or b > (n - n % 2) / 2 or a + b > n - 2)
	{
		std::cout << "-1\n";
		return;
	}

	int comple = a > b;
	int maxima = std::min(a, b), minima = std::max(a, b);

	std::vector<int> ans(n);

	if (minima != maxima)
	{
		std::iota(ans.begin(), ans.end(), 1);
		int cur = minima + maxima + 1;
		ans[0] = cur + 1;

		for (int i = 1; i <= maxima + 1; i++)
			ans[2 * i] = cur--;

		cur = 1;

		for (int i = 0; i < minima; i++)
			ans[2 * i + 1] = cur++;

	}
	else if (minima != 0)
	{
		int cur = maxima + minima + 2;
		int st = cur + 1;

		for (int i = 0; i <= minima; i++)
			ans[2 * i + 1] = cur--;

		cur = 1;

		for (int i = 0; i <= maxima; ++i)
			ans[(2 * i)] = cur++;

		for (int i = maxima + minima + 2; i < n; i++)
			ans[i] = i + 1;
	}
	else
		std::iota(ans.begin(), ans.end(), 1);

	f(ans, comple);

	for (int i : ans)
		// assert(i != 0);
		std::cout << i << " ";
	std::cout << '\n';
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