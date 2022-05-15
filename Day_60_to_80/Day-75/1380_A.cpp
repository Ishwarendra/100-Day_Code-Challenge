#include <bits/stdc++.h>

void solve()
{
	int n;
	std::cin >> n;
	
	std::vector<int> a(n);
	
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	
	std::vector<int> pref_min(n), suff_min(n, n - 1);
	
	for(int i = 1; i < n; i++)
	{
		if (a[pref_min[i - 1]] < a[i])
			pref_min[i] = pref_min[i - 1];
		else
			pref_min[i] = i;
	}
	
	for(int i = n - 2; i >= 0; i--)
	{
		if (a[suff_min[i + 1]] < a[i])
			suff_min[i] = suff_min[i + 1];
		else
			suff_min[i] = i;
	}
	
	for(int i = 1; i < n - 1; i++)
	{
		if (a[pref_min[i - 1]] < a[i] and a[i] > a[suff_min[i + 1]])
		{
			std::cout << "YES\n" << pref_min[i - 1] + 1 << " " << i + 1 << " " << suff_min[i + 1] + 1 << "\n";
			return;
		}
	}
	
	std::cout << "NO\n";
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