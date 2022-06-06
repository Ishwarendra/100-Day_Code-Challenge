#include <bits/stdc++.h>

#ifdef LOCAL
	#include <F:\CPP\Debug\debug.h> 
#else
	#define trace(x...) 1;
	#define print(x...) 1;
#endif

void solve()
{
	int n, m;
	std::cin >> n >> m;
	
	std::string s;
	std::cin >> s;
	
	int sz = std::max(n, m);
	
	std::vector<int> row(sz), col(sz);
	
	int col_ans = 0, last_serious = -1e6;
	
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '1')
		{
			last_serious = i;
			
			if (!col[i % m])
				col[i % m] = 1, col_ans++;
		}
		
		if (i - last_serious < m)
			row[i % m]++;
		
		std::cout << row[i % m] + col_ans << " ";
	}
	
	std::cout << "\n";
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