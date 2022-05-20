#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
	#include <F:\CPP\Debug\debug.h> 
#else
  #define trace(x...) 1
#endif

const i64 inf = i64(1e10);

void solve()
{
	int n, m;
	std::cin >> n >> m;
	
	std::vector<std::vector<int>> grid(n, std::vector<int>(m));
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			std::cin >> grid[i][j];
	
	auto safe = [&](int i, int j)
	{
		return i >= 0 and j >= 0 and i < n and j < m;
	};
			
	auto cost = [&](int i, int j)
	{
		i64 sum = 0;
		
		int x = i, y = j;
		
		while (safe(x, y))
			sum += grid[x][y], x--, y--;
			
		x = i, y = j;
		
		while (safe(x, y))
			sum += grid[x][y], x++, y--;
		
		x = i, y = j;
		
		while (safe(x, y))
			sum += grid[x][y], x--, y++;
		
		x = i, y = j;
		
		while (safe(x, y))
			sum += grid[x][y], x++, y++;
					
		sum -= 3 * grid[i][j];
		
		return sum;
	};			
	
	i64 ans = -inf;	
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			ans = std::max(ans, cost(i, j));
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