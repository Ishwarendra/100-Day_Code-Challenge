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
	
	int n, k;
	std::cin >> n >> k;
	
	if (n * (n + 1) / 2 == k)
	{
		for (int i = 1; i <= n; ++i)
			std::cout << i << " \n"[i == n];
	}
	else
		std::cout << "-1\n";
	
	return 0;
}