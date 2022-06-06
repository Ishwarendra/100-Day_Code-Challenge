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
	i64 n;
	std::cin >> n;

	auto s = std::to_string(n);
	int len = s.length();

	std::vector<int> div;

	for (int i = 1; i < len; i++)
		if (len % i == 0)
			div.push_back(i);

	i64 ans = 0;

	for (int num : div)
	{
		if (num == 1 and s[0] == '1'
		        and std::count(s.begin(), s.end(), '0'))
		{
			std::string cur;

			for (int i = 1; i < len; i++)
				cur += '9';

			ans = std::max(ans, std::stoll(cur));
		}
		else
		{
			std::string cur = s.substr(0, num);
			std::string add = cur;

			while (cur.size() < len)
				cur += add;

			i64 m1 = std::stoll(cur);

			if (m1 <= n)
				ans = std::max(ans, m1);

			i64 temp = std::stoll(add);
			temp -= 1;
			cur = std::to_string(temp);
			add = cur;

			while (cur.size() < len)
				cur += add;

			i64 m2 = std::stoll(cur);

			if (m2 <= n)
				ans = std::max(ans, m2);
		}
	}

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