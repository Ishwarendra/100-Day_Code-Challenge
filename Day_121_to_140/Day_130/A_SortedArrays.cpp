#include<bits/stdc++.h>

#define LOCAL

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
	
	int n;
	std::cin >> n;
	
	std::vector<int> a(n);
	
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	
	if (n <= 2)
	{
		std::cout << "1\n";
		return 0;
	}
	
	bool inc = false, dec = false;
	int ans = 1;
	
	for (int i = 1; i < n; ++i)
	{
		if (a[i] > a[i - 1])
			inc = true;
		
		if (a[i] < a[i - 1])
			dec = true;
			
		if (inc and dec)
			inc = false, dec = false, ans++;
	}
	
	std::cout << ans << "\n";
	
	return 0;
}