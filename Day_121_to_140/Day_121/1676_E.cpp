#include <bits/stdc++.h>


#ifdef LOCAL
	#include <F:\CPP\Debug\debug.h> 
#else
  #define trace(x...) 1
#endif

void solve()
{
	int n, q;
	std::cin >> n >> q;
	
	std::vector<int> a(n);
	
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	
	std::sort(a.begin(), a.end(), std::greater());
	
	for (int i = 1; i < n; i++)
		a[i] += a[i - 1];	
	
	while (q--)
	{
		int x;
		std::cin >> x;
		
		auto lb = std::lower_bound(a.begin(), a.end(), x);
		
		if (lb == a.end())
			std::cout << "-1\n";
		else
			std::cout << lb - a.begin() + 1 << "\n";
	}
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