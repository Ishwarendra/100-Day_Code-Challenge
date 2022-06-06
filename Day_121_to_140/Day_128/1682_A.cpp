#include <bits/stdc++.h>

#ifdef LOCAL
	#include <F:\CPP\Debug\debug.h> 
#else
	#define trace(x...) 1;
	#define print(x...) 1;
#endif

using i64 = long long;

void solve()
{
	int n;
	std::string s;
	
	std::cin >> n >> s;
	
	i64 ans = 0;
	
	std::vector<bool> good(n); 
	
	for (int i = (n - 1) / 2; i >= 0; i--)	
	{
		if (s[i] == s[(n - 1) / 2])
			good[i] = good[n - i - 1] = true;
		else
			break;
	}
	
	for (int i = 0; i < n; i++)
	{
		if (good[i])
			ans++;
	}	
	
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