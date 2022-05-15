#include<bits/stdc++.h>

void solve()
{
	int n; 
	std::cin >> n;
	
	std::vector<int> a(n);
	
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
	
	int start_land = n - 1, end_land = 0;
	
	for(int i = 0; i < n; i++)
	{
		if (a[i] == 0)
		{
			start_land = i - 1;
			break;
		}
	}
	
	for(int i = n - 1; i >= 0; i--)
	{
		if (a[i] == 0)
		{
			end_land = i;
			break;
		}
	}
	
	std::cout << std::max(0, end_land - start_land + 1) << "\n";
}

int main()
{
	int t; 
	std::cin >> t;
	
	while(t--)
		solve();
	
	return 0;
}