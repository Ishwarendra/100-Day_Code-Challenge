#include<bits/stdc++.h>

using i64 = long long;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;
	std::cin >> n;
	
	std::vector<int> f(n);

	for (int i = 0; i < n; i++)
		std::cin >> f[i];
	
	int k;
	std::cin >> k;
	
	std::map<int, int> key;
	
	int total_keys = 0;
	
	for (int i = 0; i < k; i++) 
	{
		int x;
		std::cin >> x;
		
		total_keys += x;
		
		for (int num = 1; num <= x; num++)
			key[num]++;
	}
	
	if (n > total_keys)
	{
		std::cout << "-1\n";
		return 0;
	}
	
	std::sort(f.rbegin(), f.rend());
	
	i64 ans = 0LL;
	
	int i = 0, factor = 1;
	while (i < n)
	{
		while (key[factor] and i < n)
		{
			ans += factor * f[i];
			i++;
			key[factor]--;
		}
		
		factor++;
	}
	
	std::cout << ans << "\n";
	
	return 0;
}