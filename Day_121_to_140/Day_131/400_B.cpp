#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::vector<std::string> a(n);

	for (int i = 0; i < n; ++i)
		std::cin >> a[i];

	std::set<int> ans;

	for (auto &row : a)
	{
		int dwarf = -1, candy = -1;

		for (int i = 0; i < row.size(); i++)
		{
			if (row[i] == 'G')
				dwarf = i;
			if (row[i] == 'S')
				candy = i;
		}

		if (dwarf > candy)
		{
			std::cout << "-1\n";
			return 0;
		}

		ans.emplace(dwarf - candy);
	}

	std::cout << ans.size() << "\n";

	return 0;
}