#include<bits/stdc++.h>

using i64 = long long;

int main()
{
	int n;
	std::cin >> n;
	
	i64 sum = 0ll;
	
	for (int i = 0; i < n - 1; ++i)
	{
		int x;
		std::cin >> x;
		
		sum += x;
	}
	
	std::cout << n * (n + 1) / 2 - sum << "\n";
	
	return 0;
}