#include <bits/stdc++.h>

#ifdef LOCAL
	#include <F:\CPP\Debug\debug.h> 
#else
	#define trace(x...) 1;
	#define print(x...) 1;
#endif

int f(int x)
{
	int pos = 0;
	for (int i = 0; i < 31; i++)
	{
		if ((x >> i) & 1)
		{
			pos = i;
			break;
		}
	}
	
	x += (1 << pos);
	
	return x;
}

void solve()
{
	int a, b;
	std::cin >> a >> b;
	
	int ans = b - a;
	
	int new_a = a;
	
	while (new_a <= b)
	{
		int x = new_a - a;
		
		for (int y = 0; y < b - a; y++)
			ans = std::min(ans, x + y + 1 + ((a + x) | (b + y)) - (b + y));
		
		// new_a = (new_a | (new_a - 1)) + 1;
		new_a = f(new_a);
	}
	
	std::cout << ans << '\n';
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