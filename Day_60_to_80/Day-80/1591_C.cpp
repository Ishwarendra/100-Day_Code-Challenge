#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
	int n, k; 
	std::cin >> n >> k;
	
	std::vector<int> right, left;
	
	for (int i = 0; i < n; i++)
	{
		int x; 
		std::cin >> x;
		
		if (x >= 0)
			right.push_back(x);
		else
			left.push_back(abs(x));
	}

	std::sort(left.begin(), left.end());
	std::sort(right.begin(), right.end());
	
	i64 ans = 0ll;
	
	int l = left.size(), r = right.size();
	
	for (int i = l - 1; i >= 0; i -= k)
		ans += 2 * left[i];
	
	for (int i = r - 1; i >= 0; i -= k)
		ans += 2 * right[i];
	
	if (left.empty())
		ans -= right.back();
	else if (right.empty())
		ans -= left.back();
	else
		ans -= std::max(left.back(), right.back());
	
	std::cout << ans << "\n";
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;
	
	while(t--)
		solve();
	
	return 0;
}