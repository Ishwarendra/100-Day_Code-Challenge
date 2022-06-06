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
	
	for (int i = 0; i < 2 * n; i++)
	{
		int x, y;
		char ch;
		
		std::cin >> x >> y >> ch;
		
		if (ch == 'L')
			ch = 'R';
		else
			ch = 'L';
		
		std::cout << x << " " << y << " " << ch << "\n";
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