#include <bits/stdc++.h>

void solve()
{
	int x, y;
	std::cin >> x >> y;
	
	if (x == 0 and y == 0)
	{
		std::cout << "0\n";
		return;
	}
	
	int z = 0;
	
	while (z * z < x * x + y * y)
		z++;
	
	if (z * z == x * x + y * y)
		std::cout <<< "1\n";
	else
		std::cout << "2\n";
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;
	
	while(t--)
		solve();
	
	return 0;
}