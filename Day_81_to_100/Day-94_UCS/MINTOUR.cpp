#include<bits/stdc++.h>

using i64 = long long;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n; 
	std::cin >> n;
	
	std::vector<std::pair<int, int>> a(n);
	
	for (int i = 0; i < n; i++)
		std::cin >> a[i].first >> a[i].second;
	
	i64 days = 0LL;
	
	for (int i = 0; i < n; i++)
	{
		if (a[i].first > days)
			days = a[i].first;
		else
		{
			int ai = a[i].first, di = a[i].second;
			int wait = (days - ai) / di + 1;
			
			if ((days - ai) % di)
				wait = (days - ai + di - 1) / di;
			
			days = ai + wait * di;
		}
	}	
	
	std::cout << days << std::endl;
	
	return 0;
}