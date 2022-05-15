#include<bits/stdc++.h>

int sqrt(int x)
{
	while (x > 9)
	{
		int tmp = 0;
		
		while (x != 0)
		{
			tmp += x % 10;
			x /= 10;
		}
		
		x = tmp;
	}
	
	return x;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int a; 
	std::cin >> a;
	
	std::cout << sqrt(a) << "\n";
	
	return 0;
}