#include <bits/stdc++.h>

using i64 = long long;

i64 square(int x)
{
	return 1ll * x * x;
}

void solve()
{
	int c, sum;
	std::cin >> c >> sum;

	i64 type_1 = c - sum % c;
	i64 type_2 = sum % c;
	
	std::cout << type_1 * square(sum / c) + type_2 * square((sum / c) + 1) << "\n";
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