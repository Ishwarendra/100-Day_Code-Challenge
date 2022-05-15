#include<bits/stdc++.h>

using i64 = long long;

constexpr int color_limit = 1e5 + 1;
std::vector<std::vector<int>> x(color_limit), y(color_limit);

i64 distance_sum(std::vector<int> &a)
{
	std::sort(a.begin(), a.end());
	
	i64 n = a.size(), sum = 0;
	
	for(int i = 0; i < n; i++)
		sum += (2 * i - n + 1) * a[i];
	
	return sum;
}

int main()
{
	int n, m;
	std::cin >> n >> m;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			int col; 
			std::cin >> col;
			
			x[col].push_back(i);
			y[col].push_back(j);			
		}
	}
	
	i64 sum = 0LL;
	
	for(int i = 1; i < color_limit; i++)
		sum += distance_sum(x[i]) + distance_sum(y[i]);
	
	std::cout << sum << "\n";
		
	return 0;
}