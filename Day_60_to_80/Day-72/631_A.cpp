#include<bits/stdc++.h>

using i64 = long long;

int main()
{
	int n; 
	std::cin >> n;
	
	i64 ans1 = 0LL, ans2 = 0LL;
	
	for(int i = 0; i < n; i++)	
	{
		int x;
		std::cin >> x;
		
		ans1 |= x;
	}
	
	for(int i = 0; i < n; i++)	
	{
		int x;
		std::cin >> x;
		
		ans2 |= x;
	}
	
	std::cout << ans1 + ans2 << "\n";
	
	return 0;
}