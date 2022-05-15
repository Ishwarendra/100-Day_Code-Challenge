#include <bits/stdc++.h>

void solve()
{
	int n;
	std::cin >> n;
	
	std::vector<int> a(n);
	
	for (int i = 0; i < n; ++i)		
		std::cin >> a[i];
	
	std::sort(a.begin(), a.end());
	
	std::cout << a[n - 1] + a[n - 2] << "\n";
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