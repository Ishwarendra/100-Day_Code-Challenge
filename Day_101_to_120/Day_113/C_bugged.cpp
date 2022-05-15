#include<bits/stdc++.h>

using i64 = long long;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;
	std::cin >> n;
	
	int ans = 0;
	std::vector<int> a(n);
	
	for (int i = 0; i < n; ++i)
	{
		std::cin >> a[i];
		ans += a[i];
	}
	
	std::sort(a.begin(), a.end());
	
	int can_del = -1;
	
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 10)
		{
			can_del = a[i];
			break;
		}
	}
	
	if (ans % 10)
		std::cout << ans << "\n";
	else
		std::cout << (can_del != -1 ? ans - can_del : 0) << "\n";
	
	
	return 0;
}