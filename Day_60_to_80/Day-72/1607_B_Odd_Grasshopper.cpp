#include<bits/stdc++.h>

using i64 = long long;

void solve()
{
	i64 x, n;
	std::cin >> x >> n;
	
	if (n == 0)
		std::cout << x << "\n";
	else if (n == 1)
		std::cout << x + (x % 2 ? 1 : -1) << "\n";
	else
	{
		i64 time = 2;
		
		int sign = (x % 2 ? 1 : -1);
		
		x += sign; 
		n--;
		
		time += (n / 4) * 4;
		
		x += sign * 4LL * (n / 4);
		
		
		for(int i = 0; i < n % 4; i++)
		{
			if (x % 2)
				x += time;
			else
				x -= time;
			
			time++;
		}
		
		std::cout << x << "\n";
	}
}

int main()
{
	int t;
	std::cin >> t;
	
	while(t--)
		solve();
	
	return 0;
}