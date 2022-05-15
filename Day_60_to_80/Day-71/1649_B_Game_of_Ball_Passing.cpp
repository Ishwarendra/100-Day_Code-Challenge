#include<bits/stdc++.h>

#define int long long

void solve()
{
	int n; 
	std::cin >> n;
	
	std::vector<int> a(n);
		
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
	
	std::sort(a.begin(), a.end());
	
	int max_ele = a.back();
	int sum = std::accumulate(a.begin(), a.end(), 0LL);
	
	if (sum == 0)
	{
		std::cout << "0\n";
		return;
	}
	
	std::cout << 1 + std::max(0LL, 2 * max_ele - 1 - sum) << "\n";	
}

int32_t main()
{
	int t; 
	std::cin >> t;
	
	while(t--)
		solve();
	
	return 0;
}