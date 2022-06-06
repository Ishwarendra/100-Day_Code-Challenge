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
	
	for (int i = 0; i < n; ++i)	
		std::cin >> a[i];
	
	if (n == 2 and a[0] == 1 and a[1] == 1)
	{
		std::cout << "0\n";
		return;
	}
	
	std::vector<int> b(a.begin(), a.end());
	
	std::sort(b.begin(), b.end());
	
	int x = -1;
	
	for (int i = 0; i < n; i++)
	{
		if (a[i] != b[i]) 
		{
			if (x == -1)
				x = a[i];
			else
				x &= a[i];
		}
	}
	
	std::cout << x << "\n";
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