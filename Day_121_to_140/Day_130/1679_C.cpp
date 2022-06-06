#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

using i64 = long long;

template <typename T>
struct Fenwick
{
	const int n;
	std::vector<T> a;

	Fenwick(int n) : n(n), a(n) {}
	Fenwick(const std::vector<int> inp) : Fenwick(inp.size())
	{
		for (int i = 0; i < n; i++)
			add(i, inp[i]);
	}
	void add(int x, T v)
	{
		for (int i = x + 1; i <= n; i += i & -i) {
			a[i - 1] += v;
		}
	}
	T sum(int x)
	{
		T ans = 0;
		x++;
		for (int i = x; i > 0; i -= i & -i) {
			ans += a[i - 1];
		}
		return ans;
	}
	T rangeSum(int l, int r)
	{
		if (l - 1 < 0)
			return sum(r);

		return sum(r) - sum(l - 1);
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, q;
	std::cin >> n >> q;

	Fenwick<int> ftRow(n), ftCol(n);
	std::vector<int> row(n), col(n);

	while (q--)
	{
		int t;
		std::cin >> t;

		if (t == 1)
		{
			int x, y;
			std::cin >> x >> y;
			x--, y--;

			row[x]++, col[y]++;

			if (row[x] == 1)
				ftRow.add(x, 1);
			if (col[y] == 1)
				ftCol.add(y, 1);
		}

		else if (t == 2)
		{
			int x, y;
			std::cin >> x >> y;
			x--, y--;

			row[x]--, col[y]--;

			if (row[x] == 0)
				ftRow.add(x, -1);
			if (col[y] == 0)
				ftCol.add(y, -1);
		}

		else
		{
			int x1, y1, x2, y2;
			std::cin >> x1 >> y1 >> x2 >> y2;

			x1--, y1--, x2--, y2--;

			int rowSum = ftRow.rangeSum(x1, x2);
			int colSum = ftCol.rangeSum(y1, y2);


			if (colSum == y2 - y1 + 1 or rowSum == x2 - x1 + 1)
				std::cout << "Yes\n";
			else
				std::cout << "No\n";
		}
	}

	return 0;
}