#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
	#include <F:\CPP\Debug\debug.h> 
#else
  #define debug(x...) 42
#endif

void solve()
{
	int n;
	std::cin >> n;
	
	std::vector<int> a(n);
	
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
		
	int min = *std::min_element(a.begin(), a.end());
	
	i64 sum = 0;	
	
	for (int i = 0; i < n; i++)
		sum += a[i] - min;
	
	std::cout << sum << "\n";
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