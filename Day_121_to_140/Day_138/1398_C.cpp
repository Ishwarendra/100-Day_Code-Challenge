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
	std::cin >> n;
	
	std::string s;
	std::cin >> s;
	
	std::vector<int> a(n);
	
	for (int i = 0; i < n; ++i)	
		a[i] = s[i] - '0';
	
	for (int i = 0; i < n; ++i)
		a[i]--;
	
	for (int i = 1; i < n; ++i)	
		a[i] += a[i - 1];
	
	std::map<int, int> m;
	i64 cnt = 0;
	print(a);
	for (int i = 0; i < n; i++)
	{
		cnt += a[i] == 0;
		if (m.find(a[i]) != m.end())
			cnt += m[a[i]];
		
		m[a[i]]++;
	}
	
	std::cout << cnt << "\n";
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