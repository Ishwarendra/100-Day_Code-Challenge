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
	i64 n;
	std::cin >> n;
	
	if (n < 4 or n % 2)
		std::cout << "-1\n";
	else
	{
		i64 p = n / 2;
		
		i64 x, y;
		
		if (p % 2 == 0)
			x = p / 2;
		else
			x = (p - 3) / 2 + 1;
		
		if (p % 3 == 0)
			y = p / 3;
		else if (p % 3 == 1)
			y = (p - 4) / 3 + 2;
		else
			y = (p - 2) / 3 + 1;
			
		std::cout << y << " " << x << "\n";
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