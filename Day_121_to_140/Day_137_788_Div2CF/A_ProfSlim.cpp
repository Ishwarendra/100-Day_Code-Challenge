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
	
	std::vector<int> a(n);
	
	int pos = 0, neg = 0;
	
	for (int i = 0; i < n; ++i)	
	{
		std::cin >> a[i];
		pos += a[i] > 0;
		neg += a[i] < 0;
	}
	
	for (int i = 0; i < neg; i++)
		a[i] = -1 * abs(a[i]);
	
	for (int i = neg; i < n; ++i)
		a[i] = abs(a[i]);
	
	if (std::is_sorted(a.begin(), a.end()))
		std::cout << "YES\n";
	else
		std::cout << "NO\n"
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