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
	
	std::vector<std::vector<int>> a(n, std::vector<int>(3));	
	
	for (int i = 0; i < n; ++i)
		std::cin >> a[i][0] >> a[i][1] >> a[i][2];
	
	std::sort(a.begin(), a.end(), 
		[&](const std::vector<int> &a, const std::vector<int> &b)
		{
			if (a[0] != b[0])
				return a[0] > b[0];
				
			if (a[1] != b[1])
				return a[1] > b[1];
			
			return a[2] > b[2];
		});
	
	std::vector<int> max(3, -1);
	
	for (int i = 1; i < n; i++)
	{
		max[0] = std::max(a[i][0], max[0]);
		max[1] = std::max(a[i][1], max[1]);
		max[2] = std::max(a[i][2], max[2]);
	}
	
	if (a[0][0] >= max[0] and a[0][1] >= max[1] and a[0][2] >= max[2])
		std::cout << "YES\n";
	else
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