#include<bits/stdc++.h>

int main()
{
	int n;
	std::cin >> n;
	
	std::vector<int> index(n + 1);
		
	for(int i = 0; i < n; i++)
	{
		int x;
		std::cin >> x;
		
		index[x] = i;
	}
	
	long long ans = 0ll;
	
	for(int i = 1; i <= n - 1; i++)
		ans += abs(index[i + 1] - index[i]);
	
	std::cout << ans << "\n";
	
	return 0;
}