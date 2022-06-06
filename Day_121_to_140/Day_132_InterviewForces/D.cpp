#include<bits/stdc++.h>

#ifdef LOCAL
	#include <F:\CPP\Debug\debug.h> 
#else
	#define trace(x...) 1;
	#define print(x...) 1;
#endif

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, q;
	std::cin >> n;
	
	std::vector<int> h(n);
	
	for (int i = 0; i < n; ++i)
		std::cin >> h[i];
	
	std::cin >> q;
	
	while (q--)
	{
		int l, r;
		std::cin >> l >> r;
		
		l--, r--;
		
		bool done = false;
		
		for (int i = l + 1; i <= r - 1; i++)
		{
			if (h[i] > std::min(h[l], h[r]))
			{
				std::cout << "NO\n";
				done = true;
				break;
			}
		}
		
		if (!done)
			std::cout << "YES\n";
	}
	
	return 0;
}