#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define pri64(x...) 1;
#endif

using i64 = long long;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	i64 n, m;
	std::cin >> n >> m;
	
	std::vector<long long> a(n), b(m);
	
	for (i64 i = 0; i < n; ++i)
		std::cin >> a[i];
	
	for (i64 i = 0; i < m; ++i)
		std::cin >> b[i];
	
	i64 g = 0;
			
	for (int i = 0; i < n - 1; ++i)
		g = std::gcd(g, abs(a[i + 1] - a[i]));
		
	for (int i = 0; i < m; ++i)
		std::cout << std::gcd(g, a[0] + b[i]) << " ";
	
	return 0;
}