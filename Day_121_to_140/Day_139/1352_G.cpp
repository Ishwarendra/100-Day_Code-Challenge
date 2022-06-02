#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
	int n;
	std::cin >> n;

	if (n <= 3)
	{
		std::cout << "-1\n";
		return;
	}

	std::deque<int> d;

	d.push_front(4), d.push_front(2);

	for (int i = 1; i <= n; i += 2)
		d.push_back(i);

	for (int i = 6; i <= n; i += 2)
		d.push_front(i);

	for (int i = 1; i < d.size(); i++)
		assert (!(abs(d[i] - d[i + 1]) < 2 and abs(d[i] - d[i + 1]) > 4));

	for (int p : d)
		std::cout << p << " ";
	std::cout << "\n";
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